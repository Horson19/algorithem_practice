//
//  main.cpp
//  binary_search
//
//  Created by HorsonChan on 2020/2/26.
//  Copyright © 2020 Horson. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;

int binary_search(int *arr, int count, int value);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int arr[10] = {0,8,19,79,106,187,290,501,621,622};
    int idx = binary_search(arr, 10, 290);
    cout << idx;
    return 0;
}

int binary_search(int *arr, int count, int value) {
    int begin = 0;
    int end = count - 1;
    while (begin <= end) {
        int mid = begin + (end - begin)/2;
        int result = arr[mid];
        if (result == value) {
            return mid;
        } else if (result < value) {
            begin = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    return -1;
}
