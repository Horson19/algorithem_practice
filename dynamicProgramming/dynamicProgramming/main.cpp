//
//  main.cpp
//  dynamicProgramming
//
//  Created by HorsonChan on 2020/4/4.
//  Copyright © 2020 Horson. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

//get heaviest
int knapsack(int *weight, int n, int w) {
    bool status[n][w+1];
    status[0][0] = true;
    if (weight[0] <= w) {
        status[0][weight[0]] = true;
    }
    for (int i = 1; i<n; i++) {
        for (int j = 0; i <= w; j++) {
            if (status[i-1][j]) status[i][j] = true; //not pack in
        }
        for (int j = 0; i <= w - weight[i]; j++) {
            if (status[i-1][j]) status[i][j+weight[i]] = true;
        }
    }
    //get result
    for (int i = w; i >= 0; i--) {
        if (status[n-1][i]) return i;//heaviest solution
    }
    return 0;
}

//get heaviest
//space complexity optimize
int knapsack2(int *weight, int n, int w) {
    bool status[w+1];
    status[0] = true;
    if (weight[0] <= w) {
        status[weight[0]] = true;
    }
    for (int i = 1; i<n; i++) {
        for (int j = w - weight[i]; i >= 0; j--) {//notice avoid repeated caculating,from the most to 0
            if (status[j]) status[j+weight[i]] = true;
        }
    }
    //get result
    for (int i = w; i >= 0; i--) {
        if (status[i]) return i;//heaviest solution
    }
    return 0;
}

//get most value
int knapsack3(int *weight, int *value, int n, int w) {
    int status[n][w+1];
    status[0][0] = 0;
    for (int i = 0; i<n; i++) {
        for (int j = 0; i<=w; i++) {
            status[i][j] = -1;
        }
    }
    if (weight[0] <= w) {
        status[0][weight[0]] = value[0];
    }
    for (int i = 1; i<n; i++) {
        for (int j = 0; j<=w; j++) {
            if (status[i-1][j] >= 0) status[i][j] = status[i-1][j];
        }
        for (int j = 0; j<=w-weight[i]; j++) {
            if (status[i-1][j] >= 0) {
                int v = status[i-1][j] + value[i];
                if (v > status[i][j + weight[i]]) {
                    status[i][j + weight[i]] = v;
                }
            }
        }
    }
    
    //found most value
    int max = -1;
    for (int i = w; i>=0; i++) {
        int v = status[n-1][i];
        if (v > max) max = v;
    }
    return max;
}

//get most value
//space complexity optimize
int knapsack4(int *weight, int *value, int n, int w) {
    int status[w+1];
    status[0] = 0;
    for (int i = 0; i<=w; i++) {
        status[i] = -1;
    }
    if (weight[0] <= w) {
        status[weight[0]] = value[0];
    }
    for (int i = 1; i<n; i++) {
        for (int j = w-weight[i]; j>=0; j--) {
            if (status[j] >= 0) {
                int v = status[j] + value[i];
                if (v > status[j + weight[i]]) {
                    status[j + weight[i]] = v;
                }
            }
        }
    }
    
    //found most value
    int max = -1;
    for (int i = w; i>=0; i++) {
        int v = status[i];
        if (v > max) max = v;
    }
    return max;
}

//double 11 advice
void double11Advice(int *items, int n, int w) {
    bool status[n][w+1];
    status[0][0] = true;
    if (items[0] < 3*w) {
        status[0][items[0]] = true;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 3*w; j++) {
            if (status[i-1][j]) status[i][j] = true;
        }
        for (int j = 0; j <= 3*w - items[i]; j++) {
            if (status[i-1][j]) status[i][j + items[i]] = true;
        }
    }
    
    int j;
    for (j = w; j <= 3*w; j++) {
        if (status[n-1][j]) break;
    }
    if (j>3*w) {
        cout << "no solution" << endl;
        return;
    }
    
    //find the way back
    for (int i = n - 1; i >= 1; --i) {
        if (j - items[i] >= 0 && status[i-1][j-items[i]]) {//have packed it in
            printf("%d ", i);
            j = j - items[i];
        }// else haven't
    }
    if (j > 0) cout << "0" <<endl;
}
