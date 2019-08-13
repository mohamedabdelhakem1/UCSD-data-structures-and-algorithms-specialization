#include <bits/stdc++.h>
using namespace std;
struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    vector<string> elems;
    unordered_map <size_t, vector <string> > hashTab;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {}

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        if (query.type == "check") {
            vector <string >elements = hashTab[query.ind];
            for(int i = 0 ; i < elements.size() ; i++) {
                cout << elements[i] <<" ";
            }
            cout<<endl;
        } else {
            string str = query.s;
            size_t hsh =  hash_func(str);
            vector <string >elements = hashTab[hsh];
            if (query.type == "find") {
                for(int i = 0 ; i < elements.size() ; i++) {
                    if(str == elements[i]) {
                        cout<<"yes"<<endl;
                        return;
                    }
                }
                cout<<"no"<<endl;
                return;
            } else if (query.type == "add") {
                string str = query.s;
                size_t hsh =  hash_func(str);
                vector <string >elements = hashTab[hsh];
                for(int i = 0 ; i < elements.size() ; i++) {
                    if(query.s == elements[i]) {
                        return;
                    }
                }
                hashTab[hsh].insert(hashTab[hsh].begin(),query.s);
            } else if (query.type == "del") {
                string str = query.s;
                size_t hsh =  hash_func(str);
                vector <string >elements = hashTab[hsh];
                for(auto i = elements.begin() ; i != elements.end() ; i++) {
                    if(str == *i) {
                        elements.erase(i);
                        hashTab[hsh] = elements;
                        return;
                    }
                }

            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
