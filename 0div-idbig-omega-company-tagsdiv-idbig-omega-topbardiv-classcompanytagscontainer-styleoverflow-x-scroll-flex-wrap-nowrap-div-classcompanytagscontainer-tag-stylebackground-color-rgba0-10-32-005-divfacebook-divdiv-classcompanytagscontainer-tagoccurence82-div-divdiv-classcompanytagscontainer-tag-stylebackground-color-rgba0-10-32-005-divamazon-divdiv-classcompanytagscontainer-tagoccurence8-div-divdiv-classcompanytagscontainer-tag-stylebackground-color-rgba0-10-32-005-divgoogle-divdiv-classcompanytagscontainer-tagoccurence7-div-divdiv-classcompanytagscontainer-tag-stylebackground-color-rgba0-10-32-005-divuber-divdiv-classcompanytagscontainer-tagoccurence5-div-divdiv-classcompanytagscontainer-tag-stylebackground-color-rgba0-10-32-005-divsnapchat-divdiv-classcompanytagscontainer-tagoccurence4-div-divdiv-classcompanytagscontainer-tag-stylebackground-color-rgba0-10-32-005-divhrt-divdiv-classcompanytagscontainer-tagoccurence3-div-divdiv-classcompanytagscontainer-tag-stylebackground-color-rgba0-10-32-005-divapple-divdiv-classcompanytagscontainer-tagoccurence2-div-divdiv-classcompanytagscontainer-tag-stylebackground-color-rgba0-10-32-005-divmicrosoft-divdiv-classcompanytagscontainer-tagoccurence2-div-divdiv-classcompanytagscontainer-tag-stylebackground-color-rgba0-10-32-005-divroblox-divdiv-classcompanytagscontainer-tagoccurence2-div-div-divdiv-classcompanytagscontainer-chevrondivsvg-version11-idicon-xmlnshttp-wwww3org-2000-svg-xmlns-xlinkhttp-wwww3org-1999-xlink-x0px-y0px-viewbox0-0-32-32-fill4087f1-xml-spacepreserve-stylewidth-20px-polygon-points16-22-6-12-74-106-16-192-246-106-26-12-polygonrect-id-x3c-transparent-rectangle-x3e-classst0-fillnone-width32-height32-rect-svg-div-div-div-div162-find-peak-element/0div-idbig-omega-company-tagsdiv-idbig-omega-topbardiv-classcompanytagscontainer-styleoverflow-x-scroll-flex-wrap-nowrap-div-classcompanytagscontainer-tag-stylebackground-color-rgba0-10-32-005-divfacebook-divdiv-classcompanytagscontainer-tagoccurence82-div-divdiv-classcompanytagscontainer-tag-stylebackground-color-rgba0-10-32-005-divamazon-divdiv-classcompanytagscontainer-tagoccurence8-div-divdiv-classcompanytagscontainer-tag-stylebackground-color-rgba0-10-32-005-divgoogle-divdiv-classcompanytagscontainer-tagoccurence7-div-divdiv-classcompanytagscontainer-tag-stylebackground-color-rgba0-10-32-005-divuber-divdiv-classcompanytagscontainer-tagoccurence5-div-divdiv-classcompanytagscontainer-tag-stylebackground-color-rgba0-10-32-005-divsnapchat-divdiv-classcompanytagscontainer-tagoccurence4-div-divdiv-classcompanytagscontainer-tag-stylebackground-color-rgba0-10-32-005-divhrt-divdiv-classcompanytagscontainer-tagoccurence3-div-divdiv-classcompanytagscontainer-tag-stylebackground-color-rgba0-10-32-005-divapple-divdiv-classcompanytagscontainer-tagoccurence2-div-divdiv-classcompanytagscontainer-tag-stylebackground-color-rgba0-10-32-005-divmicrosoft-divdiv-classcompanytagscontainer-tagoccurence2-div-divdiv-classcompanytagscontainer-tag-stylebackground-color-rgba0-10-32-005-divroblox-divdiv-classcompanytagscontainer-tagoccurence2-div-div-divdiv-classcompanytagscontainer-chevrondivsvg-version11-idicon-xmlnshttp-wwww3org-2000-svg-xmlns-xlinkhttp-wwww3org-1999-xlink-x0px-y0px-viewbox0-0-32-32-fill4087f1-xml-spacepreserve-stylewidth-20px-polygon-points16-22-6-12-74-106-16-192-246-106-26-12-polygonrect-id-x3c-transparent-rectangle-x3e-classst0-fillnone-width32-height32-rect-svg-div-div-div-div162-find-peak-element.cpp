class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int left = 0, n = arr.size(), right = n-1;
        if(n == 1) return 0;
        
        while(left <= right){
            int mid = left + (right - left)/2;
            
            //both neighbors exist.
            if(mid > 0 and mid < n-1){
                //mid is a peak.
                if(arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1]) return mid;
            }
            
            //only left neighbor exist
            if(mid > 0 and mid == n-1){
                //mid is peak.
                if(arr[mid] > arr[mid -1]) return mid;
            }
            
            //only right neighbor exist.
            if(mid < n-1 and mid == 0){
                ///mis is peak.
                if(arr[mid] > arr[mid+1]) return mid;
            }
            
            //mid isn't a peak, we need to change search space.
            //left neighbor exists
            if(mid > 0){
                //and it is bigger, go there.
                if(arr[mid] < arr[mid-1]){
                    right = mid-1;
                    continue;
                }
            } 
            
            //right neighbor exist
            if(mid < n-1){
                //and its bigger, go there.
                if(arr[mid] < arr[mid+1]){
                    left = mid+1;
                }
            }
            
//             cout<<left <<' '<<mid<<' '<<right<<endl;
        }
        return 0;
    }
};