#include <bits/stdc++.h>
using namespace std;
int found = 0;
void dfs(vector<vector<int> > &adj, int x, vector <bool> &visited,vector <bool> &finished) {
    visited[x] = true;
    for(int i = 0 ; i < adj[x].size() ; i++) {
        if(visited[adj[x][i]] == false && found == 0) {
            dfs(adj,adj[x][i],visited , finished);
        }else if(found == 0 && visited[adj[x][i]] == true &&finished[adj[x][i]] == false){
            found = 1;
            return;
        }
    }
    finished[x] = true;

}
int acyclic(vector<vector<int> > &adj) {
    vector <bool> visited(adj.size(), false);
    vector <bool> finished(adj.size(), false);
    for(int i = 0 ; i < adj.size() ; i++) {
        if(visited[i] == false) {
            dfs(adj,i,visited , finished);
        }
    }
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
  }
  std::cout << acyclic(adj);
}
