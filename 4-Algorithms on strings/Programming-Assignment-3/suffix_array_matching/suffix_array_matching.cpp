#include <bits/stdc++.h>
using namespace std;
vector <int > sort_char(string text) {
    int n = text.size();
    vector <int> order(n);
    map<char, int> countt;

    for(int i = 0 ; i < n ; i++) {
        if(countt.find(text[i]) != countt.end()) {
            countt[text[i]]++;
        } else {
            countt[text[i]] = 1;
        }
    }
    auto i = countt.begin();
    auto prev = i;
    i++;
    for( ; i !=  countt.end(); i++) {
        countt[i->first] = countt[i->first] + countt[prev->first];
        prev = i;
    }
    for(int i = n-1 ; i >= 0 ; i--) {
        char c = text[i];
        countt[c]--;
        order[countt[c]] = i;
    }
    return order;
}
vector <int>compute_classes (string text, vector< int> order ) {
    int n =  text.size();
    vector <int>classes (n);
    classes[order[0]] = 0;

    for(int i = 1; i < n ; i++) {
        if(text[order[i]] != text[order[i-1]]) {
            classes[order[i]] =  classes[order[i-1]] + 1;
        } else {
            classes[order[i]] = classes[order[i-1]];
        }
    }
    return classes;
}
vector <int> sort_doubled(int L,string text,vector <int> order, vector<int> classes) {
    int n = text.size();
    vector <int> countt(n,0);
    vector <int> new_order (n);
    for(int i = 0; i <n; i++) {
        countt[classes[i]]++;
    }

    for(int i = 1; i <n; i++) {
        countt[i] +=  countt[i-1] ;
    }
    for(int i = n-1 ; i >=0 ; i--) {
        int start = (order[i] - L + n ) % n;
        int cl = classes[start];
        countt[cl]--;
        new_order[countt[cl]] = start;
    }
    return new_order;
}
vector <int> update_classes (int L, vector< int> new_order,vector <int >classes) {
    int n =  new_order.size();
    vector <int>new_classes (n);
    new_classes[new_order[0]] = 0;
    for(int i = 1 ; i < n ; i++) {
        int cur = new_order[i];
        int prev = new_order[i-1];
        int mid_cur = (cur+L) % n;
        int mid_prev = (prev+L) % n;
        if(classes[cur] != classes[prev] || classes[mid_cur] != classes[mid_prev]) {
            new_classes[cur] = new_classes[prev]+1;
        } else {
            new_classes[cur] = new_classes[prev];
        }
    }

    return new_classes;
}
vector<int> BuildSuffixArray(const string& text) {
    vector<int > order = sort_char(text);
    vector <int> classes = compute_classes( text,order);
    int L = 1;
    while(L < text.size()) {
        order = sort_doubled(L,text,order,classes);
        classes = update_classes(L,order,classes);
        L = 2*L;
    }
    return order;
}
vector<int> FindOccurrences(const string& pattern, const string& text, const vector<int>& suffix_array) {
    vector<int> result;
    int n = suffix_array.size();
    int minn = 0;
    int maxx = text.size();
    while(minn < maxx) {
        int mid = ( minn + maxx ) /2;
        if(mid == n) {
            return result;
        }
        if(pattern > text.substr(suffix_array[mid] ,pattern.size() )) {
            minn = mid+1;
        } else {
            maxx = mid;
        }
    }
    int start =  minn;
    maxx = text.size();
    while(minn < maxx) {
        int mid = ( minn + maxx ) /2;
        if(mid == n) {
            maxx = n;
            break;
        }
        if(pattern < text.substr(suffix_array[mid] , pattern.size() )) {
            maxx = mid;
        } else {
            minn = mid + 1 ;
        }
    }
    int endd  = maxx;
    if(start > endd) {
    } else {
        for(int i = start ; i < endd ; i++) {
            result.push_back(suffix_array[i]);
        }
    }
    return result;
}

int main() {
    char buffer[100001];
    scanf("%s", buffer);
    string text = buffer;
    text += '$';
    vector<int> suffix_array = BuildSuffixArray(text);
    int pattern_count;
    scanf("%d", &pattern_count);
    vector<bool> occurs(text.length(), false);
    for (int pattern_index = 0; pattern_index < pattern_count; ++pattern_index) {
        scanf("%s", buffer);
        string pattern = buffer;
        vector<int> occurrences = FindOccurrences(pattern, text, suffix_array);
        for (int j = 0; j < occurrences.size(); ++j) {
            occurs[occurrences[j]] = true;
        }
    }
    for (int i = 0; i < occurs.size(); ++i) {
        if (occurs[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
