#include <bits/stdc++.h>
using namespace std;

int partition3(vector<int> &A, int num) {
    unordered_map <int,int > freq;
    int m = A.size();
    int dp [m+1][num+1];
    A.insert(A.begin(), 0);
    for(int i = 0 ; i < A.size() ; i++) {
        if( freq.find(A[i]) != freq.end()) {
            freq[A[i]]++;
        } else {
            freq[A[i]] = 1;
        }
    }
    for(int i = 0 ; i <= m ; i++ ) {
        dp[i][0] = 0;
    }
    for(int i = 0 ; i <= num ; i++ ) {
        dp[0][i] = 0;
    }
    int countt = 0;

    for(int i = 1 ; i <= m ; i++) {
        for(int j = 1 ; j <= num ; j++ ) {
            dp[i][j] = dp[i-1][j];
            if( j >= A[i] ) {
                dp[i][j] = max(dp[i][j], dp[i-1][j - A[i]] + A[i] );
            }
            if(dp[i][j] == num) {
                countt++;
            }
        }
    }

    for(int i = 0 ; i <= m ; i++) {
        for(int j = 0 ; j <= num ; j++ ) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return (countt >= 3);
}

int main() {
    int n;
    std::cin >> n;
    vector<int> A(n);
    int sum = 0;
    for (size_t i = 0; i < A.size(); ++i) {
        std::cin >> A[i];
        sum += A[i];
    }
    if(sum % 3 != 0) {
        cout<< "0";
    } else {
        std::cout << partition3(A,sum/3) << '\n';
    }
}
