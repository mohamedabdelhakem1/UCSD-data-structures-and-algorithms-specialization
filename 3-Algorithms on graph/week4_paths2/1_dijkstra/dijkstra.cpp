#include <bits/stdc++.h>
using namespace std;
typedef  pair <int,int> pi;

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
    int n = adj.size();
    vector <int> dist(n,INT_MAX);
    dist[s] = 0;
    set<pi> sett;
    sett.insert(make_pair(0,s));
    while(!sett.empty()) {
        auto it = sett.begin();
        pi minn =  *it;
        sett.erase(it);
        int u =  minn.second;
        for(int i = 0 ; i < adj[u].size() ; i++) {
            int v = adj[u][i];
            if(dist[v] > dist[u] + cost[u][i]) {
                sett.erase(make_pair(dist[v] ,v));
                dist[v] = dist[u] + cost[u][i];
                sett.insert(make_pair(dist[v],v));
            }
        }
    }
    return (dist[t] ==  INT_MAX) ? -1:dist[t];
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    vector<vector<int> > cost(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    int s, t;
    std::cin >> s >> t;
    s--, t--;
    std::cout << distance(adj, cost, s, t);
}
