#include <bits/stdc++.h>

using std::vector;
using std::queue;
int distance(vector<vector<int> > &adj, int s, int t) {
    int n = adj.size();
    vector<int> dist(n, -1);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        for(int i = 0 ; i < adj[top].size() ; i++) {
            if(dist[adj[top][i]] == -1){
                q.push(adj[top][i]);
                dist[adj[top][i]] = dist[top] + 1;
            }
        }
    }
    return dist[t]  ;
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
    int s, t;
    std::cin >> s >> t;
    s--, t--;
    std::cout << distance(adj, s, t);
}
