#include <bits/stdc++.h>
using namespace std;
typedef pair<double, pair<int,int> > pi;
struct DisjointSetElement {
    int rank;
    int parent;
    int node;
    DisjointSetElement(int node = 0, int parent = -1, int rank = 0):
        node(node), parent(parent), rank(rank) {}
};
unordered_map < int, DisjointSetElement> DisjointSets;

void make_set(int num) {
    DisjointSetElement e(num,num,0);
    DisjointSets[num] = e;
}

int find_set(int node) { // path compression heuristic
    if(DisjointSets[node].parent != node) {
        DisjointSets[node].parent = find_set(DisjointSets[node].parent);
    }
    return DisjointSets[node].parent;
}
void union_sets( int node1,int node2) {
    int set1 = find_set(node1);
    int set2 = find_set(node2);
    if(set1 != set2)
        if(DisjointSets[set1].rank  > DisjointSets[set2].rank) {
            DisjointSets[set2].parent = set1;
        } else {
            DisjointSets[set1].parent = set2;
            if(DisjointSets[set1].rank == DisjointSets[set2].rank) {
                DisjointSets[set2].rank += 1;
            }
        }
}
double compute_dist(int x1, int x2,int y1,int y2) {
    int dx = x1 - x2;
    int dy = y1 - y2;
    return sqrt(dx*dx + dy*dy);
}


double clustering(vector<int> x, vector<int> y, int k) {
    int n = x.size();
    set< pi > distances;
    for(int i = 0 ; i < n ; i++) {
        for(int j = i+1 ; j < n ; j++) {
            distances.insert(make_pair(compute_dist(x[i],x[j], y[i], y[j]), make_pair(i,j) ));
        }
    }

    for(int i = 0 ; i < n ; i++) {
        make_set(i);
    }
    double minn = DBL_MAX ;
    int set_number = n;
    auto it = distances.begin();
    for( it = distances.begin() ;  set_number > k && it !=  distances.end() ; it++) {
        double dist  = it->first;
        int node1 = it->second.first;
        int node2 = it->second.second;
        if(find_set(node1) != find_set(node2)) {
            union_sets(node1,node2);
            set_number--;
        }
    }
    for(auto  i = it; i !=  distances.end() ; i++) {
        double dist  = i->first;
        int node1 = i->second.first;
        int node2 = i->second.second;
        if(find_set(node1) != find_set(node2)) {
            if(dist < minn) {
                minn = dist;
                break;
            }
        }
    }
    return minn;
}

int main() {
    size_t n;
    int k;
    std::cin >> n;
    vector<int> x(n), y(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    std::cin >> k;
    std::cout << std::setprecision(13) << clustering(x, y, k) << std::endl;
}
