class Solution {
public:
    
    //function to merge to subarrays in sorted order.
    void merge(vector<int>&arr, int left, int mid, int right, vector<int>&temp){
        //calculate starting points of both subarrays.
        int start1 = left, start2 = mid+1;
        //calculate sizes of both subarrays.
        int n1 = mid - left +1, n2 = right - mid;
        
        //copy elements of both subarrays into temp arrays.
        for(int i=0; i<n1; i++){
            temp[start1 + i] = arr[start1 + i];
        }
        for(int i=0; i<n2; i++){
            temp[start2 + i] = arr[start2 + i];
        }
        
        //merge the subarrays 'in temp' back into original array arr.
        int i=0, j=0, k= left;
        while(i < n1 and j < n2){
            if(temp[start1 + i] <= temp[start2 + j]){
                arr[k] = temp[start1 + i];
                i += 1;
            }else{
                arr[k] = temp[start2 + j];
                j += 1;
            }
            k++;
        }
        
        //copy remaining elements.
        while(i < n1){
            arr[k] = temp[start1 + i];
            i++; k++;
        }
        
        while(j < n2){
            arr[k] = temp[start2 + j];
            j++; k++;
        }
    }
    
    //Recursive function to sort an array using merge sort.
    void mergeSort(vector<int>&arr, int left, int right, vector<int>&temp){
        if(left >= right){
            return;
        }
        
        int mid = (left + right)/2;
        mergeSort(arr, left, mid, temp);
        mergeSort(arr, mid+1, right, temp);
        
        //merge the sorted halves.
        merge(arr, left, mid, right, temp);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        vector<int>temp(nums.size());
        
        mergeSort(nums, 0, nums.size() - 1, temp);
        return nums;
    }
};