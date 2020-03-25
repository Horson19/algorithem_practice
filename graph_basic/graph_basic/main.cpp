//
//  main.cpp
//  graph_basic
//
//  Created by HorsonChan on 2020/3/17.
//  Copyright © 2020 Horson. All rights reserved.
//

#include <iostream>
#include <queue>

#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::queue;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

class Graph {
    int v;
    ListNode **linkedList;
    void print(int *pre, int s, int t) {
        if (pre[t] != -1 && s != t) {
            print(pre, s, pre[t]);
        }
        cout << t;
        cout << " ";
    }
    
    bool found;
    
public:
    Graph(int capacity) {
        v = capacity;
        linkedList = new ListNode*[capacity];
        for (int i = 0; i<capacity; i++) {
            linkedList[i] = new ListNode(i);
        }
    }
    
    void addEdge(int s, int t) {
        ListNode *p = linkedList[s];
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new ListNode(t);
        
        ListNode *p2 = linkedList[t];
        while (p2->next != NULL) {
            p2 = p2->next;
        }
        p2->next = new ListNode(s);
    }
    
    //breadth first search
    void bfs(int s, int t) {
        if (s == t) return;
        bool *visited = new bool[v];
        queue<ListNode *> queue;
        int *prev = new int[v];
        for (int i = 0; i<v; i++) {
            prev[i] = -1;
        }
        queue.push(linkedList[s]);
        visited[s] = true;
        while (!queue.empty()) {
            ListNode *p = queue.front();
            queue.pop();
            p = p->next;
            while (p != NULL) {
                ListNode *st = p;
                if (!visited[p->val]) {
                    prev[p->val] = st->val;
                    visited[p->val] = true;
                    if (p->val == t) {
                        //print;
                        print(prev, s, t);
                        return;
                    }
                    queue.push(p);
                    p = p->next;
                }
            }
        }
    }
    
    //depth first search
    void dfs(int s, int t) {
        found = false;
        int *prev = new int[v];
        for (int i = 0; i < v; i++) {
            prev[i] = -1;
        }
        bool *visited = new bool[v];
        recurDfs(s, t, prev, visited);
        if (found) print(prev, s, t);
        else cout << "not found";
    }
    
    void recurDfs(int s, int t, int *prev, bool *visited) {
        if (found) return;
        ListNode *p = linkedList[s];
        ListNode *st = p;
        p = p->next;
        while (p != NULL) {
            if (!visited[p->val]) {
                prev[p->val] = st->val;
                visited[p->val] = true;
                if (s == t) {
                    found = true;
                    return;
                }
                recurDfs(p->val, t, prev, visited);
                p = p->next;
            }
        }
    }
};
