class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        int n = arr.size();
        
        int actual_sum = n*(n+1)/2;
        int curr_sum = accumulate(arr.begin(), arr.end(), 0);
        int duplicate;
        unordered_set<int>s;
        for(auto a: arr){
            if(s.count(a) != 0){
                duplicate = a;
                break;
            }
            else
                s.insert(a);
        }
        
        return {duplicate, actual_sum - curr_sum + duplicate};
    }
};