#include <bits/stdc++.h>
using namespace std;
bool correct = true;
struct Node {
    int key;
    int left;
    int right;

    Node() : key(0), left(-1), right(-1) {}
    Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};
void in_order_walk(unordered_set<int> &inStack,Node n,vector<Node>& tree,vector<int> &result) {
    if(n.left != -1 ) {
        if(inStack.find(tree[n.left].key) != inStack.end()){
            correct = false;
        }else{
             inStack.insert(tree[n.left].key);
        }

        in_order_walk(inStack,tree[n.left],tree,result);
    }
    inStack.erase(n.key);
    result.push_back(n.key);
    if(n.right != -1 ) {
        if(inStack.find(tree[n.right].key) != inStack.end()){
            correct = false;
        }else{
            inStack.insert(tree[n.right].key);
        }
        in_order_walk(inStack,tree[n.right],tree,result);
    }
}

bool IsBinarySearchTree(vector<Node>& tree) {
    if(tree.size() == 0)
        return true;
    vector<int> result;
    unordered_set<int> inStack;
    inStack.insert(tree[0].key);
    in_order_walk(inStack, tree[0],tree,result);
    int n = (int)result.size();
    if(!correct) {
        return false;
    }
    for(int i = 0 ; i < n-1 ; i++) {
        if(result[i] > result[i+1] ) {
            return false;
        }
    }
    return true;
}

int main() {
    int nodes;
    cin >> nodes;
    vector<Node> tree;
    for (int i = 0; i < nodes; ++i) {
        int key, left, right;
        cin >> key >> left >> right;
        tree.push_back(Node(key, left, right));
    }
    if (IsBinarySearchTree(tree)) {
        cout << "CORRECT" << endl;
    } else {
        cout << "INCORRECT" << endl;
    }
    return 0;
}
