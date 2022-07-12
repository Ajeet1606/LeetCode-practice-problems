class Solution {
public:
    vector<int>arr;
    int avgSide;
    bool fun(vector<int>& matchsticks, int idx){
        // base case
        if(idx == matchsticks.size()){
            return arr[0]==arr[1] and arr[1]==arr[2] and arr[2]==arr[3];
        }
        
        for(int i=0; i<4; i++){
            int j=i;
            while(--j>=0){
                if(arr[j] == arr[i])
                    break;
            }
            if(j != -1) continue;
            if(arr[i] <= avgSide){
                arr[i] += matchsticks[idx];
                if(fun(matchsticks, idx+1))
                    return true;
                arr[i] -= matchsticks[idx];
            }
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        if(n==0) return false;
        int perimeter = 0;
        for(auto a: matchsticks){
            perimeter += a;
        }
        
        avgSide = perimeter/4;
        if(avgSide*4 != perimeter){
            return false;
        }
        arr.resize(4, 0);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        for(auto a: matchsticks){
            if(a > avgSide)
                return false;
        }
        return fun(matchsticks, 0);
    }
};