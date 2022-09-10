class Solution {
    
    vector<vector<vector<int>>> mem;
    int recursion(vector<int>& prices,int n,int k,int pos,bool bought)
    {
        if(k==0 || pos>=n)  //All transactions done OR outOfBounds
            return 0;
        if(mem[bought][k][pos]!=-1) //Return already calculated value
            return mem[bought][k][pos];
        
        int sum = recursion(prices,n,k,pos+1,bought);   
        if(bought)
            sum = max(sum,recursion(prices,n,k-1,pos+1,false)+prices[pos]);     //SELL
        else
            sum = max(sum,recursion(prices,n,k,pos+1,true)-prices[pos]);    //BUY
        
        mem[bought][k][pos] = sum;
        return sum;
    }
    
public:
    
    int maxProfit(int k, vector<int>& prices) {
        mem.resize(2,vector<vector<int>> (k+1,vector<int> (prices.size(),-1)));     //mem[bought][k][pos]
        return recursion(prices,prices.size(),k,0,false);
    }
};