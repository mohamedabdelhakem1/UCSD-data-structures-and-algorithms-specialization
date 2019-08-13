#include <bits/stdc++.h>
using namespace std;
const int LEAF_LEN = 1;
string s;
// Vertex of a splay tree
struct Vertex {
    int lCount;
    // Sum of all the keys in the subtree - remember to update
    // it after each operation that changes the tree.
    Vertex* left;
    Vertex* right;
    Vertex* parent;
    string str;
    Vertex(int lcount, string str, Vertex* left, Vertex* right, Vertex* parent)
        : lCount(lCount), str(str), left(left), right(right), parent(parent) {}
    Vertex(){}
};
int count_leaves(Vertex* v) {
    queue<Vertex* > q;
    q.push(v->left);
    int countt;
    while(!q.empty()) {
        Vertex* top =  q.front();
        q.pop();
        if(top->left == NULL && top->right == NULL) {
            countt++;
        } else {
            if(top->left != NULL) {
                q.push(top->left);
            }
            if(top->right != NULL) {
                 q.push(top->right);
            }
        }
    }
    return countt;
}
void update(Vertex* v) {
    if (v == NULL)
        return;
    v->lCount = count_leaves(v);
    if (v->left != NULL) {
        v->left->parent = v;
    }
    if (v->right != NULL) {
        v->right->parent = v;
    }
}

void small_rotation(Vertex* v) {
    Vertex* parent = v->parent;
    if (parent == NULL) {
        return;
    }
    Vertex* grandparent = v->parent->parent;
    if (parent->left == v) {
        Vertex* m = v->right;
        v->right = parent;
        parent->left = m;
    } else {
        Vertex* m = v->left;
        v->left = parent;
        parent->right = m;
    }
    update(parent);
    update(v);
    v->parent = grandparent;
    if (grandparent != NULL) {
        if (grandparent->left == parent) {
            grandparent->left = v;
        } else {
            grandparent->right = v;
        }
    }
}

void big_rotation(Vertex* v) {
    if (v->parent->left == v && v->parent->parent->left == v->parent) {
        // Zig-zig
        small_rotation(v->parent);
        small_rotation(v);
    } else if (v->parent->right == v && v->parent->parent->right == v->parent) {
        // Zig-zig
        small_rotation(v->parent);
        small_rotation(v);
    } else {
        // Zig-zag
        small_rotation(v);
        small_rotation(v);
    }
}

// Makes splay of the given vertex and makes
// it the new root.
void splay(Vertex*& root, Vertex* v) {
    if (v == NULL)
        return;
    while (v->parent != NULL) {
        if (v->parent->parent == NULL) {
            small_rotation(v);
            break;
        }
        big_rotation(v);
    }
    root = v;
}

// Searches for the given key in the tree with the given root
// and calls splay for the deepest visited node after that.
// If found, returns a pointer to the node with the given key.
// Otherwise, returns a pointer to the node with the smallest
// bigger key (next value in the order).
// If the key is bigger than all keys in the tree,
// returns NULL.
Vertex* find(Vertex*& root, int key) {

}

void split(Vertex* root, int key, Vertex*& left, Vertex*& right) {
    right = find(root, key);
    splay(root, right);
    if (right == NULL) {
        left = root;
        return;
    }
    left = right->left;
    right->left = NULL;
    if (left != NULL) {
        left->parent = NULL;
    }
    update(left);
    update(right);
}

Vertex* merge(Vertex* left, Vertex* right) {
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;
    Vertex* min_right = right;
    while (min_right->left != NULL) {
        min_right = min_right->left;
    }
    splay(right, min_right);
    right->left = left;
    update(right);
    return right;
}



void build_rope(Vertex* node, Vertex* par, int l,int r) {
    Vertex *tmp = new Vertex();
    tmp->left = tmp->right = NULL;
    tmp->parent = par;
    if ((r-l+1) > LEAF_LEN) {
        tmp->lCount = (r-l+2)/2;
        cout<<(tmp->lCount)<<" "<<l<<" "<<r<<endl;
        node = tmp;
        int m = (l + r)/2;
        build_rope(node->left, node,  l, m);
        build_rope(node->right, node,  m+1, r);
    } else {
        node = tmp;
        tmp->lCount = (r-l+1);

        cout<<(tmp->lCount)<<"  leaf " <<l<<" "<< r<<endl;
        tmp->str = s.substr(r,r-l+1);
        cout<<(tmp->str)<<endl;
    }
}
void process( int i, int j, int k ) {

}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    Vertex* ver = new Vertex();
    build_rope(ver, NULL, 0,static_cast<int>(s.size() - 1));
    int actions;
    cin >> actions;
    for (int action_index = 0; action_index < actions; ++action_index) {
        int i, j, k;
        cin >> i >> j >> k;
        process(i, j, k);
    }
    cout <<s<< endl;
}
