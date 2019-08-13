#include <bits/stdc++.h>
using namespace std;
int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
    int v = adj.size();
    vector <int>dist(v,INT_MAX /2);
    dist[0] = 0;
    for(int i = 0 ; i < v-1 ; i++) {
        for(int at = 0 ; at < v ; at++) {
            int k = 0;
            for(int to : adj[at]) {
                if(dist[to] > dist[at] + cost[at][k]) {
                    dist[to] = dist[at] + cost[at][k];
                }
                k++;
            }
        }
    }
    for(int at = 0 ; at < v ; at++) {
        int k = 0;
        for(int to : adj[at]) {
            if(dist[to] > dist[at] + cost[at][k]) {
                return 1;
            }
            k++;
        }
    }

    return 0;
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
    std::cout << negative_cycle(adj, cost);
}
