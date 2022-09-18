Brute force O(n^2) and O(1)
```
//Brute force O(n^2) and O(1)
class Solution {
public:
int trap(vector<int>& height) {
int ans = 0;
int n = height.size();
for(int i=0; i<n; i++){
//find left max
int lmx = 0, j=i;
while(j>=0){
lmx = max(height[j], lmx);
j--;
}
//find right max
int rmx = 0;
j = i;
while(j<n){
rmx = max(height[j], rmx);
j++;
}
ans += min(lmx, rmx) - height[i];
}
return ans;
}
};
```