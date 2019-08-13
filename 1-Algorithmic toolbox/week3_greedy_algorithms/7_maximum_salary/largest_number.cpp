#include <bits/stdc++.h>
using namespace std;

bool compare(string s1, string s2) {
    int r1 = stoi (s1+s2);
    int r2 =  stoi(s2+s1);
    if(r1 <= r2) {
        return false;
    }
    return true;
}
string largest_number(vector<string> a) {
    sort(a.begin(), a.end(), compare);
    stringstream ret;
    for (size_t i = 0; i < a.size(); i++) {
        ret << a[i];
    }
    string result;
    ret >> result;
    return result;
}

int main() {
    int n;
    std::cin >> n;
    vector<string> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    std::cout << largest_number(a);
}
