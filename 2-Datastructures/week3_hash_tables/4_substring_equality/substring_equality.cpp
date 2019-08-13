#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
typedef  unsigned long long ull;
static const  ll m1 = 1000000009ll ;
static const  ll m2 = 1000000007ll ;
ll power(ll x,  ull y , int mod)  {
    ll res = 1ll;     // Initialize result

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x)% mod;

        // n must be even now
        y = y>>1; // y = y/2
        x = (x*x) % mod;  // Change x to x^2
    }
    return res;
}
vector <ll> precompute_hashes(string text, long long m,long long x ) {
    int n = static_cast< int >(text.size())  ;
    vector<ll> H(n+1);
    H[0] = 0ll;
    for (int i = 1 ; i <= n; i++) {
        H[i] =  (((x *  H[i-1]) % m )+ text[i-1]) % m;
    }
    return H;
}
class Solver {
    string s;
    vector<ll> H1;
    vector<ll> H2;
    ll x;
public:
    Solver(string s) : s(s) {
        x = 31ll;
        H1 = precompute_hashes(s,m1,x);
        H2 = precompute_hashes(s,m2,x);
    }
    bool ask(int a, int b, int l) {
        ll x_l_1 = power(x,l,m1);
        ll x_l_2 = power(x,l,m2);
        x_l_1 *= -1;
        x_l_2 *= -1;

        ll ha1 = (((m1 + x_l_1 * H1[a] ) % m1) + H1[a+l] ) % m1;
        ll hb1 = (((m1 + x_l_1 * H1[b] ) % m1) + H1[b+l]  )% m1;
        ll ha2 = (((m2 + x_l_2 * H2[a] ) % m2) + H2[a+l]  )% m2;
        ll hb2 = (((m2 + x_l_2 * H2[b] ) % m2) + H2[b+l]  )% m2;
        return (ha1 == hb1) && (ha2 == hb2);
    }
     bool ask2(int a, int b, int l) {
        return s.substr(a,l) == s.substr(b,l);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    string s;
    int q;
    cin >> s >> q;
    Solver solver(s);
    for (int i = 0; i < q; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
    }
}
