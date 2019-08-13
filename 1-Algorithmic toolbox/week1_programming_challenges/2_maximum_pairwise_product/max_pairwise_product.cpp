#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MaxPairwiseProduct(string path) {
    ll max1 = INT_MIN;
    ll max2 = INT_MIN;

    string line;
    ifstream myfile ("in.txt");
    int index;
    if (myfile.is_open()) {
        int i = 0;
        while ( getline (myfile,line) ) {
            int n = stoi(line);
            if(n > max1) {
                max1 = n;
                index = i;
            }
            i++;
        }
        myfile.close();
    }
    ifstream myfile2 ("in.txt");
    if (myfile2.is_open()) {
        int i = 0;
        while ( getline (myfile2,line) ) {
            int n = stoi(line);
            if(n > max2 && i != index) {
                max2 = n;
            }
            i++;
        }
        myfile2.close();
    }
    return max1 * max2;
}

int main() {
    ll n;
    cin >> n;
    ofstream myfile;
    myfile.open ("in.txt");
    ll num;
    for (ll i = 0; i < n; ++i) {
        cin >> num;
        myfile << num<<endl;
    }
    cout<<MaxPairwiseProduct("in.txt");
    return 0;
}
