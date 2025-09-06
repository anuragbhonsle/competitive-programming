#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* nxt[26]; // assuming lowercase a-z
    bool isEnd;

    TrieNode() {
        for(int i=0;i<26;i++) nxt[i] = nullptr;
        isEnd = false;
    }
};

struct Trie {
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string &word) {
        TrieNode* node = root;
        for(char c : word){
            int idx = c - 'a';
            if(!node->nxt[idx]) node->nxt[idx] = new TrieNode();
            node = node->nxt[idx];
        }
        node->isEnd = true;
    }

    bool search(const string &word) {
        TrieNode* node = root;
        for(char c : word){
            int idx = c - 'a';
            if(!node->nxt[idx]) return false;
            node = node->nxt[idx];
        }
        return node->isEnd;
    }

    bool startsWith(const string &prefix) {
        TrieNode* node = root;
        for(char c : prefix){
            int idx = c - 'a';
            if(!node->nxt[idx]) return false;
            node = node->nxt[idx];
        }
        return true;
    }
};

int main(){
    Trie trie;
    int q; cin >> q;
    while(q--){
        int type; cin >> type;
        if(type==1){ // insert
            string w; cin >> w;
            trie.insert(w);
        } else if(type==2){ // search
            string w; cin >> w;
            cout << (trie.search(w) ? "YES\n" : "NO\n");
        } else { // startsWith
            string p; cin >> p;
            cout << (trie.startsWith(p) ? "YES\n" : "NO\n");
        }
    }
}
