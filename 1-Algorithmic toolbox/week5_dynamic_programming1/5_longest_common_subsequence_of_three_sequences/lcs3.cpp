#include <bits/stdc++.h>
using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
    int n1 = a.size();
    int n2 = b.size();
    int n3 = c.size();
    int dp[n3+1][n2+1][n1+1];
    for(int j = 0 ; j <= n3 ; j++) {
        for(int i = 0 ; i <= n2 ; i++) {
            dp[j][i][0] = 0;
        }
        for(int i = 0 ; i <= n1 ; i++) {
            dp[j][0][i] = 0;
        }
    }
    for(int i = 0 ; i <= n3 ; i++) {
        for(int j = 1 ; j <= n2 ; j++) {
            for(int k = 1 ; k <= n1 ; k++) {
                if(i == 0) {
                    dp[i][j][k] = 0;
                } else {
                    int inc = ((a[k-1] == b[j-1]) && (b[j-1] == c[i-1]));
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k],max(dp[i][j][k-1], dp[i-1][j-1][k-1] + inc)));
                }
            }
        }
    }
//    for(int i = 0 ; i <= n3 ; i++) {
//        cout<<"layer " << i <<endl;
//        for(int j = 0 ; j <= n2 ; j++) {
//            for(int k = 0 ; k <= n1 ; k++) {
//                cout<< dp[i][j][k]<<" ";
//            }
//            cout<<endl;
//        }
//    }
    return dp[n3][n2][n1];
}
int main() {
    size_t an;
    std::cin >> an;
    vector<int> a(an);
    for (size_t i = 0; i < an; i++) {
        std::cin >> a[i];
    }
    size_t bn;
    std::cin >> bn;
    vector<int> b(bn);
    for (size_t i = 0; i < bn; i++) {
        std::cin >> b[i];
    }
    size_t cn;
    std::cin >> cn;
    vector<int> c(cn);
    for (size_t i = 0; i < cn; i++) {
        std::cin >> c[i];
    }
    std::cout << lcs3(a, b, c) << std::endl;
}
