class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> dupli;
        int l=0,len=0;

        for(int r=0;r<s.size();r++){
            while(dupli[s[r]]){
                dupli.erase(s[l]);
                l++;
            }
            dupli[s[r]]++;
            len = max(len, r-l+1);
        }

        return len;
    }
};
