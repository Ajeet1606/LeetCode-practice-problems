//Approach 1 -> Store differences in map as keys and numbers as values.

Time Complexity  - O(n + nlogn)
Space - O(n)
    
    
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int>ans;
        
        unordered_map<int, vector<int>>map;
        //closest and maximum distance of elements from x
        int mn_diff = INT_MAX, mx_diff = INT_MIN;
        
        for(int i=0; i<n; i++){
            int diff = abs(x - arr[i]);
            //push into map
            map[diff].push_back(arr[i]);
            //update pointers
            mn_diff = min(mn_diff, diff);
            mx_diff = max(mx_diff, diff);
        }
        //cnt numbers picked, we only need k numbers.
        int nums_taken = 0;
        for(int i= mn_diff; i<= mx_diff; i++){
            for(auto a: map[i]){
                ans.push_back(a);
                nums_taken++;
                if(nums_taken == k) break;
            }
            if(nums_taken == k) break;
        }
        //sort again, as they're sorted on the basis of differences.
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//--------------------------------------------------------------------------------------------------------------------------------------------------------------


//Approach 2 -> Priority Queue of K size
Time Complexity - > O(nlogn)
Space -> O(k)

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        // pair of distance, number
        priority_queue<pair<int, int>>pq;
        
        for(int i=0; i<n; i++){                     //O(n)
            pq.push({abs(arr[i] - x), arr[i]});     //O(logn)
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<int>ans;
        while(!pq.empty()){                         //O(k)
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(ans.begin(), ans.end());               //O(klogk)
        return ans;
    }
};

//------------------------------------------------------------------------------------------------------------------------------------------------------

Approach 3 - >  Two Pointers: Shrink array size to K
Time Complexity - > O(n - k)
Space -> O(1)
    
    
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size()-1;
        vector<int>ans;
        
        while(r - l + 1 > k){                           //O(n-k)
            if(abs(x - arr[l]) <= abs(x - arr[r])){
                r--;
            }else{
                l++;
            }
        }
        
        for(int i=l; i<=r; i++)
            ans.push_back(arr[i]);
        return ans;
    }
};

//---------------------------------------------------------------------------------------------------------------------------------------------------------------

Approach 4 - > Bianry Search + Two Pointers: Expand array size to K
Time Complexity - > O(k)
Space -> O(1)

class Solution {
public:
    //Binary Search + 2 pointer
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //0 to k size
        int n = arr.size();
        int r = lower_bound(arr.begin(), arr.end(), x) - arr.begin();       // O(logn)
        int l = r-1;
        
        while(k--){                                                         // O(k)
            if(r >= n or l>=0 and abs(x-arr[l] <= abs(x-arr[r])))
                l--;
            else
                r++;
        }
        
        return vector<int>(arr.begin()+l+1, arr.begin()+r);                 // O(k)
    }
};
