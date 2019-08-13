#include <bits/stdc++.h>
using namespace std;
int result = 0;
int _id = 1;
stack<int>_stack;
void dfs(vector<vector<int> > &adj, int x, vector <int> &id, vector <int> &low_link, vector <bool> &on_stack ) {
    id[x] = _id;
    low_link[x] = id[x];
    _stack.push(x);
    on_stack[x] = true;
    _id++;
    for(int i = 0 ; i < adj[x].size() ; i++) {
        if(id[adj[x][i]] == -1) {
            dfs(adj, adj[x][i], id, low_link, on_stack);
        }
        if(on_stack[adj[x][i]] == true) {
            low_link[x] = min(low_link[x],low_link[adj[x][i]] );
        }
    }
    if(id[x] ==  low_link[x]) {
        result++;
        int i = _stack.top() ;
        while(!_stack.empty()) {
            _stack.pop();
            on_stack[i] = false;
            low_link[i] = id[x];
            if(i == x)
                break;
            i = _stack.top();
        }
    }
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
    int n = adj.size();
    vector <int> id(n,-1);
    vector <int> low_link(n,INT_MAX);
    vector <bool> on_stack(n,false);

    for(int i = 0 ; i < adj.size() ; i++) {
        if(id[i] == -1) {
            dfs(adj, i, id, low_link, on_stack);
            //    fill(on_stack.begin(),on_stack.end(), false);
        }
    }
    return result;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }
    std::cout << number_of_strongly_connected_components(adj);
}
