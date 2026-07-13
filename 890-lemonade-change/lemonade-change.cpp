#include<bits/stdc++.h>
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> freq;
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5){
                freq[bills[i]]++;
            }
            else if(bills[i] == 10){
                freq[bills[i]]++;
                if(freq[5] > 0){
                    freq[5]--;
                }
                else return false;
            }
            else{
                freq[bills[i]]++;
                if(freq[10] > 0 && freq[5] > 0){
                    freq[10]--;
                    freq[5]--;
                }
                else if(freq[10] == 0 && freq[5] >=3){
                    freq[5] = freq[5]-3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};