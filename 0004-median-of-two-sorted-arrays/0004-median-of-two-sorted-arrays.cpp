class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size(), n2 = arr2.size();
        
        vector<int>merge(n1+n2);
        int ptr1 = 0, ptr2 = 0, ptr = 0;
       
        while(ptr1 < n1 and ptr2 < n2){
            if(arr1[ptr1] <= arr2[ptr2]){
                merge[ptr]= arr1[ptr1++];
            }else{
                merge[ptr] = arr2[ptr2++];
            }
            ptr++;
        }
        while(ptr1 < n1){
            merge[ptr] = arr1[ptr1++];
            ptr++;
        }
        while(ptr2 < n2){
            merge[ptr] = arr2[ptr2++];
            ptr++;
        }
        int mid = (n1+n2)/2;
        if((n1+n2) %2 or n1+n2 ==1) return (double)merge[mid];
        
        return (double)(merge[mid-1] + merge[mid])/2;
    }
    
};