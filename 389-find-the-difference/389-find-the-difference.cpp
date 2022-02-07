class Solution {
public:
    char findTheDifference(string s, string t) {
        int arr[26] = {0};
        for(int i=0; i<s.length(); i++)
            arr[s[i]-'a']++;
        for(int i=0; i<t.length(); i++)
            arr[t[i]-'a']--;
        char ch;
        for(int i=0; i<26; i++){
            if(arr[i] < 0){
                ch = i+'a';
                break;
            }
        }
        return ch;
    }
};