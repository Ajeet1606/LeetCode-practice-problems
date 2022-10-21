class Solution {
public: //we maintain a set of size k.
    bool containsNearbyDuplicate(vector<int>& arr, int k) {
        unordered_set<int>s;
        if(k >= arr.size()) k = arr.size()-1;

        for(int i=0; i<arr.size(); i++){
            if(i > k) s.erase(arr[i - k -1]);
            if(s.count(arr[i]) != 0) return true;
            s.insert(arr[i]);
        }

        return false;
    }
};