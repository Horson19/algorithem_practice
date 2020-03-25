//
//  main.cpp
//  search_last_max
//
//  Created by HorsonChan on 2020/2/28.
//  Copyright © 2020 Horson. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;
int search_last_min(int *arr, int count, int min);
int search_last_value(int *arr, int count, int value);
int search_first_max(int *arr, int count, int max);
int search_first_value(int *arr, int count, int value);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int arr[20] = {0,8,19,79,79,
        79,79,106,106,106,
        187,187,187,187,290,
        501,501,501,621,622};
    int idx = search_last_min(arr, 20, 623);
    int idx2 = search_last_value(arr, 20, 106);
    int idx3 = search_first_max(arr, 20, 187);
    int idx4 = search_first_value(arr, 20, 501);
    cout << idx4 << endl;
    return 0;
}

int search_last_min(int *arr, int count, int min) {
    int start = 0;
    int end = count - 1;
    while (start <= end) {
        int mid = start + ((end - start) >> 1);
        if (arr[mid] <= min) {
            if (mid == count - 1 || arr[mid + 1] > min) {
                return mid;
            } else {
                start = mid + 1;
            }
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

int search_last_value(int *arr, int count, int value) {
    int start = 0;
    int end = count - 1;
    while (start <= end) {
        int mid = start + ((end - start) >> 1);
        if (arr[mid] > value) {
            end = mid - 1;
        } else if (arr[mid] < value) {
            start = mid + 1;
        } else {
            if (mid == count - 1 || arr[mid + 1] != value) {
                return mid;
            } else {
                start = mid + 1;
            }
        }
    }
    return -1;
}

int search_first_max(int *arr, int count, int max) {
    int start = 0;
    int end = count - 1;
    while (start <= end) {
        int mid = start + ((end - start) >> 1);
        if (arr[mid] >= max) {
            if (mid == 0 || arr[mid - 1] < max) {
                return mid;
            } else {
                end = mid - 1;
            }
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

//very clean binary search
int search_first_value(int *arr, int count, int value) {
    int start = 0;
    int end = count - 1;
    while (start <= end) {
        int mid = start + ((end - start) >> 1);
        //result start is the index of first < value
        if (arr[mid] >= value) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    if (start < count && arr[start] == value) {
        return start;
    } else {
        return -1;
    }
}
