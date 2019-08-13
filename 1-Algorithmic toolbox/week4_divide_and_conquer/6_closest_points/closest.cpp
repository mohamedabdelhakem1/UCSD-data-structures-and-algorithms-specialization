#include <bits/stdc++.h>
using namespace std;
bool _compareY(pair <int,int>p1, pair<int,int> p2) {
    return (p1.second < p2.second);
}
bool _compareX(pair <int,int>p1, pair<int,int> p2) {
    return (p1.first < p2.first);
}
double dist(pair <int, int> p1, pair < int,int > p2) {
    double dx = abs(p1.first - p2.first);
    double dy = abs(p1.second - p2.second);
    return sqrt(dx * dx  + dy * dy);
}
double brute_force(vector<pair <int,int> > points, int l,int r) {
    double d = INT_MAX;
    for(int i = l ; i <= r; i++) {
        for(int j = i + 1 ; j <= r; j++) {
            double distance = dist(points[i], points[j]);
            d = (distance < d ) ? distance : d;
        }
    }
    return d;
}
double minimal_distance(vector<pair <int,int> > points,vector<pair <int,int> > points_y,int l,int r ) {
    if (l-r <= 3)
        return brute_force(points, l,r);
    if(l < r) {
        int mid =  (l+r) / 2;
        double dist_l = minimal_distance(points,points_y, l, mid);
        double dist_r = minimal_distance(points,points_y, mid + 1, r);
        double d = (dist_r < dist_l) ? dist_r : dist_l;
        vector <pair <int,int>> d_points ;

        double dl = points[mid].first - d;
        double dr = points[mid].first + d;
        for(pair <int,int > p : points_y) {
            if( dl < p.first && p.first < dr) {
                d_points.push_back(p);
            } else {
                break;
            }
        }
        int siz =  d_points.size();
        for(int i = 0 ; i < siz - 1 ; i++) {
            for(int j = i+1 ; j =< min(i+7,siz-1) && abs(d_points[j].second - d_points[i].second) < d; j++) {
                double distance = dist(d_points[i], d_points[j]);
                d = (distance < d) ? distance : d;
            }
        }
        return d;
    }
}


int main() {
    size_t n;
    std::cin >> n;
    vector<pair <int,int> > points(n);
    vector<pair <int,int> > points_y(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> points[i].first >> points[i].second;
        points_y[i].first = points[i].first ;
        points_y[i].second = points[i].second ;
    }

    sort(points.begin(), points.end(), _compareX) ;
    sort(points_y.begin(), points_y.end(), _compareY) ;
    std::cout << std::fixed;
    std::cout << std::setprecision(9) << minimal_distance(points,points_y, 0, points.size() - 1 ) << "\n";
}
