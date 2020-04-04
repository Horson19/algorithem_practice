//
//  main.cpp
//  backTracking algorithm
//
//  Created by HorsonChan on 2020/4/4.
//  Copyright © 2020 Horson. All rights reserved.
//

#include <iostream>
using namespace std;

int maxW = 0;
int maxV = 0;
int weight[5] = {2,2,4,6,3};
int value[5] = {3,4,8,9,6};
int n = 5;
int w = 9;
bool mem[5][10];

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

//get heaviest
void f(int i, int cw) {
    if (cw == w || i == n) {
        if (cw > maxW) {
            maxW = cw;
        }
        return;
    }
    if (mem[i][cw]) return;
    mem[i][cw] = true;
    
    f(i+1, cw);//do not pack into
    if (cw + weight[i+1] <= w) {
        f(i+1, cw + weight[i+1]);//pack into
    }
}

//get most value
void f2(int i, int cw, int cv) {
    if (cw == w || i == n) {
        if (cv > maxV) maxV = cv;
        return;
    }
    f2(i+1, cw, cv);
    if (cw + weight[i+1] <= w) {
        f2(i+1, cw+weight[i+1], cv+value[i+1]);
    }
}
