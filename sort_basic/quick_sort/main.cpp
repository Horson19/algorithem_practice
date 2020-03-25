//
//  main.cpp
//  quick_sort
//
//  Created by HorsonChan on 2020/2/23.
//  Copyright © 2020 Horson. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;

void quick_sort(int *arr, int count);
void quick_sort_c(int *arr, int p, int r);
int seperate(int *arr, int p, int r);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int arr[] = {0,22,124,84,23,23,9,18,42,123};
    quick_sort(arr, 10);
    cout << arr <<endl;
    return 0;
}

void quick_sort(int *arr, int count) {
    quick_sort_c(arr, 0, count - 1);
}

void quick_sort_c(int *arr, int p, int r) {
    if (r <= p) {
        return;
    }
    int q = seperate(arr, p, r);
    quick_sort_c(arr, p, q-1);
    quick_sort_c(arr, q+1, r);
}

int seperate(int *arr, int p, int r) {
    int j = p;
    int i = p;
    int value = arr[r];
    for (; j <= r - 1; j++) {
        if (arr[j] < value) {
            //todo: if i == j, if still need to exchange?
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    int temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;
    return i;
}
