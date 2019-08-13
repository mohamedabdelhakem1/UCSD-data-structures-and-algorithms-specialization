#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;


vector<int> BuildSuffixArray(const string& text) {
    vector<int> result;
    vector < pair <string, int>> suffix_arr;
    for(int i = 0; i< text.size() ; i++) {
        string suffix = text.substr(i);
        suffix_arr.push_back(make_pair( suffix,i));
    }
    sort(suffix_arr.begin() , suffix_arr.end() );
    for(int i = 0 ; i < suffix_arr.size() ;i++ ){
        result.push_back(suffix_arr[i].second);
    }
    return result;
}

int main() {
    string text;
    cin >> text;
    vector<int> suffix_array = BuildSuffixArray(text);
    for (int i = 0; i < suffix_array.size(); ++i) {
        cout << suffix_array[i] << ' ';
    }
    cout << endl;
    return 0;
}
