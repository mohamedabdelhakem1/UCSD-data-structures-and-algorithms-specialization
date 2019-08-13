#include <bits/stdc++.h>
using namespace std;
typedef pair<double,int> pi;

double compute_dist(int x1, int x2,int y1,int y2) {
    int dx = x1 - x2;
    int dy = y1 - y2;
    return sqrt(dx*dx + dy*dy);
}
double minimum_distance(vector<int> x, vector<int> y) {
    double result = 0.;
    int n = x.size();
    vector<vector <double> > adj_mat(n, vector <double>(n));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            adj_mat[i][j] = compute_dist(x[i], x[j], y[i], y[j]);
        }
    }
    vector <double> cost(n, DBL_MAX);
    cost[0] = 0;
    set<pi> st;
    st.insert(make_pair(0,0));
    for(int i = 1 ; i<n; i++ ) {
          st.insert(make_pair(cost[i],i));
    }
    while(!st.empty()) {
        auto it =  st.begin();
        st.erase(it);
        pi top = *it;
        result += top.first;
        for(int i = 0 ; i < n ; i++ ) {
            if(i == top.second)
                continue;
            if(st.find(make_pair(cost[i],i)) != st.end() && cost[i] > adj_mat[top.second][i]) {
                st.erase(make_pair(cost[i],i));
                cost[i]  = adj_mat[top.second][i];
                st.insert(make_pair(cost[i],i));
            }
        }
    }
    return result;
}

int main() {
    size_t n;
    std::cin >> n;
    vector<int> x(n), y(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
