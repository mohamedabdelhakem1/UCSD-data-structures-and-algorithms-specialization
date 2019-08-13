#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int> > &adj, int x, vector <bool> &visited) {
    visited[x] = true;
    for(int i = 0 ; i < adj[x].size() ; i++) {
        if(visited[adj[x][i]] == false ) {
            dfs(adj,adj[x][i],visited);
        }
    }
}
int number_of_components(vector<vector<int> > &adj) {
    int c = 0;
    vector <bool> visited(adj.size(), false);
    for(int i = 0 ; i < adj.size() ; i++) {
        if(visited[i] == false) {
            dfs(adj,i,visited);
            c++;
        }
    }
    return c;
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
    std::cout << number_of_components(adj);
}
