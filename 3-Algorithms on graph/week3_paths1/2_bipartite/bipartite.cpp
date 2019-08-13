#include <iostream>
#include <vector>
#include <queue>
#define BLACK 1
#define WHITE 0
using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
    int n =  adj.size();
    vector <bool> visited(n);
    vector <int> color(n , -1);
    queue<int>q;
    q.push(0);
    visited[0] = true;
    color[0] = 0;
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        int _color = (color[top] == 0) ? 1:0;
        for(int i = 0 ; i < adj[top].size() ; i ++) {
            if(visited[adj[top][i]] == false) {
                visited[adj[top][i]] = true;
                color[adj[top][i]] = _color;
                q.push(adj[top][i]);
            }
            if( visited[adj[top][i]] && color[top] == color[adj[top][i]]){
                return 0;
            }
        }
    }


    return 1;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    std::cout << bipartite(adj);
}
