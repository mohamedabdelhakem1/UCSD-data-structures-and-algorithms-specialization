#include <bits/stdc++.h>
using namespace std;

struct Vertex {

    int node;
    Vertex  *parent;
    unordered_map< int, Vertex* > childern;
    int depth;
    Vertex(int node_, Vertex *parent_, int depth_ ) : depth(depth_),node(node_),parent(parent_) {}
    Vertex(const Vertex& v) :node(v.node), parent(v.parent), depth(v.depth) {}
};
struct Edge {
    // The ending node of this edge.
    int source;
    int node;
    // Starting position of the substring of the text
    // corresponding to the label of this edge.
    int start;
    // Position right after the end of the substring of the text
    // corresponding to the label of this edge.
    int end;
    Edge(int source_,int node_, int start_, int end_) :source(source_), node(node_), start(start_), end(end_) {}
    Edge(const Edge& e) :source(e.source), node(e.node), start(e.start), end(e.end) {}
};
//Edge find_edge(vector<Edge> &vec, string text , int index) {
//    int i = 0;
//    for( auto it  = vec.begin() ; it != vec.end()  && i < vec.size();it++) {
//        if(  text[vec[i].start] == text[index]){
//            Edge return_value = vec[i];
//            vec.erase(it);
//            return return_value;
//        }
//        i++;
//    }
//}
map<int, vector<Edge> > SuffixTreeFromSuffixArray(
    const vector<int>& suffix_array,
    const vector<int>& lcp_array,
    const string& text) {

    unordered_map<int, Vertex*> vertices;

    int n = suffix_array.size();
    map<int, vector<Edge> > tree;

    Edge e(0,1, suffix_array [0], n);
    tree[0].push_back(e);

    Vertex* root = new Vertex(0,NULL,0);
    Vertex* child = new Vertex(1,root, n-suffix_array [0]);
    root->childern[1] = child;
    vertices[0] = root;
    vertices[1] = child;

    int c = 2;
    int prev_node = 1;

    for(int i = 1 ; i < n ; i++) {
        if(lcp_array[i-1] == 0) {
            Edge e(0,c, suffix_array [i], n);
            tree[0].push_back(e);

            Vertex* child = new Vertex(c,root, n-suffix_array [i]);
            root->childern[c] = child;
            vertices[c] = child;
            prev_node = c;
            c++;
        } else {
            Vertex* prev = vertices[prev_node];
            while(prev->depth >  lcp_array[i-1]) {
                prev = prev->parent;
            }
            if(prev->depth == lcp_array[i-1]) {
                Edge new_edge(prev->node, c,suffix_array[i] +lcp_array[i-1], n);
                tree[prev->node].push_back(new_edge);
                Vertex* child = new Vertex(c,prev, n - suffix_array [i]);
                prev->childern[c] = child;
                vertices[c] = child;
                prev_node = c;
                c++;
            } else { // prev ->depth < lcp_array[i-1]
                // break edge

               // Edge broken = find_edge(tree[prev->node] ,text , suffix_array[i] + prev->depth); // get the edge to break
                Edge broken = tree[prev->node].back();
                tree[prev->node].pop_back();

                Edge new_edge(broken.source,c, broken.start, broken.start + (lcp_array[i-1] - prev->depth)) ;   // new edge instead of broken
                tree[prev->node].push_back(new_edge); // add the new edge for the same vertex
                Vertex* mid_node = new Vertex(c,prev, lcp_array[i-1]);  // mid vertex of depth of lcp_arry[i-1]

                Vertex* end_node = prev->childern[broken.node]; // get the end node
                prev->childern.erase(broken.node); // erase the end node from childern of parent node
                prev->childern[c] = mid_node; // add the new mid node instead;

                vertices[prev->node] = prev; // update the parent node

                mid_node->childern[broken.node] = end_node; //  add the end node to children of mid node
                Edge second_half(c, broken.node,broken.start + (lcp_array[i-1] - prev->depth), broken.end);
                Edge added_edge (c, c+1, suffix_array[i] +lcp_array[i-1], n);
                tree[c].push_back(second_half);
                tree[c].push_back(added_edge);

                c++;
                Vertex* added_vertex = new Vertex(c,mid_node, n - suffix_array[i]);
                mid_node->childern[c] = added_vertex;

                vertices[c-1] = mid_node; // add the new mid node to hash map
                vertices[c] = added_vertex; // add the new node to hash map
                prev_node = c;
                c++;
            }
        }
    }

    return tree;
}


int main() {
    char buffer[200001];
    scanf("%s", buffer);
    string text = buffer;
    vector<int> suffix_array(text.length());
    for (int i = 0; i < text.length(); ++i) {
        scanf("%d", &suffix_array[i]);
    }
    vector<int> lcp_array(text.length() - 1);
    for (int i = 0; i + 1 < text.length(); ++i) {
        scanf("%d", &lcp_array[i]);
    }
    map<int, vector<Edge> > tree = SuffixTreeFromSuffixArray(suffix_array, lcp_array, text);
    printf("%s\n", buffer);

    vector<pair<int, int> > stack(1, make_pair(0, 0));
    while (!stack.empty()) {
        pair<int, int> p = stack.back();
        stack.pop_back();
        int node = p.first;
        int edge_index = p.second;
        if (!tree.count(node)) {
            continue;
        }
        const vector<Edge>& edges = tree[node];
        if (edge_index + 1 < edges.size()) {
            stack.push_back(make_pair(node, edge_index + 1));
        }
        printf("%d %d\n", edges[edge_index].start, edges[edge_index].end);
        stack.push_back(make_pair(edges[edge_index].node, 0));
    }
    return 0;
}
