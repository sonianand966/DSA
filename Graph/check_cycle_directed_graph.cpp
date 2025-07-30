
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

bool dfs(int x, vector <int> &color, vector < vector <int> > &edges) {
    // turn current state to processing
    color[x] = 1;

    for(int &to : edges[x]) {
        // if the node from current node is also in 
        // 'processing' state, it means we have visited this (in the same component)
        // and are trying to visit again -- meaning a cycle
        if(color[to] == 1) return true;

        // similarly check for child
        if(color[to] == 0 and dfs(to, color, edges))
            return true;
    }

    // finally mark as processed
    color[x] = 2;
    return false;
}

bool check_cycle_directed_graph(int n, vector < vector <int> > &edges) {
    vector <int> color(n, 0);

    for(int i = 0 ; i < n ; i++) {
        if(color[i] == 0 and dfs(i, color, edges))
            return true;
    }      

    return false;
}


int32_t main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    
    int n = 4;
    vector < vector <int> > edges = {{1}, {2}, {3}, {0}};
    cout << check_cycle_directed_graph(n, edges) << endl;
    return 0;
}

