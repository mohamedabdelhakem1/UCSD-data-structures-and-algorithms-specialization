#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}
long long fibonacci_dp(long long from, long long n) {
    int fib [n+3];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2 ; i < n+3 ; i++) {
        fib[i] = (fib[i-1] % 10 + fib[i-2] % 10) % 10;
    }
    return (((fib[n+2] - 1 + 10) % 10) - ((fib[from+1] - 1 + 10) % 10) + 10) % 10 ;
}
int main() {
    long long from , to;
    cin >> from >> to;
    from = from % 60;
    to = to % 60;
    if(to < from ){
        to += 60;
    }
    cout << fibonacci_dp(from , to ) << '\n';
}
