#include <bits/stdc++.h>
using namespace std;

void PreprocessBWT(vector <char> &sorted, string& bwt,unordered_map<char, int>& first_occ,
                   unordered_map<char, vector<int> >& countt) {
    int n =  bwt.size();
    for(int i =  0 ; i < n ; i++)
        sorted[i] = bwt[i];
    sort(sorted.begin(), sorted.end());
    for(int i = 0; i < n; i++) {
        if(first_occ.find(sorted[i]) == first_occ.end()) {
            first_occ[sorted[i]] = i;
        }
    }
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
}

int CountOccurrences( vector <char> sorted,
                      string& pattern,
                      string& bwt,
                      unordered_map<char, int>& first_occ,
                      unordered_map<char, vector<int> >& countt) {
    int top = 0;
    int bottom = bwt.size() - 1;
    int it = pattern.size() - 1;
    while(top  <= bottom) {
        if(top < 0 || bottom < 0  || top+1 > bwt.size()  || bottom+1 > bwt.size())
            return 0;
        if(it >=0) {
            char sym = pattern[it];
            it--;
            if(first_occ.find(sym)== first_occ.end()) {
                return 0;
            }
            top =  first_occ[sym] + countt[sym][top];
            bottom =  first_occ[sym] + countt[sym][bottom + 1] - 1;
        } else {
            return bottom - top + 1;
        }
    }
    return 0;
}


int main() {
    string bwt;
    cin >> bwt;
    int pattern_count;
    cin >> pattern_count;

    int siz =  bwt.size();
    unordered_map<char, int> first_occ;
    unordered_map<char, vector<int> > countt;
    vector <char> sorted(siz);

    PreprocessBWT(sorted,bwt, first_occ, countt);
    for (int pi = 0; pi < pattern_count; ++pi) {
        string pattern;
        cin >> pattern;
        int occ_count = CountOccurrences(sorted, pattern, bwt, first_occ, countt);
        printf("%d ", occ_count);
    }
    printf("\n");
    return 0;
}
