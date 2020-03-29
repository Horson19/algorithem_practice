//
//  main.cpp
//  AC
//
//  Created by HorsonChan on 2020/3/29.
//  Copyright © 2020 Horson. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}

class AcNode {
public:
    char data;
    AcNode **childen;
    AcNode *fail;
    int length = -1;
    bool isEndingChar;
    AcNode(char data) {
        this->data = data;
        this->childen = new AcNode*[3];
    }
};

class AC {
    AcNode *trieRoot = new AcNode('/');
public:
    void insert(char *text) {
        AcNode *p = trieRoot;
        for (int i = 0; i<strlen(text); i++) {
            int idx = (int)text[i] - (int)'a';
            if (p->childen[idx] == NULL) {
                p->childen[idx] = new AcNode(text[i]);
            }
            p = p->childen[idx];
        }
        p->isEndingChar = true;
    }
    
    bool find(char *text) {
        AcNode *p = trieRoot;
        for (int i = 0; i<strlen(text); i++) {
            int idx = (int)text[i] - (int)'a';
            if (p->childen[idx] == NULL) {
                return false;
            }
            p = p->childen[idx];
        }
        if (p->isEndingChar) return true;
        else return false;
    }
    
    void buildFailurePointers() {
        queue<AcNode*> queue;
        trieRoot->fail = NULL;
        queue.push(trieRoot);
        while (!queue.empty()) {
            AcNode *p = queue.front();
            queue.pop();
            for (int i = 0; i<26; i++) {
                AcNode *pc = p->childen[i];
                if (p == NULL) continue;
                if (p == trieRoot) {
                    pc->fail = trieRoot;
                } else {
                    AcNode *q = p->fail;
                    while (q != NULL) {
                        int qIdx = (int)pc->data - (int)'a';
                        AcNode *qc = q->childen[qIdx];
                        if (qc != NULL) {
                            pc->fail = qc;
                            break;
                        }
                        q = q->fail;
                    }
                    if (q == NULL) {
                        pc->fail = trieRoot;
                    }
                }
                queue.push(pc);
            }
        }
    }
    
    //not sure if right
    void match(char *text) {
        int n = (int)strlen(text);
        AcNode * p = trieRoot;
        for (int i = 0; i<n; i++) {
            int idx = (int)text[i] - (int)'a';
            while (p->fail != NULL) {
                if (p->childen[idx] != NULL) {
                    p = p->childen[idx];
                    while (p->fail != NULL) {
                        int idx = i - p->length + 1;
                        if (p->isEndingChar) {
                            printf("idx: %d, length: %d\n", idx, p->length);
                        }
                        p = p->fail;
                    }
                    p = trieRoot;
                } else {
                    p = p->fail;
                }
            }
        }
    }
    
    void match2(char *text) {
        int n = (int)strlen(text);
        AcNode * p = trieRoot;
        for (int i = 0; i<n; i++) {
            int idx = (int)text[i] - (int)'a';
            while (p->childen[idx] != NULL && p != trieRoot) {
                p = p->fail;
            }
            if (p->childen[idx] == NULL) {
                p = trieRoot;
            } else {
                p = p->childen[idx];
            }
            AcNode *temp = p;
            while (temp != trieRoot) {
                int idx = i - temp->length + 1;
                if (temp->isEndingChar) {
                    printf("idx: %d, length: %d\n", idx, p->length);
                }
                temp = p->fail;
            }
        }
    }
};


