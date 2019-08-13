#include <bits/stdc++.h>
using namespace std;
vector<int> optimal_sequence(int n) {
    std::vector<int> sequence;
    while (n >= 1) {
        sequence.push_back(n);
        if (n % 3 == 0) {
            n = n/3;
        }
        if (n % 2 == 0) {
            n = min ( n/2,n);
        }
        n = min ( n,n - 1);

    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}
vector<int> optimal_sequence_dp(int n) {
    int dp[n+1];
    int prev[n+1];
    dp[0] = 0;
    dp[1] = 0;
    prev[0] = 0;
    prev[1] = 1;
    for(int i = 2 ; i <= n ; i++) {
        int s1 = (i%2 == 0) ? dp[i/2] + 1 : INT_MAX;
        int s2 = (i%3 == 0) ? dp[i/3] + 1 : INT_MAX;
        int s3 = dp[i-1] + 1;
        dp[i] = min(s1,min(s2,s3));
        if(dp[i] == s1) {
            prev[i] = i/2;
        } else if(dp[i] == s2) {
            prev[i] = i/3;
        } else {
            prev[i] = i-1;
        }
    }
    vector <int> sequence;
    int i = n;
    while(i != 1) {
        sequence.insert(sequence.begin(),i);
        i = prev[i];
    }
    sequence.insert(sequence.begin(),1);
    return sequence;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> sequence = optimal_sequence_dp(n);
    std::cout << sequence.size() - 1 << std::endl;
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
}
