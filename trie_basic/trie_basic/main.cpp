//
//  main.cpp
//  trie_basic
//
//  Created by HorsonChan on 2020/3/26.
//  Copyright © 2020 Horson. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

class TrieNode {
public:
    char data;
    bool isEndingChar;
    TrieNode **childen;
    TrieNode(char data) {
        this->data = data;
        this->childen = new TrieNode*[3];
    }
};

class Trie {
    TrieNode *trieRoot = new TrieNode('/');
public:
    void insert(char *text) {
        TrieNode *p = trieRoot;
        for (int i = 0; i<strlen(text); i++) {
            int idx = (int)text[i] - (int)'a';
            if (p->childen[idx] == NULL) {
                p->childen[idx] = new TrieNode(text[i]);
            }
            p = p->childen[idx];
        }
        p->isEndingChar = true;
    }
    
    bool find(char *text) {
        TrieNode *p = trieRoot;
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
};
