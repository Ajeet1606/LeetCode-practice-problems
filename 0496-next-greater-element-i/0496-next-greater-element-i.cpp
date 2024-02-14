class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr1, vector<int>& arr2) {
        stack<int>s;
        unordered_map<int, int>mp;
        vector<int>ans;
        
        for(int i=arr2.size()-1; i>=0; --i){
            while(!s.empty() && s.top() <= arr2[i]){
                s.pop();
            }
            
            if(s.empty()) mp[arr2[i]] = -1;
            else mp[arr2[i]] = s.top();
            s.push(arr2[i]);
            cout<<arr2[i];
        }
        
        for(int i=0; i<arr1.size(); i++){
            cout<<arr1[i];
            ans.push_back(mp[arr1[i]]);
        }
        return ans;
    }
};