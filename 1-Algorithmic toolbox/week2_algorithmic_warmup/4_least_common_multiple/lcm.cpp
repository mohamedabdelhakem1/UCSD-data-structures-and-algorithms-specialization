#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_naive_optimized1(int a, int b) {
  for (long l = max(a,b) ; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}
long long gcd(int a ,int b){
    if(b == 0)
        return a;
    return gcd(b,a%b);
}
long long lcm_fast(long long a, long long b) {
  return ((long long) (a * b))/gcd(a,b);
}
int main() {
  int a, b;
  cin >> a >> b;
  //cout << lcm_naive(a, b) << endl;
  cout << lcm_fast(a,b)<<endl;
  return 0;
}
