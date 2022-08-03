class MyCalendar {
public:
    vector<pair<int, int>>arr;
    int n;
    MyCalendar() {
        n = arr.size();
    }
    
    bool book(int start, int end) {
        bool ans = true;
        
            for(int i=0; i<n; i++){
                //no conflict condition
                if(arr[i].first < end and start < arr[i].second){
                    ans = false;
                    break;
                }
            }
        
        
        if(ans){
            arr.push_back({start, end});
            n++;
            //sort(arr.begin(), arr.end());
        }
        
        // for(auto a: arr){
        //     cout<<a.first<<a.second<<" ";
        // }
        // cout<<endl;
        return ans;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */