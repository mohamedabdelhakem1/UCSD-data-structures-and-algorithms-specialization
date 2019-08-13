#include <bits/stdc++.h>
using namespace std;

vector<int> fast_count_segments( vector<pair <int,int > > segments, vector<int> points) {
    vector <pair <int, int> > pairs(segments.size() * 2 + points.size()) ;
    vector<int> cnt (points.size());
    unordered_map <int,vector <int> > mp;
    int i = 0;
    for(pair <int, int > p : segments ) {
        pairs[i] = make_pair(p.first,1);
        i++;
        pairs[i] = make_pair(p.second,3);
        i++;
    }
    int j = 0;
    for(int p : points ) {
        if(mp.find(p) == mp.end()) {
            pairs[i] = make_pair(p, 2);
            i++;
        }
        mp[p].push_back(j);
        j++;
    }
    sort(pairs.begin(), pairs.end());

    int cover = 0;
    for(pair <int, int > p : pairs) {
        if(p.second == 1 ) {
            cover++;
        } else if(p.second == 3) {
            cover--;
        } else {
            vector <int> vec = mp[p.first];
            for(int k : vec) {
                cnt[k] = cover;
            }
        }
    }
    return cnt;

}
vector<int> naive_count_segments(vector<pair <int,int > > segments,  vector<int> points) {
    vector<int> cnt(points.size());
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = 0; j < segments.size(); j++) {
            cnt[i] += (segments[j].first <= points[i] && points[i] <= segments[j].second);
        }
    }
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair <int,int > > segments(n);
    for (size_t i = 0; i < segments.size(); i++) {
        std::cin >> segments[i].first >> segments[i].second;
    }
    vector<int> points(m);
    for (size_t i = 0; i < points.size(); i++) {
        std::cin >> points[i];
    }
    //use fast_count_segments
    vector<int> cnt1 = fast_count_segments(segments, points);
    for (size_t i = 0; i < cnt1.size(); i++) {
        std::cout << cnt1[i] << ' ';
    }

}
