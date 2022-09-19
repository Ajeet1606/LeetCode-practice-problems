class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<pair<string, string>>>content_file;
        
        for(int i=0; i< paths.size(); i++){
            string curr = paths[i], dir;
            int j=4;    //start at idx 4 (root)
            //directory
            while(curr[j] != ' '){
                dir.push_back(curr[j]);
                j++;
            }
            while(j < curr.size()){
                string file_name, content;
                //file_name starts
                while(curr[++j] != '('){
                    file_name.push_back(curr[j]);
                }
                //content starts
                while(curr[++j] != ')'){
                    content.push_back(curr[j]);
                }
                j++;//jump ) 
                //cout<<dir<<" "<<file_name<<" "<<content<<endl;
                content_file[content].push_back({dir, file_name});
            }
            
        }
        
        vector<vector<string>>ans;
        
        for(auto c: content_file){
            //cout<<"content "<<c.first<<" ";
            if(c.second.size() <= 1) continue;
            vector<string>temp;
            for(auto a: c.second){
                //cout<<"dir "<<a.first<<" name "<<a.second<<endl;
                string res = "root";
                res += a.first + "/";
                res += a.second;
                temp.push_back(res);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};