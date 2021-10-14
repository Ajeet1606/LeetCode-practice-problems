class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>a(n);
        for(int i = 0; i<n; i++)
            a[i] = i+1;
        int pos = k-1;
        int i = 0;
        while(--n){
            //cout<<pos<<endl;
            a.erase(a.begin()+pos);
            pos = (pos + k-1)% n;
        }
        return a[0];
    }
};