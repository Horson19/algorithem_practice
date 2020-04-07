//
//  main.cpp
//  backtracking
//
//  Created by HorsonChan on 2020/4/8.
//  Copyright © 2020 Horson. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    //invoke
    // minDistBT(0, 0, 0, w, n)  need to construct w
    return 0;
}
int minimum = -1;
void minDistBT(int i, int j, int dist, int **w, int n) {
    if (i == n-1 && j == n-1) {
        int ds = dist + w[i][j];
        if (ds < minimum) {
            minimum = ds;
        }
        return;
    }
    if (i<n) {
        minDistBT(i+1, j, dist+w[i][j], w, n);
    }
    if (j<n) {
        minDistBT(i, j+1, dist+w[i][j], w, n);
    }
}
