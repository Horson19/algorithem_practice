//
//  main.cpp
//  recursion
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
int n = 4;
int mem[4][4];

int minDist(int i, int j, int **matrix) {
    if (i == 0 && j == 0) {
        return matrix[0][0];
    }
    if (mem[i][j] > 0) return mem[i][j];
    
    int top = 99999;//max value instead
    if (i-1 >= 0) {
        top = minDist(i-1, j, matrix);
    }
    int left = 99999;//max value instead
    if (j-1 >= 0) {
        left = minDist(i, j-1, matrix);
    }
    int shortCut = min(left, top);
    int dist = matrix[i][j] + shortCut;
    
    mem[i][j] = dist;
    return dist;
}
