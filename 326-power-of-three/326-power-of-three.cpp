class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0){
           return false;
        }
        vector<int>arr;
        while(n > 0){
            int rem = n%3;
            arr.push_back(rem);
            n = n/3;
        }
        
        int len = arr.size();
        if(arr[len-1] != 1) return false;
        for(int i=0; i<len-1; i++){
            if(arr[i] != 0)
                return false;
        }
        return true;
    }
};