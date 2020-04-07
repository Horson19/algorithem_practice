//
//  main.cpp
//  dp2
//
//  Created by HorsonChan on 2020/4/8.
//  Copyright © 2020 Horson. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

int minDistDP(int **matrix, int n) {
    int status[n][n];
    status[0][0] = matrix[0][0];
    for (int i = 1; i<n; i++) {
        status[i][0] = status[i-1][0] + matrix[i][0];
    }
    for (int j = 1; j<n; j++) {
        status[0][j] = status[0][j-1] + matrix[0][j];
    }
    for (int i = 1; i<n; i++) {
        for (int j = 1; j<n; j++) {
            int left = status[i][j-1];
            int top = status[i-1][j];
            status[i][j] = min(left, top) + matrix[i][j];
        }
    }
    return status[n-1][n-1];
}
