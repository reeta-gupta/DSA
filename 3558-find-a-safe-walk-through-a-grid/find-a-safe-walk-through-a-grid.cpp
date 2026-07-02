class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> minCost(m, vector<int>(n,INT_MAX));
        deque<pair<int,int>> dq;

        minCost[0][0] = grid[0][0];
        dq.push_front({0,0});
        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        while(!dq.empty()){
            auto it = dq.front();
            dq.pop_front();

            int row = it.first;
            int col = it.second;
            if(row == m-1 && col == n-1){
                return minCost[row][col] < health;
            }

            for(int i = 0; i < 4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    int cost = grid[nr][nc];
                    if(minCost[row][col] + cost < minCost[nr][nc]){

                        minCost[nr][nc] = minCost[row][col] + cost;

                        if(cost==0)
                            dq.push_front({nr,nc});
                        else
                            dq.push_back({nr,nc});
                    }
                }
            }
        }
        return minCost[m-1][n-1] < health;

    }
};