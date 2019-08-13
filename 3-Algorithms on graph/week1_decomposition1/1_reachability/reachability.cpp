#include <bits/stdc++.h>
using namespace std;
int found = 0;
void dfs(vector<vector<int> > &adj, int x, int y, vector <bool> visited) {
    visited[x] = true;
    if(x == y) {
        found =1;
        return;
    }
    for(int i = 0 ; i < adj[x].size() ; i++) {
        if(visited[adj[x][i]] == false && found == 0) {
            dfs(adj,adj[x][i],y ,visited);
        }
    }
}
int reach(vector<vector<int> > &adj, int x, int y) {
    vector <bool> visited(adj.size(), false);
    dfs(adj, x,y, visited);
    return found;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    int x, y;
    std::cin >> x >> y;
    std::cout << reach(adj, x - 1, y - 1);
}
