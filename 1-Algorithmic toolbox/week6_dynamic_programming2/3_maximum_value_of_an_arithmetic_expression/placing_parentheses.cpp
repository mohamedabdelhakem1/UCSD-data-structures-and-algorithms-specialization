#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long eval(long long a, long long b, char op) {
    if (op == '*') {
        return a * b;
    } else if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else {
        assert(0);
    }
}

long long get_maximum_value( string &exp) {
    ll n = exp.size()/2;
    char ops[n];
    ll ints[n + 1];
    for(ll i = 0 ; i < exp.size() ; i++) {
        if(i % 2 == 0) {
            ints[i/2] =  exp[i] - '0';
        } else {
            ops[i/2] = exp[i] - 0;
        }
    }
    ll minn[n+1][n+1];
    ll maxx[n+1][n+1];

    for(ll i = 0 ; i <= n ; i++) {
        for(ll j = 0 ; j <= n ; j++) {
            maxx[i][j] = 0;
            minn[i][j] = 0;
        }
    }
    for(ll i = 0 ; i <= n ;i++) {
        minn[i][i] = ints[i];
        maxx[i][i] = ints[i];
    }
    for(ll l = 1; l <= n; l++ ) {
        for(ll i = 0 ; i <= n-l ; i++) {
            ll j = i + l;
            ll mi = LONG_MAX;
            ll Ma = INT_MIN;
            for(ll k = i ; k < j ; k++) {
                ll a = eval(minn[i][k],maxx[k+1][j],ops[k]);
                ll b = eval(maxx[i][k],maxx[k+1][j],ops[k]);
                ll c = eval(minn[i][k],minn[k+1][j],ops[k]);
                ll d = eval(maxx[i][k],minn[k+1][j],ops[k]);
                mi = min(mi,min(a,min(b,min(c,d))));
                Ma = max(Ma,max(a,max(b,max(c,d))));
            }
            minn[i][j] = mi;
            maxx[i][j] = Ma;
        }
    }

    return maxx[0][n];
}

int main() {
    string s;
    std::cin >> s;
    std::cout << get_maximum_value(s) << '\n';
}
