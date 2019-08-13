#include <bits/stdc++.h>
#define ll long long
using namespace std;
int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

ll fibonacci_dp(ll n) {
    ll fib [n+2];
    fib[0] = 0;
    fib[1] = 1;
    for(ll i = 2 ; i < n+2 ; i++) {
        fib[i] = (fib[i-1] % 10 + fib[i-2] % 10) % 10;
    }
    return ((fib[n+1] * fib[n]) % 10);
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_dp(n % 60)<<endl;
   // std::cout << fibonacci_sum_squares_naive(n)<<endl;
}
