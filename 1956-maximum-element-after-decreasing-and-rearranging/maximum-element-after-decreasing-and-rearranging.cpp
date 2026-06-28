class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 2;
        arr[0] = 1;
        int n = arr.size();
        for(int i =1; i < n; i++){
            if(arr[i] != arr[i-1]){
                arr[i] = ans;
                ans++;
            }
            else{
                arr[i] = ans-1;
            }
        }
        return arr[n-1];
    }
};