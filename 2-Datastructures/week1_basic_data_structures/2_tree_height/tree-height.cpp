#include <bits/stdc++.h>
using namespace std;
class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
        this->parent = NULL;
    }

    void setParent(Node *theParent) {
        parent = theParent;
        parent->children.push_back(this);
    }
    int get_height(Node *n) {
        int maxx = 0;
        for(int i = 0 ;i < n->children.size() ;i++){
            maxx = max(maxx , get_height(n->children[i]));
        }
        return 1 + maxx;
    }
};


int main_with_large_stack_space() {
    std::ios_base::sync_with_stdio(0);
    int n;
    std::cin >> n;
    std::vector<Node> nodes;
    vector<int> nds;
    nodes.resize(n);
    int p_i = 0;
    for (int child_index = 0; child_index < n; child_index++) {
        int parent_index;
        std::cin >> parent_index;
        nds.push_back(parent_index);
        if (parent_index >= 0)
            nodes[child_index].setParent(&nodes[parent_index]);
        else
            p_i = child_index;
        nodes[child_index].key = child_index;
    }

    // Replace this code with a faster implementation
 //   int maxHeight = 0;
//    for (int leaf_index = 0; leaf_index < n; leaf_index++) {
//        int height = 0;
//        for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent)
//            height++;
//        maxHeight = std::max(maxHeight, height);
//    }

    cout <<nodes[p_i].get_height(&nodes[p_i])<< endl;
    return 0;
}

int main (int argc, char **argv) {
    return main_with_large_stack_space();
}
