class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();
        int mod = 1e9 + 7;

        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        // Base Case
        score[n-1][n-1] = 0;
        ways[n-1][n-1] = 1;

        for(int i = n-1; i >= 0; i--){

            for(int j = n - 1; j >= 0; j--){

                if(board[i][j] == 'X')
                    continue;

                if(i == n - 1 && j == n - 1)
                    continue;

                // Check Down
                if(i + 1 < n && ways[i + 1][j] > 0){

                    if(score[i + 1][j] > score[i][j]){
                        score[i][j] = score[i + 1][j];
                        ways[i][j] = ways[i + 1][j];
                    }
                    else if(score[i + 1][j] == score[i][j]){
                        ways[i][j] = (ways[i][j] + ways[i + 1][j]) % mod;
                    }
                }

                // Check Right
                if(j + 1 < n && ways[i][j + 1] > 0){

                    if(score[i][j + 1] > score[i][j]){
                        score[i][j] = score[i][j + 1];
                        ways[i][j] = ways[i][j + 1];
                    }
                    else if(score[i][j + 1] == score[i][j]){
                        ways[i][j] = (ways[i][j] + ways[i][j + 1]) % mod;
                    }
                }

                // Check Diagonal
                if(i + 1 < n && j + 1 < n && ways[i + 1][j + 1] > 0){

                    if(score[i + 1][j + 1] > score[i][j]){
                        score[i][j] = score[i + 1][j + 1];
                        ways[i][j] = ways[i + 1][j + 1];
                    }
                    else if(score[i + 1][j + 1] == score[i][j]){
                        ways[i][j] = (ways[i][j] + ways[i + 1][j + 1]) % mod;
                    }
                }

                if(ways[i][j] == 0)
                    continue;

                if(board[i][j] != 'S' && board[i][j] != 'E'){
                    score[i][j] += board[i][j] - '0';
                }
            }
        }

        if(ways[0][0] == 0)
            return {0, 0};

        return {score[0][0], ways[0][0]};
    }
};