#include <bits/stdc++.h>
using namespace std;

void max_sliding_window_naive(vector<int> const & A, int w) {
    for (size_t i = 0; i < A.size() - w + 1; ++i) {
        int window_max = A.at(i);
        for (size_t j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A.at(j));

        cout << window_max << " ";
    }

    return;
}
void maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    for (int i=0; i<nums.size(); i++) {
        if (!dq.empty() && dq.front() == i-k)
            dq.pop_front();
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        dq.push_back(i);
        if (i>=k-1) {
            cout<<nums[dq.front()]<<" ";
        }
    }
}
//
//vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//    deque <int> dq;
//    vector <int>sol;
//    for (size_t i = 0; i < nums.size() ; ++i) {
//        if(dq.empty()) {
//            dq.push_back(i);
//        } else {
//            int backk = dq.back();
//            while(nums[backk] < nums[i]) {
//                dq.pop_back();
//                if(dq.empty())
//                    break;
//                backk = dq.back();
//            }
//            if(dq.size() != 0 &&i>=k-1 &&dq.front() < i-k+1)
//                dq.pop_front();
//            if(dq.size() == k) {
//                dq.pop_front();
//            }
//            dq.push_back(i);
//        }
//        if(i >= k-1 ) {
//            sol.push_back( nums[dq.front()]);
//          cout<<nums[dq.front()]<<" ";
//         }
//    }
//    return sol;
//}

int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    maxSlidingWindow(A, w);

    return 0;
}
