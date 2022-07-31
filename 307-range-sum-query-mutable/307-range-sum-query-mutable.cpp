class NumArray {
public:
    vector<int>arr, sum;
    int len;
    NumArray(vector<int>& nums) {
        this->arr = nums;
        int n = arr.size();
        double root = sqrt(n);
        cout<<root;
        len = ceil(n/root);
        cout<<endl<<len;
        sum.resize(len, 0);
        for(int i=0; i<n; i++){
            sum[i/len] += arr[i];
        }
    }
    
    void update(int idx, int val) {
        sum[idx/len] = sum[idx/len] - arr[idx]+ val;
        arr[idx] = val;
    }
    
    int sumRange(int left, int right) {
        int ans = 0;
        int stBlock = left/len;
        int endBlock = right/len;
        if(stBlock == endBlock){
            for(int i=left; i<= right; i++)
                ans += arr[i];
        }
        else{
            for(int i=left; i<= (stBlock+1)*len -1; i++){
                ans += arr[i];
            }
            for(int i=stBlock+1; i< endBlock; i++){
                ans += sum[i];
            }
            for(int i=endBlock*len; i<= right; i++){
                ans += arr[i];
            }
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */