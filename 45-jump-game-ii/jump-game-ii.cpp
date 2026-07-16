class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int jumps = 0;
        while(r < nums.size()-1){
            int farthest = 0;
            for(int index = l; index <= r; index++){
                farthest = max(index + nums[index], farthest);
            }
            l = r+1;
            r = farthest;
            jumps += 1;
        }
        return jumps;
    }
};