class MyCalendar {
public:
    vector<pair<int, int>>arr;
    int n;
    MyCalendar() {
        n = arr.size();
    }
    
    bool book(int start, int end) {
        bool ans = false;
        if(n == 0){
            ans = true;
        }
        else{
            if(end <= arr[0].first){
                ans = true;
            }
            else if(start >= arr[n-1].second){
                ans = true;
            }
            else{
                for(int i=1; i<n; i++){
                    if(start >= arr[i-1].second and end <= arr[i].first){
                        ans = true;
                        break;
                    }
                }
            }
        }
        
        if(ans){
            arr.push_back({start, end});
            n++;
            sort(arr.begin(), arr.end());
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