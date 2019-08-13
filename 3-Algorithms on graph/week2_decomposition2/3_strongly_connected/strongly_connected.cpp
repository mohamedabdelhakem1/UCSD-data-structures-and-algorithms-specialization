#include <bits/stdc++.h>
using namespace std;

void dfs_reversed(vector<vector<int> > &reversed, int x, vector <bool> &visited) {
    visited[x] = true;
    for(int i = 0 ; i < reversed[x].size() ; i++) {
        if(visited[reversed[x][i]] == false) {
            dfs_reversed(reversed,reversed[x][i],visited);
        }
    }
}
void dfs(vector<vector<int> > &adj, int x, vector <bool> &visited,vector <int> &order) {
    visited[x] = true;
    for(int i = 0 ; i < adj[x].size() ; i++) {
        if(visited[adj[x][i]] == false) {
            dfs(adj,adj[x][i],visited, order);
        }
    }
    order.insert(order.begin(),x);
}
vector<vector<int> > reverse_graph(vector<vector<int> > adj) {
    vector<vector<int> > reversed (adj.size());
    for(int i = 0 ; i < adj.size() ; i++) {
        for(int j = 0 ; j < adj[i].size() ; j++) {
            reversed[adj[i][j]].push_back(i);
        }
    }
    return reversed;
}
int number_of_strongly_connected_components(vector<vector<int> > adj) {
    int result = 0;
    vector <bool> visited(adj.size(), false);
    vector <int> order;
    for(int i = 0 ; i < adj.size() ; i++) {
        if(visited[i] == false) {
            dfs(adj,i,visited, order);
        }
    }
    vector<vector<int> > reversed = reverse_graph(adj);

    fill(visited.begin(),visited.end(),false);
    for(int  i= 0 ; i < order.size() ; i++ ) {
        if(visited[order[i]] == false) {
            dfs_reversed(reversed,order[i],visited);
            result++;
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
