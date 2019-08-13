#include <bits/stdc++.h>
using namespace std;

double get_optimal_value(int capacity, vector<pair<double,int> > v_w) {
    double value = 0.0;
    int n = v_w.size();
    sort(v_w.begin(), v_w.end());
    for(int i = n-1 ; i >=0  ; i-- ) {
        double v = v_w[i].first;
        int w = v_w[i].second;
        if(w < capacity){
            value += (v * w);
            capacity -= w;
        }else{
            value = value +  (v * capacity);
            break;
        }
    }
    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<pair <  double,int > > values_weights(n);
    for (int i = 0; i < n; i++) {
        int v,w;
        cin >> v >> w;
        values_weights[i].first = (double)v/(double)w;
        values_weights[i].second = w;
    }
    double optimal_value = get_optimal_value(capacity, values_weights);
    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}
