class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int sumLeft = 0;
        int sumRight = 0;
        int leftqnMarkCount = 0;
        int rightqnMarkCount = 0;

        for(int i = 0; i < n; i++){
            if(num[i] == '?'){
                if(i < n/2){
                    leftqnMarkCount++;
                }
                else {
                    rightqnMarkCount++;
                }
            }
            else{
                if(i < n/2){
                    sumLeft += num[i] - '0';
                }
                else{
                    sumRight += num[i] - '0';
                }
            }
        }
        int totalQuestionMarkCount = leftqnMarkCount + rightqnMarkCount;
        if(totalQuestionMarkCount % 2 == 1) return true;

        int leftt = 2*sumLeft + 9*leftqnMarkCount;
        int rightt = 2*sumRight + 9*rightqnMarkCount;

        if(leftt == rightt) return false;
        else return true;

    }
};