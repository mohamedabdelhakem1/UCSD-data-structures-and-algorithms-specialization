#include <bits/stdc++.h>
using namespace std;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int n = stops.size();
    int minn = 0;
    if(tank >= dist){
        return 0;
    }
    int t = tank;
    stops.push_back(dist);
    for(int i = 0 ; i < n ; i++) {
        if(i == 0){
              t = t - stops [i];
        }else{
            t = t - (stops[i]-stops[i-1]);
        }
        if(stops[i+1] - stops[i] > tank){
            return -1;
        }
        if(stops[i+1] - stops[i] > t){
            t = tank;
            minn++;
        }
    }
    return minn;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
