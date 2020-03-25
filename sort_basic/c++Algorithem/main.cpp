//
//  main.cpp
//  c++Algorithem
//
//  Created by HorsonChan on 2020/2/23.
//  Copyright © 2020 Horson. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;

void merge_sort(int *arr, int count);
void merge_sort_c(int *arr, int p, int r);
void merge(int *arr, int p, int r, int q);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int arr[] = {0,22,124,84,23,23,9,18,42,123};
    merge_sort(arr, 10);
    cout << arr <<endl;
    return 0;
}

void merge_sort(int *arr, int count) {
    merge_sort_c(arr, 0, count - 1);
}

void merge_sort_c(int *arr, int p, int r) {
    if (r <= p) {
        return;
    }
    int q = (r+p)/2;
    merge_sort_c(arr, p, q);
    merge_sort_c(arr, q + 1, r);
    merge(arr, p, r, q);
}

void merge(int *arr, int p, int r, int q) {
    int i = p;
    int j = q + 1;
    int k = 0;
    int temp[r - q + 1];
    while (i <= q && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    int start = j;
    int end = r;
    if (i <= q) {
        start = i;
        end = q;
    }
    while (start <= end) {
        temp[k++] = arr[start++];
    }
    for (int idx = 0; idx <= (r - p); idx++) {
        arr[p + idx] = temp[idx];
    }
}
