#include <bits/stdc++.h>
#include <string>
#include <string.h>
using namespace std;

string BWT( string& text) {
    string result = "";
    vector <string > mat;
    int n = static_cast <int>(text.size());
    for(int i = 0 ; i < n ; i++) {
        char _last =  text[n-1];
        text = _last + text.substr(0 , n-1) ;
        mat.push_back(text);
    }
    sort(mat.begin() , mat.end());
    for(int i = 0 ; i < n ; i++) {
        result += mat[i][n-1];
    }
    return result;
}

int main() {
    string text;
    cin >> text;
    cout << BWT(text) << endl;
    return 0;
}
