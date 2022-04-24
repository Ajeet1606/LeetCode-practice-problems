class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>>data;
    unordered_map<string, vector<pair<string, int>>>avgTime;
        
    void checkIn(int id, string stationName, int t) {
        data[id] = {stationName, t};
    }
    
    void checkOut(int id, string checkOutSt, int checkOutTime) {
        string checkInSt = data[id].first;
        int checkInTime = data[id].second;
        avgTime[checkInSt].push_back({checkOutSt, checkOutTime - checkInTime});
    }
    
    double getAverageTime(string checkInSt, string checkOutSt) {
        double ans;
        bool firstTime = true;
        auto v = avgTime[checkInSt];
        int cnt= 0;
        for(auto a: v){
            if(a.first == checkOutSt){
                ans += a.second;
                cnt++;
                cout<<a.second<<" ";
            }
        }
        
        return ans/cnt;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */