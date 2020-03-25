//
//  main.cpp
//  bm_string_match_algorithem
//
//  Created by HorsonChan on 2020/3/22.
//  Copyright © 2020 Horson. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;
using std::max;

int hashSize = 256;
int bm(char *a, int n, char *b, int m);

int main(int argc, const char * argv[]) {
    return 0;
}


void generateHashBC(char* b, int m, int* bc) {
    for (int i = 0; i<hashSize; i++) {
        bc[i] = -1;
    }
    for (int i = 0; i<m; i++) {
        bc[(int)b[i]] = i;
    }
}

void generateGS(char *b, int m, int *suffix, bool *prefix) {
    for (int i = 0; i<m; i++) {
        suffix[i] = -1;
        prefix[i] = false;
    }
    for (int i = 0; i<m-1; i++) {
        int j = i;
        int k = 0;
        while (j>=0 && b[j] == b[m-1-k]) {
            j--;
            k++;
            suffix[k] = j+1;
        }
        if (j == -1) prefix[k] = true;
    }
}

int moveByGS(int j, int m, int *suffix, bool *prefix) {
    int k = m - 1 - j;
    if (suffix[k] != -1) return j - suffix[k] + 1;
    for (int r = j+2; r <= m-1; r++) {
        if (prefix[m-r]) {
            return r;
        }
    }
    return m;
}

int bm(char *a, int n, char *b, int m) {
    int *bc = new int[hashSize];
    int *suffix = new int[m];
    bool *prefix = new bool[m];
    generateHashBC(b, m, bc);
    generateGS(b, m, suffix, prefix);
    int i = 0;
    while (i <= n-m) {
        int j;
        for (j = m - 1; j >= 0; j--) {
            if (b[j] != a[i+j]) break;
        }
        if (j == -1) return i;
        int x = i + (j - bc[(int)a[i+j]]);//bad character rule
        int y = 0;
        if (j < m-1) {
            y = moveByGS(j, m, suffix, prefix);
        }
        i = i + max(x,y);
    }
    return -1;
}

