#include <bits/stdc++.h>
using namespace std;
int mergee(int a[], int l,int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid ;
    int left[n1];
    int right[n2];
    for(int i = 0 ; i < n1; i++) {
        left[i] = a[l+i];
    }
    for(int i = 0 ; i < n2; i++) {
        right[i] = a[mid+1+i];
    }
    int i=0,j=0,k=0;
    int inv_count = 0;
        while(i< n1 && j < n2) {
        if(left[i] <= right[j]  ) {
            a[l+k] = left[i];
            i++;
        } else {
            a[l+k] = right[j];
            j++;
            inv_count += (n1 - i);
        }
        k++;
    }
    while(i < n1 ) {
        a[l+k] = left[i];
        i++;
        k++;
    }
    while(j < n2 ) {
        a[l+k] = right[j];
        j++;
        k++;
    }
    return inv_count;
}

int merge_sort(int a[], int l, int r) {
    int inv = 0;
    if(l < r) {
        int mid = (l+r) / 2;
         inv = merge_sort(a, l,mid) + merge_sort(a, mid+1, r) + mergee(a,l,mid,r);
    }
    return inv;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout<<merge_sort(a, 0, n- 1) ;



}
