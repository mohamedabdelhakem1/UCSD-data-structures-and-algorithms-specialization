#include <bits/stdc++.h>
using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
    int n1 = a.size();
    int n2 = b.size();
    int dp[n2+1][n1+1];
    for(int i = 0 ; i <= n1 ; i++) {
        dp[0][i] = 0;
    }
    for(int i = 0 ; i <= n2 ; i++) {
        dp[i][0] = 0;
    }
    for(int i = 1 ; i <= n2 ; i++) {
        for(int j = 1 ; j <= n1 ; j++) {
            int inc = (a[j-1] == b[i-1]);
            dp[i][j] = max(dp[i-1][j] , max(dp[i][j-1]  , dp[i-1][j-1] + inc));
        }
    }
    return dp[n2][n1];
}
int main() {
    size_t n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    size_t m;
    cin >> m;
    vector<int> b(m);
    for (size_t i = 0; i < m; i++) {
        cin >> b[i];
    }
    cout << lcs2(a, b) << endl;
}
