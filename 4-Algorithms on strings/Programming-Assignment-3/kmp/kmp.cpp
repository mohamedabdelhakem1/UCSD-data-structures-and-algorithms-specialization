#include <bits/stdc++.h>
using namespace std;
vector<int>compute_prefix_function(string pattern) {
    int n = pattern.size();
    vector <int> prefix(n,0);
    int j = 0;
    for(int i = 1 ; i < n ; i++) {
        while(j > 0 && pattern[i] != pattern[j]) {
            j = prefix[j-1];
        }
        if(pattern[i] == pattern[j]) {
            j++;
        } else {
            j = 0;
        }
        prefix[i] = j;
    }
    return prefix;
}
vector<int> find_pattern(const string& pattern, const string& text) {
    vector<int> result;
    if(pattern.size() > text.size()) {
        return result;
    }
    vector<int>prefix = compute_prefix_function(pattern);
    int siz =  text.size();
    int n = pattern.size();
    int j = 0;
    for(int i = 0 ; i < siz ;) {
        if(text[i] == pattern[j]) {
            j++;
            i++;
        }
        if(j == n) {
            result.push_back(i-j);
            j = prefix[j-1];
        } else if(j < n && text[i] != pattern[j] ) {
            if(j != 0)
                j = prefix[j-1];
            else
                i++;
        }
    }
    return result;
}


int main() {
    string pattern, text;
    cin >> pattern;
    cin >> text;
    vector<int> result = find_pattern(pattern, text);
    for (int i = 0; i < result.size(); ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}
