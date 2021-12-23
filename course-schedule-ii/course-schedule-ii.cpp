class Solution {
public:
    stack<int> S;
    vector<int> V;
    vector<int> P;
    bool cycle;
    map<int, vector<int> > G;
    
    void DFS(int n)
    {        
        for(int i=0;i<n;++i)
        {
            if(!V[i]) DFS_recur(i);
        }
    }
    
    void DFS_recur(int curr)
    {
        if(cycle) return;
        
        V[curr] = true;
        P[curr] = true;
        
        for(int i : G[curr])
        {   
            if(P[i] == true) cycle = true;
            if(!V[i]) DFS_recur(i);
        }
        
        S.push(curr);
        P[curr] = false;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) 
    {
        vector<int> Ans;
        V.assign(n, false);
        P.assign(n, false);
        cycle = false;
        for(auto i : prerequisites)
        {
            G[i[1]].push_back(i[0]);
        }

        DFS(n);
        
        while(!S.empty())
        {
            Ans.push_back(S.top());
            S.pop();
        }
        
        if(cycle) return {};
        return Ans;
    }
};