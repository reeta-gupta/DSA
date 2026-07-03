class Solution {
public:
    int n;
    vector<vector<pair<int,int>>> adj;
    vector<int> indegree;
    vector<int> topo;

    bool check(int mid, vector<bool>& online, long long k){

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        for(int u : topo){

            if(dist[u] == LLONG_MAX)
                continue;

            if(u != 0 && u != n-1 && !online[u])
                continue;

            for(auto &[v,cost] : adj[u]){

                if(cost < mid)
                    continue;

                if(v != n-1 && !online[v])
                    continue;

                if(dist[u] + cost < dist[v]){
                    dist[v] = dist[u] + cost;
                }
            }
        }

        return dist[n-1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        n = online.size();

        adj.assign(n,{});
        indegree.assign(n,0);

        int high = 0;

        // Build graph
        for(auto &e : edges){

            int u = e[0];
            int v = e[1];
            int cost = e[2];

            adj[u].push_back({v,cost});
            indegree[v]++;

            high = max(high,cost);
        }

        // Topological Sort
        queue<int> q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
        }

        while(!q.empty()){

            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto &it : adj[node]){

                indegree[it.first]--;

                if(indegree[it.first]==0)
                    q.push(it.first);
            }
        }

        int low = 0;
        int ans = -1;

        while(low <= high){

            int mid = low + (high-low)/2;

            if(check(mid,online,k)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
};