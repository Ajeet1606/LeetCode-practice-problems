class NumArray {
public:
    vector<int>tree, arr;
    int n;
    NumArray(vector<int>& nums) {
        this->arr = nums;
        this->n = nums.size();
        tree.resize(n*2);
        buildTree();
    }
    
    //O(n)
    void buildTree(){
        int j = 0;
        for(int i=n; i<2*n; i++){
            tree[i] = arr[j++];
        }
        for(int i = n-1; i>=0; i--){
            tree[i] = tree[i*2] + tree[i*2+1];
        }
    }
    
    void update(int idx, int val) {
        idx += n;
        tree[idx] = val;
        while(idx > 0){
            int l = idx, r = idx;
            if(idx & 1){
                l = idx-1;
            }
            else{
                r = idx+1;
            }
            
            tree[idx/2] = tree[l] + tree[r];
            idx /= 2;
        }
    }
    
    int sumRange(int left, int right) {
        //find leaf with value left, right
        left += n;
        right += n;
        
        int sum = 0;
        while(left <= right){
            if(left & 1){
                sum += tree[left];
                left++;
            }
            if(!(right&1)){
                sum += tree[right];
                right--;
            }
            left /= 2;
            right /= 2;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */