class Solution {
    
public:
    unordered_map<int, int>points, cache;
    
    int maxPoints(int num){
        if(num == 0) return 0;
        if(num == 1) return points[1];
        if(cache.count(num) == 1)
            return cache[num];
        
        //recurrence relation
        int gain = points[num]*num;
        cache[num] = max(maxPoints(num-1), maxPoints(num-2) + gain);
        return cache[num];
    }

    
    int deleteAndEarn(vector<int>& arr) {
        int maxNum = 0;
        for(auto i: arr){
            points[i]++;
            //cout<<points[i]<<" ";
            maxNum = max(maxNum, i);
        }
        cout<<maxNum;
        return maxPoints(maxNum);
    }
};