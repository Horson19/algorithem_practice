//
//  main.cpp
//  editDistDP
//
//  Created by HorsonChan on 2020/4/11.
//  Copyright © 2020 Horson. All rights reserved.
//

#include <iostream>

using namespace std;
int min(int x, int y, int z);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
//Levenshtein distance
//back tracking
char *a = "backtrack";
char *b = "backlwkmd";
int n = 9;
int m = 9;
int minDist = 9999;//max value
void lwstDistBT(int i, int j, int dist) {
    if (i == n || j == m) {
        if (i<n) dist += (n-i);
        if (j<n) dist += (m-j);
        if (dist < minDist) minDist = dist;
        return;
    }
    if (a[i] == b[j]) {
        lwstDistBT(i+1, j+1, dist);
    } else {
        lwstDistBT(i+1, j, dist + 1);
        lwstDistBT(i, j+1, dist + 1);
        lwstDistBT(i+1, j+1, dist + 1);
    }
}
//回溯这里的思想是，发现不相等，把增删操作增加的距离，记录到下个节点

//动态规划这里的思想是，发现不相等，把增删操作增加的距离记录在当前节点
int lwstDistDP() {
    int status[n][m];
    for (int i = 0; i<n; i++) {
        if (a[i] == b[0]) status[i][0] = i;
        else if (i != 0) status[i][0] = status[i-1][0] + 1;
        else status[i][0] = 1;
    }
    for (int j = 0; j<m; j++) {
        if (a[0] == b[j]) status[0][j] = j;
        else if (j != 0) status[0][j] = status[0][j-1] + 1;
        else status[0][j] = 1;
    }
    for (int i = 1; i<n; i++) {
        for (int j = 1; j<m; j++) {
            if (a[i] == b[j]) status[i][j] = min(status[i-1][j] + 1, status[i][j-1] + 1, status[i-1][j-1]);
            //这里就可以用上面的注释解释，为什么是判断a[i] == a[j]而不是a[i-1] == [j-1]，因为记录状态的节点变了，这里是记录在当前节点，而上面回溯最后判断i == n 或者j == m才会停，所以会多一个节点，最后状态在多出的那个节点里
            else status[i][j] = min(status[i-1][j] + 1, status[i][j-1] + 1, status[i-1][j-1] + 1);
        }
    }
    return status[n-1][m-1];
}

int min(int x, int y, int z) {
    int res = 99999;//max value
    if (x < res) res = x;
    if (y < res) res = y;
    if (z < res) res = z;
    return res;
}
