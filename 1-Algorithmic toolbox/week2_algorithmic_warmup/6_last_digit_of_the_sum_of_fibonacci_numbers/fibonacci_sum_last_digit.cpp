#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;
    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous % 10 ;
        previous = current % 10;
        current = (tmp_previous % 10 + current % 10) % 10 ;
        sum += current % 10;
        sum %= 10;
    }
    return sum ;
}

ll fibonacci_dp(ll n) {
    ll fib [n+3];
    fib[0] = 0;
    fib[1] = 1;
    for(ll i = 2 ; i < n+3 ; i++) {
        fib[i] = (fib[i-1] % 10 + fib[i-2] % 10) % 10;
    }
    return ((fib[n+2] -1 + 10) % 10);
}

int main() {
    long long n = 0;
    std::cin >> n ;
    std::cout << fibonacci_dp(n % 60)<<endl;

}
