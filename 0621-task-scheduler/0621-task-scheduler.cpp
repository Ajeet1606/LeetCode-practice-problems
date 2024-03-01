class Solution {
public:
    
    int leastInterval(vector<char>& tasks, int n) {       
        vector<int>counter(26, 0);
        //store frequency.
        for(char task: tasks){
            counter[task - 'A']++;
        }
        //create a max heap.
        priority_queue<int>pq;
        
        //push every task to heap.
        for(int i=0; i<26; ++i){
            if(counter[i]) pq.push(counter[i]);
        }
        
        int ans = 0;
        
        //process tasks
        while(!pq.empty()){
            vector<int>remaining;   //used to store updated freq after processing one cycle.
            int all = n+1;  //time before next cycle.
            
            //we should have time left in cur cycle and some tasks to perform as well.
            while(all and !pq.empty()){
                //pick the most frequent one.
                int count = pq.top();
                //remove from heap.
                pq.pop();
                //process one task out of all, if left some, store in remaining.
                if(--count){
                    remaining.push_back(count);
                }
                //update timer.
                ans++;
                //update total time req for next cycle.
                all--;
            }
            //re-insert the remaining tasks into heap.
            for(int count: remaining) pq.push(count);
            //no task remaining, break;
            if(pq.empty()) break;
            //if we're doing one more cycle, add the idle time of cur cycle to ans.
            ans += all;
        }
        
        return ans;
    }
};