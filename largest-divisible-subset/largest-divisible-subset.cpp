class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        
        int n = arr.size();
		
		// Sorting step
        sort(arr.begin(), arr.end());
        
        vector<int> lis(n, 1); // This will keep the length of LIS that obeys our property of divide
		vector<int>prev_idx(n, -1); // previous index array to track for previous element in the lis before i
        int max{}, index{};
 
        for(int i{}; i<n; ++i){
            
            for(int j{i-1}; j>=0; --j){
                
				// Here we know arr[i] > arr[j] because of sorting so if arr[j] divides arr[i]
				// and adding arr[j] to the LIS of arr[i] increases the size of LIS of arr[i],
				// then we will update the LIS of arr[i] and we store j i.e. the prev index for i in our sequence
                if(lis[j]+1 > lis[i] && arr[i]%arr[j] == 0){
                    
                    lis[i] = lis[j] + 1;
                    prev_idx[i] = j;
                }
            }
        }
		
		// Compute the last index in our LIS that will be the maximum length LIS
		for(int i{}; i<n; ++i){
            
            if(max < lis[i]){
                max = lis[i];
                index = i;
            }
        }
        
        vector<int>divisible_subset{};
        
		// Traverse from last index to the first index in our LIS
		// and add elements to our result
        while(index != -1){
            
            divisible_subset.push_back(arr[index]);
            index = prev_idx[index];
        }
        
        return divisible_subset;
    }
};