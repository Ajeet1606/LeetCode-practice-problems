class Solution {
public:
    
    void merge(vector<int>&count, vector<pair<int, int>>&v, int left, int mid, int right){
        //array to store merged elements with corresponding index.
        vector<pair<int,int>> temp(right - left + 1);
        //i will traverse left part, j will traverse right part.
        int i = left, j = mid+1, k=0;
        //while both are in valid position. 
        while(i<=mid and j<=right){
            //if left part value is smaller, add right value in merged array(temp)
            if(v[i].first <= v[j].first){
                temp[k++] = v[j++];
            }
            //left is bigger, it's out need, update it's value in count(answer) array with number of small elements in right side. 'jth' is small so all after it will also. 
            else{
                count[v[i].second] += right-j+1;
                temp[k++] = v[i++];
            }
        }
        
        //now one of i/j covers full area other remains.
        //simply push that in merged array.
        while(i<=mid){
            temp[k++] = v[i++];
        }
        
        while(j <= right){
            temp[k++] = v[j++];
        }
        
        //now temp has final merged array, assign it to v.
        for(int i=left; i<=right; i++){
            v[i] = temp[i-left];
        }
    }
    
    
    void mergeSort(vector<int>&count, vector<pair<int, int>>&v, int left, int right){
        //divide the array from middle.
        if(left < right){
            int mid = left + (right - left)/2;
            //call for left part.
            mergeSort(count, v, left, mid);
            //call for right part.
            mergeSort(count, v, mid+1, right);
            //now merge the parts.
            merge(count, v, left, mid, right);
        }
    }
    
    
    vector<int> countSmaller(vector<int>& nums) {
        
        //given array size.
        int n = nums.size();
        //v array to store every element with its index.
        vector<pair<int, int>>v(n);
        for(int i=0; i<n; i++){
            v[i].first = nums[i];//value
            v[i].second = i;//index.
        }
        //answer array.
        vector<int>count(n, 0);
        //function call.
        mergeSort(count, v, 0, n-1);
        return count;
    }
};