#include <bits/stdc++.h>
using namespace std;
int get_change(int m) {
    int dp[m+1];
    dp[0] = 0;
    fill_n(dp, m+1, INT_MAX);
    vector <int> coins = {1,3,4};
    for(int i = 1 ; i <= m ; i++) {
        if(i == 1 || i == 3 || i == 4) {
            dp[i] = 1;
        } else {
            for(int j = 0 ; j < 3 ; j++) {
                if(i - coins[j] >= 0) {
                    dp[i] = min(dp[i], 1 + dp[i-coins[j]] );
                }
            }
        }
    }
    return dp[m];
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
