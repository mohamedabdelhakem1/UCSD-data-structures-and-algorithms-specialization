#include <iostream>
#include <bits/stdc++.h>
using  namespace std;
int fibonacci_dp_fast(int n, int m) {
    int fib [n+1];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2 ; i <= n ; i++) {
        fib[i] = ((fib[i-1] % m) + (fib[i-2] % m )) % m;
    }
    return fib[n] % m;
}
int pisano_peroid(int m) {
    vector <int> fib {0,1};
    int i = 2;
    while(true) {
        int n = ((fib[i-1] % m) + (fib[i-2] % m )) % m ;
        fib.push_back(n);
        if(fib[i] == 1 &&  fib[i-1] == 0) {
            return i-1;
        }
        i++;
    }
    return 1;
}
int main() {
    long long n, m;
    std::cin >> n >> m;
    int period =  pisano_peroid(m);
    std::cout << fibonacci_dp_fast(n % period, m) << '\n';
}
