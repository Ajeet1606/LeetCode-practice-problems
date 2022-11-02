class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) {
        int start = 60* stoi(loginTime.substr(0, 2)) + stoi(loginTime.substr(3));
        
        int finish = 60* stoi(logoutTime.substr(0, 2)) + stoi(logoutTime.substr(3));
        
        if(start > finish) finish += 60*24;
        
        return max(0, (finish/15) - (start+14)/15);
    }
};