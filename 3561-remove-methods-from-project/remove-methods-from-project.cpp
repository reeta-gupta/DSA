class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;

        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour, adj, visited);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        int x = invocations.size();
        vector<vector<int>> adj(n);
        for(auto &edge : invocations){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        vector<bool> visited(n, false);
        dfs(k, adj, visited);

        for(auto &edge: invocations){
            int u = edge[0];
            int v = edge[1];

            if(!visited[u] && visited[v]){
                vector<int> ans;
                for(int i = 0 ; i < n; i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        vector<int> anss;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                anss.push_back(i);
            }
        }
        return anss;
    }
};