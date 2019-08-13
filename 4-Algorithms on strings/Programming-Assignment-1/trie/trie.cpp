#include <bits/stdc++.h>
using namespace std;

struct edge {
    int from;
    int to;
    char label;
};
struct vertex {
    int index;
    unordered_map <char, edge> out_edges;
};
class trie {
public:
    vertex *root = new vertex();
    unordered_map <int, vertex*> vertices;
    trie() {
        root->index = 0;
        vertices[0] = root;
    }
    vector<edge> edges;

    int size() {
        return static_cast<int>(edges.size());
    }
};

trie* build_trie(vector<string> & patterns) {

    trie *t = new trie();
    int c = 1;
    for(int i = 0 ; i < patterns.size() ; i++) {
        vertex *v = t->root;
        for(int j  = 0 ; j < static_cast<int>(patterns[i].size()) ; j++) {
             if( v->out_edges.find(patterns[i][j])  != v->out_edges.end()) {
                int num =  v->out_edges[patterns[i][j]].to;
                v = t->vertices[num];
            } else {
                vertex* new_vertex = new vertex();
                new_vertex->index = c;
                t->vertices[c] = new_vertex ;
                v->out_edges[patterns[i][j]] = {v->index, c, patterns[i][j] } ;
                t->edges.push_back( v->out_edges[patterns[i][j]]);
                v = new_vertex;
                c++;
            }
        }

    }

    return t;
}

int main() {
    size_t n;
    std::cin >> n;
    vector<string> patterns;
    for (size_t i = 0; i < n; i++) {
        string s;
        std::cin >> s;
        patterns.push_back(s);
    }

    trie *t = build_trie(patterns);
    vector <edge> ed =  t->edges;
    for (size_t i = 0; i < ed.size(); ++i) {
        cout << ed[i].from << "->" << ed[i].to <<":"<<ed[i].label <<endl;
    }

    return 0;
}
