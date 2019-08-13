#include <bits/stdc++.h>
using namespace std;
/**
trivial
*/
int get_majority_element_O_N_2(vector<int> &a, int left, int right) {
    //2 nested for loop
}

int find_major(vector<int> &a, int  num, int left, int right) {
    int countt = 0;
    for(int i = left ; i <= right; i++) {
        if(num == a[i]) {
            countt++;
        }
    }
    return countt;
}
/**
div and con
*/
int get_majority_element_O_N_LOGN(vector<int> &a, int left, int right) {
    if(left == right) {
        return a[left];
    }
    int mid = (left + right) / 2;
    int l =  get_majority_element_O_N_LOGN(a,left, mid);
    int r = get_majority_element_O_N_LOGN(a,mid+1,right);
    if(l == r) {
        return l;
    }
    int left_count = find_major(a,l,left,right);
    int right_count = find_major(a,r,left,right);
    return (left_count > right_count) ? l : r ;

}
/**
sorting
*/
int get_majority_element_O_N_LOGN_1(vector<int> &a, int left, int right) {
    sort(a.begin(), a.end());
    int max_occ = 1;
    for(int i = 0 ; i < a.size()-1 ; i++) {
        int c = 1;
        while(a[i] == a[i+1]) {
            c++;
            i++;
        }
        max_occ = max(c,max_occ);
    }
    return (max_occ > (a.size() /2));
}
/**
hashing
*/
int get_majority_element_O_N(vector<int> &a, int left, int right) {
    unordered_map <int, int> mp ;
    int max_occ = 1;
    mp[a[0]] =  1;
    for(int i = 1; i < a.size(); i++) {
        if(mp.find(a[i]) == mp.end()) {
            mp[a[i]] =  1;
        } else {
            mp[a[i]]++;
            if(max_occ < mp[a[i]]) {
                max_occ = mp[a[i]];
            }
        }
    }
    if(max_occ > (a.size() /2) ) {
        return 1;
    } else {
        return 0;
    }

}
/**
Boyer-Moore Voting Algorithm
*/
int get_majority_element_O_N_another_sol(vector<int> &a, int left, int right) {
    int countt = 1;
    int max_index = 0;
    for(int  i = 1 ; i < a.size() ; i++) {
        if(a[max_index] == a[i]) {
            countt++;
        } else {
            countt--;
            if(countt == 0) {
                max_index = i;
                countt++;
            }
        }
    }
    return a[max_index];
}
int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    std::cout <<(find_major( a , get_majority_element_O_N_another_sol(a, 0, a.size()) , 0 , a.size() ) > a.size()/2) << '\n';
}
