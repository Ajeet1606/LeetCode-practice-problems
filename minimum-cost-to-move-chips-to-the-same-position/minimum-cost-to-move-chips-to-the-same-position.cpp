class Solution {
public:
    int minCostToMoveChips(vector<int>& pos) {
        int odd = 0, even = 0;
        for(int i = 0; i < pos.size(); i++){
            if(pos[i]&1) odd++;
            else even++;
        }
        return min(odd, even);
    }
};