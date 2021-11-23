// standard Disjoin Set Union class template
class DSU {
    public:
    vector<int> par, sz;
    DSU(int n) : par(n), sz(n,1) {
        iota(begin(par), end(par), 0);                         // initializes each node's parent to be itself - fills as [0,1,2,3,...,n]
    }
    int find(int x) {
        if(par[x] == x) return x;                              // x is itself the parent of the component that it belongs to
        return par[x] = find(par[x]);                          // update parent of x before returning for each call -path compression
    }
    bool Union(int x, int y) {
        int xp = find(x), yp = find(y);                        // find parents of x and y, i.e, representatives of components that x and y belong to
        if(xp == yp) return false;                             // x and y already belong to same component - not possible to union
        if(sz[xp] > sz[yp]) par[yp] = par[xp], sz[xp] += sz[yp];   // union by size - join smaller sized to bigger one
        else par[xp] = par[yp], sz[yp] += sz[xp];
        return true;
    }
};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = size(nums), ans = 1;
        DSU ds(*max_element(begin(nums), end(nums)) + 1);      // max(nums) is largest element that will be stored in DSU
        unordered_map<int, int> mp;                            // maintains {parent of component: frequency}
        for(auto c : nums) 
            for(int f = 2; f <= sqrt(c); f++)                  // finding factors of each element
                if(c % f == 0)                                 // if f divides c, then f & c/f are its factor. So union them
                    ds.Union(c, f), 
                    ds.Union(c, c/f);
        
        for(int i = 0; i < n; i++)                             // iterate and find parent that is seen most. It'll give the largest group
            ans = max(ans, ++mp[ds.find(nums[i])]);
        return ans;
    }
};