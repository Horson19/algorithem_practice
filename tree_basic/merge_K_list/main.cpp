//
//  main.cpp
//  merge_K_list
//
//  Created by HorsonChan on 2020/3/13.
//  Copyright © 2020 Horson. All rights reserved.
//

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//min heap
class Heap {
public:
    ListNode **a;
    int maxCapacity;//max capacity
    int count;//current saved count
    Heap(int capacity) {
        a = new ListNode*[capacity+1];
        maxCapacity = capacity;
        count = 0;
    }
    
    void insert(ListNode* node) {
        if (maxCapacity <= 0 || count == maxCapacity) return;
        if (node == NULL) return;
        count++;
        a[count] = node;
        heapify_up(count);
    }
    
    ListNode* deleteTop() {
        ListNode *node = a[1];
        a[1] = a[count];
        count--;
        heapify_down(1);
        return node;
    }
private:
    void heapify_up(int idx) {
        int i = idx;
        while (i/2 > 0 && a[i/2]->val > a[i]->val) {
            ListNode *temp = a[i];
            a[i] = a[i/2];
            a[i/2] = temp;
            i = i/2;
        }
    }
    
    void heapify_down(int idx) {
        int i = idx;
        while (true) {
            int maxPos = i;
            if (i*2 <= count && a[i*2]->val < a[i]->val) maxPos = i*2;
            if ((i*2+1) <= count && a[i*2+1]->val < a[maxPos]->val) maxPos = i*2+1;
            if (maxPos == i) break;
            ListNode *temp = a[i];
            a[i] = a[maxPos];
            a[maxPos] = temp;
            i = maxPos;
        }
    }
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
    Heap heap = Heap((int)(lists.size()));
    ListNode *res = new ListNode(0);
    ListNode *p = res;
    for (int i = 0; i < lists.size(); i++) {
        heap.insert(lists[i]);
    }
    while (heap.count > 0) {
        cout << "个数";
        cout << heap.count <<endl;
        cout << "内容" <<endl;
        for (int i = 1; i <= heap.count; i++) {
            cout << heap.a[i]->val <<endl;
        }
        cout << "——————————————————" <<endl;
        ListNode *node = heap.deleteTop();
        p->next = node;
        p = p->next;
        cout << "个数";
        cout << heap.count <<endl;
        cout << "内容" <<endl;
        for (int i = 1; i <= heap.count; i++) {
            cout << heap.a[i]->val <<endl;
        }
        cout << "——————————————————" <<endl;
        
        if (node->next != NULL) {
            heap.insert(node->next);
        }
    }
    return res->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<ListNode *> lists;
    ListNode *node1 = new ListNode(-10);
    ListNode *node2 = new ListNode(-9);
    ListNode *node3 = new ListNode(-9);
    ListNode *node4 = new ListNode(-3);
    ListNode *node5 = new ListNode(-1);
    ListNode *node6 = new ListNode(-5);
    ListNode *node7 = new ListNode(4);
    ListNode *node8 = new ListNode(-8);
    ListNode *node9 = new ListNode(-9);
    ListNode *node10 = new ListNode(-6);
    ListNode *node11 = new ListNode(-5);
    ListNode *node12 = new ListNode(-3);
    ListNode *node13 = new ListNode(-3);
    ListNode *node14 = new ListNode(-2);
    vector<ListNode *>list1 = {node1,node2,node3,node4,node5};
    vector<ListNode *>list2 = {node6};
    vector<ListNode *>list3 = {node7};
    vector<ListNode *>list4 = {node8};
    vector<ListNode *>list5 = {NULL};
    vector<ListNode *>list6 = {node9,node10,node11};
    vector<ListNode *>list7 = {node12,node13,node14};
    vector<vector<ListNode *>> arr = {list1,list2,list3,list4,list5,list6,list7};
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size() - 1; j++) {
            arr[i][j]->next = arr[i][j+1];
        }
    }
    vector<ListNode *> target;
    for (int i = 0; i < arr.size(); i++) {
        target.push_back(arr[i][0]);
    }
    mergeKLists(target);
    return 0;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        Heap heap = Heap((int)(lists.size()));
        ListNode *res = new ListNode(0);
        ListNode *p = res;
        for (int i = 0; i < lists.size(); i++) {
            heap.insert(lists[i]);
        }
        while (heap.count > 0) {
            ListNode *node = heap.deleteTop();
            p->next = node;
            p = p->next;
            if (node->next != NULL) {
                heap.insert(node->next);
            }
        }
        return res->next;
    }
};
