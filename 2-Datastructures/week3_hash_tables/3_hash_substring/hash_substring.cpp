#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
static const long long x = 263;
static const long long prime = 1000000007;
ull poly_hash_func(const string& s)  {
    unsigned long long hash = 0;
    for (int i = static_cast< int >( s.size() ) - 1; i >= 0; --i)
        hash = (hash * x + s[i]) % prime;
    return hash ;
}
vector <ull> precompute_hashes(string text, string pattern ) {

    vector<ull> H(text.size()- pattern.size() +1);
    string s = text.substr(text.size()-pattern.size() , pattern.size());
    H[text.size()-pattern.size()] = poly_hash_func(s);
    ull y = 1;
    for(size_t  i = 1 ; i <= pattern.size(); i++) {
        y = (x*y) % prime;
    }
    for(int i = static_cast< int >( text.size() - pattern.size() - 1 ) ; i>= 0; i--) {
        H[i] = ((x*H[i+1] + text[i] - (y * text[i+pattern.size()] %prime) ) + prime ) % prime;
    }
    return H;
}
struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    std::vector<int> ans;
    for (size_t i = 0; i + s.size() <= t.size(); ++i)
        if (t.substr(i, s.size()) == s)
            ans.push_back(i);
    return ans;
}


vector<int> get_occurrences_fast(const Data& input) {
    const string& s = input.pattern, t = input.text;
      unsigned long long pHash = poly_hash_func(s);
    auto H = precompute_hashes(t,s);
    vector<int> ans;
    for (size_t  i = 0; i + s.size() <= t.size(); ++i) {
        if (pHash != H[i]) {
            continue;
        }
        if (t.substr(i, s.size()) == s){
            ans.push_back(i);
        }
    }
    return ans;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences_fast(read_input()));
    return 0;
}
