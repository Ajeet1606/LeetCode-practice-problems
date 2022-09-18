//Optimal approach O(n) and O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        
        int l = 0, r = n-1;
        int leftMx = 0, rightMx = 0;
        
        while(l < r){
            leftMx = max(leftMx, height[l]);
            rightMx = max(rightMx, height[r]);
            
            if(leftMx < rightMx){
                ans += leftMx - height[l];
                l++;
            }else{
                ans += rightMx - height[r];
                r--;
            }
        }
        
        return ans;
    }
};