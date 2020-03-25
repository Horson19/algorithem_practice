//
//  main.cpp
//  heap
//
//  Created by HorsonChan on 2020/3/11.
//  Copyright © 2020 Horson. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;
using std::vector;

void heapify(int *a, int n, int i);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

//max heap
class Heap {
    int *a;
    int n;//max capacity
    int count;//current saved count
    Heap(int capacity);
    void insert(int data);
    void deleteIdx(int idx);
};

Heap::Heap(int capacity) {
    a = new int[capacity + 1];
    n = capacity;
    count = 0;
}

void Heap::insert(int data) {
    count++;
    a[count] = data;
    int i = count;
    while (i/2 > 0 && a[i/2] < a[i]) {
        int temp = a[i/2];
        a[i/2] = a[i];
        a[i] = temp;
        i = i/2;
    }
}

void Heap::deleteIdx(int idx) {
    if (idx < 1 || count <= 0) {
        return;
    }
    a[idx] = a[count];
    count--;
    heapify(a, count, idx);
}

//from top to bottom heapify
void heapify(int *a, int count, int i) {
    while (true) {
        int resPos = i;
        if (i*2 <= count && a[i*2] > a[i]) resPos = i * 2;
        if (i*2+1 <= count && a[i*2+1] > a[resPos]) resPos = i * 2 + 1;
        if (i == resPos) break;
        int temp = a[i];
        a[resPos] = a[i];
        a[i] = temp;
        i = resPos;
    }
}

//suppose the target a is sort from index 1 to count
void buildHeap(int *a, int count) {
    for (int i = count/2; i >= 1; i--) {
        heapify(a, count, i);
    }
}

//suppose the target a is sort from index 1 to count
void sortHeap(int *a, int count) {
    //O(n)
    buildHeap(a, count);
    int n = count;
    //O(nlogn)
    while (n > 1) {
        int temp = a[1];
        a[1] = a[n];
        a[n] = temp;
        n--;
        heapify(a, n, 1);
    }
}
