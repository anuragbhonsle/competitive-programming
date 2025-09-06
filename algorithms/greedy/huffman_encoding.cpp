#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(NULL), right(NULL) {}
};

struct cmp {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code) {
    if (!root) return;
    if (root->ch != '$') cout << root->ch << ": " << code << "\n";
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void huffmanCoding(vector<char>& chars, vector<int>& freq) {
    priority_queue<Node*, vector<Node*>, cmp> pq;
    for (int i = 0; i < chars.size(); i++)
        pq.push(new Node(chars[i], freq[i]));

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* merged = new Node('$', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }
    printCodes(pq.top(), "");
}

int main() {
    vector<char> chars = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freq = {5, 9, 12, 13, 16, 45};
    huffmanCoding(chars, freq);
}
