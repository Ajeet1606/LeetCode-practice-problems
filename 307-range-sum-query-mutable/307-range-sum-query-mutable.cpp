class NumArray {
public:
    vector<int> arr;
    int n, sum = 0;
    NumArray(vector<int>& nums) {
        this->arr = nums;
        this->n = nums.size();
        sum = accumulate(arr.begin(), arr.end(), 0);
    }   
    
    
    void update(int idx, int val) {
        sum += val - arr[idx];
        arr[idx] = val;
    }
    
    int sumRange(int left, int right) {
       int ans = 0;
        if(right - left < n/2){
            ans = accumulate(arr.begin()+left, arr.begin()+right+1, 0);
        }
        else{
            ans = sum - accumulate(arr.begin(), arr.begin()+left, 0) - accumulate(arr.begin()+right+1, arr.end(), 0); 
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