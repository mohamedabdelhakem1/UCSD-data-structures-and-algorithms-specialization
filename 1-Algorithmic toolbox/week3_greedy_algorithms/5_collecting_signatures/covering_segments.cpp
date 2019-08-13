#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
    int start, end;
};
bool _compare(Segment s1, Segment s2) {
    if(s1.end < s2.end) {
        return true;
    } else if(s1.end >= s2.end) {
        return false;
    }
}
vector<int> optimal_points(vector<Segment> &segments) {
    vector<int> points;
    sort(segments.begin(), segments.end(),_compare);
    points.push_back(segments[0].end);
    for (size_t i = 1; i < segments.size(); ++i) {
        if(points[points.size()-1] < segments[i].start){
            points.push_back(segments[i].end);
        }
    }
    return points;
}

int main() {
    int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
}
