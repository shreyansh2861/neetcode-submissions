class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;

        for(int i=0;i<strs.size();i++){
            ans+=strs[i];
            ans+="&**";
        }

        return ans;
    }

    vector<string> decode(string s) {
        string temp;
        vector<string> ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='&' && s[i+1]=='*' && s[i+2]=='*'){
                ans.push_back(temp);
                temp="";
                i+=2;
            }
            else{
                temp.push_back(s[i]);
            }
        }

        return ans;
    }
};
