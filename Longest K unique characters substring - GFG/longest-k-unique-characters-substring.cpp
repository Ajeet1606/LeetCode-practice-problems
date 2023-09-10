//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string str, int k) {
    // your code here
    unordered_map<char, int>mp;
    int ans = 0, n = str.length();

    int left = 0, right = 0;
    while(right < n){
        mp[str[right]]++;
        int sz = mp.size();
        if(sz == k){
            ans = max(ans, right - left +1);
        }else if (sz > k){
            while(sz > k){
                mp[str[left]]--;
                if(mp[str[left]] == 0){
                    mp.erase(str[left]);
                    sz--;
                }
                left++;
            }
        }
        right++;
    }
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends