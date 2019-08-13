#include <bits/stdc++.h>
using namespace std;

string InverseBWT(string& bwt) {
    string text = "";
    // last to first property
    int n =  bwt.size();
    char sorted[n] ;
    for(int i =  0 ; i < n ; i++)
        sorted[i] = bwt[i];
    sort(sorted, sorted + n);
    unordered_map <char,int> first_occ;
    for(int i = 0; i < n; i++) {
        if(first_occ.find(sorted[i]) == first_occ.end()) {
            first_occ[sorted[i]] = i;
        }
    }
    unordered_map <char,vector<int>> countt;
    for(int i = 0; i < n; i++) {
        if(countt.find(bwt[i]) == countt.end()) {
            countt[bwt[i]].push_back(0);
        }
    }
    for(int i = 0 ; i < n ; i++ ) {
        countt[bwt[i]].push_back(countt[bwt[i]].back()+1);
        for(auto it  = countt.begin() ; it != countt.end() ; it++)
            if(it->first != bwt[i]) {
                countt[it->first].push_back(countt[it->first].back());
            }
    }
    int pointer = 0;
    for(int i= 0; i <n; i++) {
        text += sorted[pointer];
        pointer = first_occ[bwt[pointer]] + countt[bwt[pointer]][pointer];
    }
    reverse(text.begin() , text.end());
    return text;
}

int main() {
    string bwt;
    cin >> bwt;
    cout << InverseBWT(bwt) << endl;
    return 0;
}
