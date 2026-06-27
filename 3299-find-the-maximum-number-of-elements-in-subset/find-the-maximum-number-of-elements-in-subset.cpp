class Solution {
public:
    int maximumLength(vector<int>& nums) {

        map<long long, int> freq;

        // Count frequency of each number
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        int ans = 1;

        // Try every unique number as the starting point
        for (auto it = freq.begin(); it != freq.end(); it++) {

            long long x = it->first;
            int count = 0;

            while (freq.find(x) != freq.end() && freq[x] > 0) {

               
                if (x == 1) {
                    count += freq[x];
                    break;
                }

         
                if (freq[x] >= 2) {
                    count += 2;
                }
  
                else {
                    count += 1;
                    break;
                }

              
                freq[x] = 0;

               
                if (x > 1000000)
                    break;

                
                x = x * x;
            }

            
            if (count % 2 == 0)
                count--;

            ans = max(ans, count);
        }

        return ans;
    }
};