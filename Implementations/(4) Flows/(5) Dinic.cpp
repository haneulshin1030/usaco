/**
* Source: GeeksForGeeks
*/
 
struct Edge {
    int v, flow, C, rev;
};
 
template<int SZ> struct Dinic {
    int level[SZ], start[SZ];
    vector<Edge> adj[SZ]; 
     
    void addEdge(int u, int v, int C) {
        Edge a{v, 0, C, sz(adj[v])};
        Edge b{u, 0, 0, sz(adj[u])};
        adj[u].pb(a), adj[v].pb(b); 
    } 
     
    bool BFS(int s, int t) {
        F0R(i,SZ) level[i] = -1;
        level[s] = 0;  
      
        queue<int> q; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto e: adj[u]) 
                if (level[e.v] < 0  && e.flow < e.C) {
                    level[e.v] = level[u] + 1;
                    q.push(e.v);
                }
        }
     
        return level[t] >= 0;
    }
      
    int sendFlow(int u, int flow, int t) {
        if (u == t) return flow;
      
        for (  ; start[u] < adj[u].size(); start[u] ++) {
            Edge &e = adj[u][start[u]]; 
                                          
            if (level[e.v] == level[u]+1 && e.flow < e.C) {
                int curr_flow = min(flow, e.C - e.flow);
                int temp_flow = sendFlow(e.v, curr_flow, t);
    
                if (temp_flow > 0) {
                    e.flow += temp_flow;
                    adj[e.v][e.rev].flow -= temp_flow;
                    return temp_flow;
                }
            }
        }
      
        return 0;
    }
     
    int maxFlow(int s, int t) {
        if (s == t) return -1;
        int total = 0;  
      
        while (BFS(s, t)) {
            F0R(i,SZ) start[i] = 0;
            while (int flow = sendFlow(s, INT_MAX, t)) total += flow;
        }
     
        return total;
    } 
};