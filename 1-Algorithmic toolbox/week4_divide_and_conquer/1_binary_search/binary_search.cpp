#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll binary_search(const vector<ll> &a, ll x) {
    ll left = 0, right = a.size();
    ll mid = 0;
    while(left <= right) {
        mid =  (left + right) /2 ;
        if(a[mid] == x) {
            return mid;
        } else if(a[mid] > x) {
            right = mid-1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int linear_search(const vector<int> &a, int x) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == x)
            return i;
    }
    return -1;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < a.size(); i++) {
        cin >> a[i];
    }
    ll m;
    cin >> m;
    vector<ll> b(m);
    for (ll i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    for (ll i = 0; i < m; ++i) {
       //  cout << linear_search(a, b[i]) << ' ';
        cout << binary_search(a, b[i]) << ' ';
    }
}
