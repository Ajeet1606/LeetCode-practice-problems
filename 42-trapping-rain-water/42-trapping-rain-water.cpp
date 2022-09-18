//Optimal approach O(n) and O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        
        int l = 0, r = n-1;
        int leftMx = 0, rightMx = 0;
        
        while(l <= r){
            if(height[l] <= height[r]){
                if(height[l] > leftMx)
                    leftMx = height[l];
                else
                    ans += leftMx - height[l];
                l++;
            }else{
                if(height[r] >= rightMx)
                    rightMx = height[r];
                else
                    ans += rightMx - height[r];
                r--;
            }
        }
        
        return ans;
    }
};