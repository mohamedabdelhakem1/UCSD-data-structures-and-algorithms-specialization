#include <bits/stdc++.h>
using namespace std;


int main() {
    string text;
    getline(cin, text);
    stack <char> st;
    stack<int> index;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];
        if (next == '(' || next == '[' || next == '{') {
            st.push(text[position]);
            index.push(position);
        } else if ( next == '}'||  next == ')'|| next == ']') {
            if(st.empty()) {
                cout<<(position+1);
                return 0;
            }
            char c = st.top();
            int in = index.top();
            if(c == '(' && next == ')') {
                st.pop();
                index.pop();
            } else if(c == '{' && next == '}') {
                st.pop();
                index.pop();
            } else if(c == '[' && next == ']') {
                st.pop();
                index.pop();
            } else {
                cout<<(position+1);
                return 0;
            }
        }
    }
    while(!st.empty()) {
        int i = index.top();
        index.pop();
        st.pop();
        if(st.empty()) {
            cout<<i+1;
            return 0;
        }
    }
    cout<<"Success";
    return 0;
}
