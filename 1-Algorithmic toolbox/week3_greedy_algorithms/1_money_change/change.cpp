#include <bits/stdc++.h>
using namespace std;

int get_change(int m) {
    int siz = m + 1;
    int dp[siz];
    fill_n(dp,siz, -1);
    vector <int> coins = {1,5,10};
    dp[0] = 0;
    for(int i = 1 ; i <= m ; i++) {
        if(i == 1 || i == 5 || i == 10) {
            dp[i] = 1;
        } else {
            for(int j = 0 ; j < 3 ; j++) {
                if(i - coins[j] >= 0) {
                    if(dp[i] == -1) {
                        dp[i] = 1 + dp[i - coins[j]];
                    } else {
                        dp[i] = min (dp[i], 1 + dp[i - coins[j]]);
                    }
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
