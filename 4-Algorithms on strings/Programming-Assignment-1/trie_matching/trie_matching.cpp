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
vector <int> solve (const string& text, int n,  vector <string>& patterns)
{   trie *t = build_trie(patterns);
	vector <int> result;

    for(int i = 0 ; i < text.size(); i++){
        int j = i;
        vertex *v = t->root;
        while(j < text.size()){
            if(v->out_edges.size() == 0){ // leaf
                result.push_back(i);
                break;
            } else if(v->out_edges.find(text[j]) != v->out_edges.end()){
                int v_num= v->out_edges[text[j]].to;
                v = t->vertices[v_num];
                j++;
            }else{
                break;
            }
        }
          if(j == text.size() && v->out_edges.size() == 0){ // leaf
                result.push_back(i);
            }
    }

    sort(result.begin() , result.end());
	return result;
}

int main (void)
{
	string t;
	cin >> t;

	int n;
	cin >> n;

	vector <string> patterns (n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve (t, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++)
	{
		cout << ans[i];
		if (i + 1 < (int) ans.size ())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}
