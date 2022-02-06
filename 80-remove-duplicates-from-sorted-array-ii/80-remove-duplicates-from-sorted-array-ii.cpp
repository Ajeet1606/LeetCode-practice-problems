class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int>map;
        for(auto a: arr){
            map[a]++;
        }
        
        int idx = 0, ans = 0;
        for(auto a: map){
            int num = a.first;
            int freq = min(2, a.second);
            for(int i=0; i<freq; i++){
                arr[idx++] = num;
                ans++;
            }
        }
        sort(arr.begin(), arr.begin()+ans);
        return ans;
    }
};