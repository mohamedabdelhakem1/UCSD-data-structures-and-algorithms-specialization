#include <bits/stdc++.h>
using namespace std;

void bfs( vector<vector<int> > &adj, vector<int> &shortest, vector <int> relaxed) {
    queue <int> q;
    vector<int> visited(adj.size(), 0);
    for(int i = 0 ; i< relaxed.size() ; i++) {
        q.push(relaxed[i]);
        visited[relaxed[i]] = 1;
    }
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        shortest[top] = false;
        for(int to : adj[top]) {
            if(visited[to] == 0) {
                visited[to] =1;
                q.push(to);
            }
        }
    }

}
void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
    int v = adj.size();
    long long maxx = 9223372036854775807L;
    vector <long long>dist(v, maxx );
    dist[s] = 0;
    reachable[s] = 1;
    for(int i = 0 ; i < v-1 ; i++) {
        for(int at = 0 ; at < v ; at++) {
            int k = 0;
            for(int to : adj[at]) {
                if(dist[at] == maxx) {
                    continue;
                }
                if(dist[to] > dist[at] + cost[at][k]) {
                    dist[to] = dist[at] + cost[at][k];
                    reachable[to] = 1 ;
                }
                k++;
            }
        }
    }
    distance = dist;
    vector <int>relaxed;
    for(int at = 0 ; at < v ; at++) {
        int k = 0;
        for(int to : adj[at]) {
            if(dist[at] == maxx) {
                continue;
            }
            if(dist[to] > dist[at] + cost[at][k]) {
                dist[to] = dist[at] + cost[at][k];
                relaxed.push_back(to);
            }
            k++;
        }
    }
    bfs(adj,shortest,relaxed);
}

int main() {
    int n, m, s;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    vector<vector<int> > cost(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    std::cin >> s;
    s--;
    vector<long long> distance(n, std::numeric_limits<long long>::max());
    vector<int> reachable(n, 0);
    vector<int> shortest(n, 1);
    shortest_paths(adj, cost, s, distance, reachable, shortest);
    for (int i = 0; i < n; i++) {
        if (!reachable[i]) {
            std::cout << "*\n";
        } else if (!shortest[i]) {
            std::cout << "-\n";
        } else {
            std::cout << distance[i] << "\n";
        }
    }
}
