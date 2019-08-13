#include <bits/stdc++.h>
using namespace std;

struct edge {
    int from;
    int to;
    string label;
};
struct vertex {
    int number;
    unordered_map <char, edge> out_edges;
};
class suffix_tree {
public:
    vertex *root = new vertex();
    unordered_map <int, vertex*> vertices;
    suffix_tree() {
        root->number = 0;
        vertices[0] = root;
    }
};

vector<string> ComputeSuffixTreeEdges(const string& text) {
    vector<string> result;
    suffix_tree *tree = new suffix_tree();
    edge e  = {0, 1,text };
    vertex *ver = new vertex();
    ver->number = 1 ;
    tree->vertices[1] = ver;
    tree->root->out_edges[text[0]] = e;
    int c = 2;
    for(int i = 1 ; i < text.size() ; i++) {
        vertex* ver = tree->root;
        for(int j = i ; j < text.size() ; j++) {
            if(ver->out_edges.find(text[j]) != ver->out_edges.end()) {
                // break edge
                string s = ver->out_edges[text[j]].label;
                if(text.substr(j, s.size()) == s) {
                    int too =  ver->out_edges[text[j]].to;
                    ver = tree->vertices[too];
                    j = j + s.size()- 1;
                } else {
                    int old_j = j;
                    j++;
                    int it = 1;
                    while(it < s.size()&& s[it] == text[j] && j <text.size()) {
                        j++;
                        it++;
                    }
                    //break
                    string s1 = s.substr(0,it);  //first  half
                    string s2 = s.substr(it);   //second half
                    ver->out_edges[text[old_j]].label = s1;
                    int too =  ver->out_edges[text[old_j]].to;
                    ver->out_edges[text[old_j]].to = c;
                    vertex *new_vertex = new vertex();
                    new_vertex->number = c;
                    edge e2 = {c, too, s2};
                    new_vertex->out_edges[s2[0]] = e2;
                    tree->vertices[c] = new_vertex;
                    c++;
                    j--;
                    ver =  new_vertex;
                }
            } else {
                edge e = {ver->number, c, text.substr(j) };
                vertex *new_ver = new vertex();
                new_ver->number = c ;
                tree->vertices[c] = new_ver;
                ver->out_edges[text[j]] = e;
                c++;
                break;
            }

        }
    }
    vertex* r;
    queue <int > verticies;

    verticies.push( tree->root->number);
    while(!verticies.empty()) {
        int top =  verticies.front();
        verticies.pop();
        r = tree->vertices[top];
        unordered_map <char, edge> outedges = r->out_edges;
        for(auto  it = outedges.begin() ; it != outedges.end() ; it++) {
            result.push_back(it->second.label);
            verticies.push(it->second.to);
        }
    }
    return result;
}

int main() {
    string text;
    cin >> text;
    vector<string> edges = ComputeSuffixTreeEdges(text);
    for (int i = 0; i < edges.size(); ++i) {
       cout << edges[i] << endl;
    }
    return 0;
}
