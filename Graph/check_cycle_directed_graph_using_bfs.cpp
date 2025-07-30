
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

// This uses Kahn's algorithm to find topologically sorted order of vertices
// in a DAG (Directed Acyclic Graph). Note that when the graph is actually
// cyclic, the order will not have the nodes which are present in the graph's
// cycle. 

bool check_cycle_directed_graph_using_bfs(int n, vector < vector <int> > &edges) {

    vector <int> indegree(n, 0);
    for(vector <int> &sinks : edges) {
      for(int &sink : sinks)
        indegree[sink]++;
    }

    queue <int> q;
    for(int i = 0 ; i < n ; i++) {
        if(indegree[i] == 0) {
          q.push(i);
          cout << i << endl;
        } 
    }

    vector <int> order;
    vector <bool> vis(n, false);

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        vis[x] = true;
        order.push_back(x);

        for(int &to : edges[x]) {
            if(vis[to]) continue;

            --indegree[to];
            if(indegree[to] == 0) {
                q.push(to);
            }
        }
    }

    if(order.size() < n)
        return true;

    return false;
}


int32_t main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    
    int n = 5;
    vector < vector <int> > edges = {{1}, {2}, {3}, {0}, {0}};
    cout << check_cycle_directed_graph_using_bfs(n, edges) << endl;
    return 0;
}

