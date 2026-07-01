class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

                if(grid[i][j] == 1){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){

            auto it = q.front();
            q.pop();

            int row = it.first;
            int col = it.second;

            for(auto d : dir){

                int nr = row + d[0];
                int nc = col + d[1];

                if(nr>=0 && nr<n && nc>=0 && nc<n && dist[nr][nc]==-1){

                    dist[nr][nc] = dist[row][col] + 1;
                    q.push({nr,nc});
                }
            }
        }

        priority_queue<vector<int>> pq;

        vector<vector<int>> vis(n, vector<int>(n,0));

        pq.push({dist[0][0],0,0});
        vis[0][0]=1;

        while(!pq.empty()){

            auto cur = pq.top();
            pq.pop();

            int safe = cur[0];
            int row = cur[1];
            int col = cur[2];

            if(row==n-1 && col==n-1)
                return safe;

            for(auto d : dir){

                int nr = row + d[0];
                int nc = col + d[1];

                if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc]){

                    vis[nr][nc]=1;

                    int newSafe = min(safe, dist[nr][nc]);

                    pq.push({newSafe,nr,nc});
                }
            }
        }

        return 0;
    }
};