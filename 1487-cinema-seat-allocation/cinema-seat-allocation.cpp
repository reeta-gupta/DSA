class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int sizee = reservedSeats.size();
        unordered_map<int, set<int>> mp;
        for(auto &it: reservedSeats){
            int row = it[0];
            int seat = it[1];

            mp[row].insert(seat);
        }
        int result = (n-mp.size())*2;
        for(auto &[row, bookedSeats] : mp){

            bool left = !bookedSeats.count(2) && !bookedSeats.count(3) && !bookedSeats.count(4) && !bookedSeats.count(5);
            bool right = !bookedSeats.count(6) && !bookedSeats.count(7) && !bookedSeats.count(8) && !bookedSeats.count(9);
            bool middle = !bookedSeats.count(4) && !bookedSeats.count(5) && !bookedSeats.count(6) && !bookedSeats.count(7);

            if(left && right) result += 2;
            else if(left || right || middle) result += 1;
        }
        return result;
    }
};