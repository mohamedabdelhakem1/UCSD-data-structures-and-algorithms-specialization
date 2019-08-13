#include <bits/stdc++.h>
using  namespace std;

class StackWithMax {
    vector <int> s;
    stack <int> track_stack;
  public:
    void Push(int value) {
        s.push_back(value);
        if(track_stack.empty()){
         track_stack.push(value);
        }else if(value > track_stack.top()){
            track_stack.push(value);
        }else{
            track_stack.push(track_stack.top());
        }
    }
    void Pop() {
        assert(s.size());
        s.pop_back();
        track_stack.pop();
    }
    int Max() const {
        assert(s.size());
        return track_stack.top();
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        } else if (query == "pop") {
            stack.Pop();
        } else if (query == "max") {
            cout << stack.Max() << "\n";
        } else {
            assert(0);
        }
    }
    return 0;
}
