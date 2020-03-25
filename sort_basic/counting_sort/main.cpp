//
//  main.cpp
//  counting_sort
//
//  Created by HorsonChan on 2020/2/24.
//  Copyright © 2020 Horson. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;
void counting_sort(int *scoreArr, int count);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int scoreArr[] = {0,5,4,8,8,2,3,9,6,6,7,1};
    counting_sort(scoreArr, 12);
    cout << scoreArr <<endl;
    return 0;
}

void counting_sort(int *scoreArr, int count) {
    int c = 10;
    int tempArr[count];
    //counting-arr: range 0-9
    int counting_Arr[c];
    for (int i = 0; i < c; i++) {
        counting_Arr[i] = 0;
    }
    
    //fill out couting arr
    for (int i = 0; i < count; i++) {
        counting_Arr[scoreArr[i]]++;
    }
    
    //added last element
    for (int i = 1; i < c; i++) {
        counting_Arr[i] += counting_Arr[i-1];
    }
    
    //sort in temp arr
    for (int i = count - 1; i >= 0; i--) {
        int index = counting_Arr[scoreArr[i]] - 1;
        tempArr[index] = scoreArr[i];
        counting_Arr[scoreArr[i]]--;
    }
    
    //copy item to scoreArr
    for (int i = 0; i < count; i++) {
        scoreArr[i] = tempArr[i];
    }
}
