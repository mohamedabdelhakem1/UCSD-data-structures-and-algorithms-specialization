#include <iostream>
#include <cassert>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.
const int MAX = 1000000;
int fib[MAX];
int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
    if(n <= 1)
        return n;
    if(fib[n] != -1)
        return fib[n];
    fib [n] = fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
    return fib[n];
}

int fibonacci_dp(int n) {
    int fib [n+1];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2 ; i <= n ; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    std::cin >> n;
    fill_n(fib, MAX, -1);
    //std::cout << fibonacci_naive(n) << '\n';
    //test_solution();
    std::cout << fibonacci_dp(n) << '\n';
    return 0;
}
