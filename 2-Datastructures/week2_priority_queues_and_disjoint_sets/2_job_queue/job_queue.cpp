#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pi;
class JobQueue {
private:
    int num_workers_;
    vector<int> jobs_;
    vector<int> assigned_workers_;
    vector<long long> start_times_;

    void WriteResponse() const {
        for (int i = 0; i < jobs_.size(); ++i) {
            cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
        }
    }

    void ReadData() {
        int m;
        cin >> num_workers_ >> m;
        jobs_.resize(m);
        for(int i = 0; i < m; ++i)
            cin >> jobs_[i];
    }

    void AssignJobs() {
        // TODO: replace this code with a faster algorithm.
        assigned_workers_.resize(jobs_.size());
        start_times_.resize(jobs_.size());
        vector<long long> next_free_time(num_workers_, 0);
        for (int i = 0; i < jobs_.size(); ++i) {
            int duration = jobs_[i];
            int next_worker = 0;
            for (int j = 0; j < num_workers_; ++j) {
                if (next_free_time[j] < next_free_time[next_worker])
                    next_worker = j;
            }
            assigned_workers_[i] = next_worker;
            start_times_[i] = next_free_time[next_worker];
            next_free_time[next_worker] += duration;
        }
    }
    struct cmp {
        bool operator()(pi p1, pi p2) {
            if(p1.first != p2.first){
                return  p1.first > p2.first ;
            }
            return p1.second > p2.second;
        }
    };

    void AssignJobs_fast() {
        // TODO: replace this code with a faster algorithm.
        assigned_workers_.resize(jobs_.size());
        start_times_.resize(jobs_.size());
        priority_queue<pi, vector<pi>, cmp> min_heap;
        for (int j = 0; j < num_workers_; ++j) {
            min_heap.push(make_pair(0,j));
        }
        for (int i = 0; i < jobs_.size(); ++i) {
            int duration = jobs_[i];
            pair <long long, long long> nw = min_heap.top();
            min_heap.pop();
            assigned_workers_[i] = nw.second;
            start_times_[i] = nw.first;
            long long next = nw.first + duration;
            min_heap.push(make_pair(next, nw.second));
        }
    }
public:
    void Solve() {
        ReadData();
        AssignJobs_fast();
        WriteResponse();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    JobQueue job_queue;
    job_queue.Solve();
    return 0;
}
