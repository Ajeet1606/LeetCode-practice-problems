class Solution {
public:
   
    bool checkPowerOf2(int num){
        if(num > 0 and (num & num-1) == 0)
            return true;
        return false;
    }

    
    void generatePermutations(vector<int>&arr, vector<bool>&taken, vector<int>&v, int n, bool &answer){

        if(arr.size() == n){
            int num = 0;
            if(arr[0] == 0) return;
            for(int i=0; i<n; i++){
                num = num*10 + arr[i];
            }
            if(num > 0 and (num & num-1) == 0){
                answer = true;
            }
            return;
        }

        for(int i=0; i<n; i++){
            if(answer) break;
            if(taken[i] == false){
                arr.push_back(v[i]);
                taken[i] = true;

                generatePermutations(arr, taken, v, n, answer);
                taken[i] = false;
                arr.pop_back();
            }
        }
    }
    
    void getArrayFromNum(int n, vector<int>&v){
        while(n > 0){
            v.push_back(n%10);
            n /= 10;
        }
    }
    
    //main function
    bool reorderedPowerOf2(int n) {
        vector<int>v;
        //logn complexity
        getArrayFromNum(n, v);
        
        vector<bool>taken(n, false);
        bool answer = false;
        vector<int>arr;
        //!(logn)
        generatePermutations(arr, taken, v, v.size(), answer);
        
        return answer;
    }
};