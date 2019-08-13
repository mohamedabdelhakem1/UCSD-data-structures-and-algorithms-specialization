#include <bits/stdc++.h>
using namespace std;

int optimal_weight(const int W, const vector<int> &w) {
    const int n = w.size();
    vector< vector<int> > dp( n+1, vector<int>(W+1) );
    for(int i = 0 ; i <= n ; i++) {
        dp[i][0] = 0;
    }
    for(int i = 0 ; i <= W ; i++) {
        dp[0][i] = 0;
    }
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= W ; j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= w[i-1]){
                dp[i][j] = max(dp [i-1][j-w[i-1]] + w[i-1] , dp[i][j]);
            }
        }
    }
    return  dp[n][W];
}

int main() {
    int n, W;
    std::cin >> W >> n;
    vector<int> w(n);

    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    std::cout << optimal_weight(W, w) << '\n';
}
