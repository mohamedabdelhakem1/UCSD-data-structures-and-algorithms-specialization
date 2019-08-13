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
void in_order_walk( Node n,vector<Node>& tree,vector<int> &result) {
    if(n.left != -1 && correct)
        in_order_walk(tree[n.left],tree,result);
    if(result.size() > 0 && result[result.size() - 1] >  n.key) {
        correct = false;
        return;
    }else if (correct){
         result.push_back(n.key);
    }
    if(n.right != -1 && correct)
        in_order_walk(tree[n.right],tree,result);
}

bool IsBinarySearchTree(vector<Node>& tree) {
    vector<int> result;
    if(tree.size() == 0)
        return true;
    in_order_walk( tree[0],tree,result);
    return correct;
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
