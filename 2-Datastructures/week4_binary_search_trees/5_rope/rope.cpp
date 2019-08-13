#include <bits/stdc++.h>
using namespace std;
const int LEAF_LEN = 1;
string s;
class Rope {
public:
    Rope *left, *right, *parent;
    string str;
    int lCount;

};

void build_rope(Rope *node, Rope *par, int l,int r) {
    Rope *tmp = new Rope();
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
void split_rope(Rope *rope, Rope *left, Rope *right, int i) {
    Rope *temp   = rope;
    while(true){

    }
}
void merge_rope( Rope *root,Rope *root1, Rope *root2) {
    Rope *tmp = new Rope();
    tmp->parent = NULL;
    tmp->left = root1;
    tmp->right = root2;
    root1->parent = root2->parent = tmp;
    tmp->lCount = root1->lCount;
    root = tmp;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    Rope *rope = NULL;
    build_rope(rope, NULL, 0,static_cast<int>(s.size() - 1));
    int actions;
    cin >> actions;
    for (int action_index = 0; action_index < actions; ++action_index) {
        int i, j, k;
        cin >> i >> j >> k;
        process(i, j, k);
    }
    cout <<s<< endl;
}
