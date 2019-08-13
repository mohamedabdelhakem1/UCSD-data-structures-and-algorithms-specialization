#include <bits/stdc++.h>
using namespace std;

int edit_distance(const string &str1, const string &str2) {
    int n = str1.size();
    int m = str2.size();
    int dp [m+1][n+1];
    for(int i = 0 ; i <= n ; i++) {
        dp[0][i] = i;
    }
    for(int i = 0 ; i <= m ; i++) {
        dp[i][0] = i;
    }
    for(int i = 1 ; i <= m ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            if(str2[i-1] == str1[j-1]) {
                dp[i][j] = min(dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1]) );
            } else {
                dp[i][j] = min(dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1]+1) );
            }
        }
    }
    return dp[m][n];
}

int main() {
    string str1;
    string str2;
    std::cin >> str1 >> str2;
    std::cout << edit_distance(str1, str2) << std::endl;
    return 0;
}
