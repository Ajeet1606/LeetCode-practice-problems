class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        
        int my_num = 1, cur_idx = 0;

        while(k > 0){
            if((cur_idx >= n) or (my_num != arr[cur_idx])){
                k--;
            }else{
                cur_idx++;
            }
            my_num++;
        }
        
        return my_num-1;
    }
};