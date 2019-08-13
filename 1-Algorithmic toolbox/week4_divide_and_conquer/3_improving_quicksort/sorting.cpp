#include <bits/stdc++.h>
using namespace std;
int part;
int partition2(vector<int> &a, int l, int r) {
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}

int partition3(vector<int> &a, int low, int high) {
    int x = a[low];
  //  cout<<x<<endl;
    int j = low ;
    int countt = low;
    for (int i = low+1; i <= high; i++) {
        if (a[i] < x) {
            j++;
            countt++;
            swap(a[i], a[j]);
            swap(a[j],a[countt]);
        } else if (a[i] == x) {
            j++;
            part++;
            swap(a[i], a[j]);

        }
    }
    if(x ==  a[j]) {
        swap(a[low],a[countt]);
    } else {
        swap(a[low], a[j]);
    }
    return j ;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }
    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    part = 0;
    int m = partition3(a, l, r);
    randomized_quick_sort(a, l, m - part - 1);
    randomized_quick_sort(a, m + 1, r);
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        cin>>a[i] ;
    }
    randomized_quick_sort(a, 0, a.size() - 1);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
    cout<<"\n";

}
