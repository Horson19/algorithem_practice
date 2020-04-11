//
//  main.cpp
//  longest common substring length
//
//  Created by HorsonChan on 2020/4/11.
//  Copyright © 2020 Horson. All rights reserved.
//

#include <iostream>

using namespace std;

char *a = "backtrack";
char *b = "backlwkmd";
int n = 9;
int m = 9;
int maxCount = 0;
int lcslDP();
void lcslBT(int i, int j, int cc);
int max(int x, int y, int z);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int a = lcslDP();
    cout<<a;
    return 0;
}


void lcslBT(int i, int j, int cc) {
    if (i == n && j == n) {
        if (cc > maxCount) maxCount = cc;
        return;
    }
    if (a[i] == b[j]) {
        lcslBT(i+1, j+1, cc+1);
    } else {
        if (i != n) lcslBT(i+1, j, cc);
        if (j != m) lcslBT(i, j+1, cc);
        if (i != n && j != m) lcslBT(i+1, j+1, cc);
    }
}

int lcslDP() {
    int status[n][m];
    for (int i = 0; i<n; i++) {
        if (a[i] == b[0]) status[i][0] = 1;
        else if (i != 0) status[i][0] = status[i-1][0];
        else status[i][0] = 0;
    }
    for (int j = 0; j<m; j++) {
        if (a[0] == b[j]) status[0][j] = 1;
        else if (j != 0) status[0][j] = status[0][j-1];
        else status[0][j] = 0;
    }
    for (int i = 1; i<n; i++) {
        for (int j = 1; j<m; j++) {
            if (a[i] == b[j]) status[i][j] = max(status[i-1][j], status[i][j-1], status[i-1][j-1]+1);
            else status[i][j] = max(status[i-1][j], status[i][j-1], status[i-1][j-1]);
        }
    }
    return status[n-1][m-1];
}

int max(int x, int y, int z) {
    int res = 0;//min value
    if (x > res) res = x;
    if (y > res) res = y;
    if (z > res) res = z;
    return res;
}
