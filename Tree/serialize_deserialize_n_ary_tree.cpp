#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    int degree;
    vector<Node*> children;

    Node(int val_, int degree_): val(val_), degree(degree_) {
        children.resize(degree, NULL);
    }
};

string serialize(Node* root) {
    if(!root) return "#";
    string s = to_string(root->val) + "," + to_string(root->children.size()) + ",";
    for(int i=0; i<root->children.size(); i++) {
        s += serialize(root->children[i]) + ",";
    }
    return s;
}

Node* build(queue<string> &q) {
    if(q.empty()) return NULL;
    string front = q.front();
    q.pop();
    if(front == "#") return NULL;
    int size = stoi(q.front());
    q.pop();
    Node* root = new Node(stoi(front), size);
    for(int i=0; i<size; i++) {
        root->children[i] = build(q);
    }
    return root;
}

Node* deserialize(string s) {
    queue<string> q;
    string temp;
    for(char ch: s) {
        if(ch == ',') {
            q.push(temp);
            temp = "";
        }
        else {
            temp += ch;
        }
    }
    q.push(temp);
    return build(q);
}


int main() {
    return 0;
}