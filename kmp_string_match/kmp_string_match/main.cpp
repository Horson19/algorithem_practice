//
//  main.cpp
//  kmp_string_match
//
//  Created by HorsonChan on 2020/3/25.
//  Copyright © 2020 Horson. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;
void generateNexts(char *b, int m, int *next);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

void generateNexts(char *b, int m, int *next) {
    next[0] = -1;
    int k = -1;
    for (int i = 1; i < m; i++) {
        while (k != -1 && b[k+1] != b[i]) {
            k = next[k];
        }
        if (b[k+1] == b[i]) {
            k++;
        }
        next[i] = k;
    }
}

int kmp(char *a, int n, char *b, int m) {
    int *nexts = new int[m];
    generateNexts(b, m, nexts);
    int j = 0;
    for (int i = 0; i < m; i++) {
        while (j > 0 && a[i] != b[j]) {
            j = nexts[j - 1] + 1;
        }
        if (a[i] == b[j]) {
            j++;
        }
        if (j == m) {
            return i - m + 1;
        }
    }
    return -1;
}
