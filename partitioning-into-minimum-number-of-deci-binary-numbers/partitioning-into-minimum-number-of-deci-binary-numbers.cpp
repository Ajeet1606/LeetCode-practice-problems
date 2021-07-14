class Solution {
public:
    int minPartitions(string n) {
        int maxv = n[0] - '0';
        for(int i = 1; i < n.length(); i++)
            if(maxv < n[i] - '0')
                maxv = n[i] - '0';
        return maxv;
    }
};