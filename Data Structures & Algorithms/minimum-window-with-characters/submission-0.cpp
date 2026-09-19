class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";

        int l=0;
        map<char,int> s1,t1;

        for(int i=0;i<t.size();i++){
            t1[t[i]]++;
        }

        int have=0, need = t1.size();
        pair<int,int> res;
        int resLen = INT_MAX;

        for(int r=0;r<s.size();r++){
            char c = s[r];
            s1[c]++;
            
            if(t1.count(c) && s1[c]==t1[c]){
                have++;
            }

            while(have == need){
                if(r-l+1<resLen){
                    resLen = r-l+1;
                    res = {l,r};
                }

                s1[s[l]]--;
                if(t1.count(s[l]) && s1[s[l]]<t1[s[l]]){
                    have--;
                }
                l++;
            }
        }


        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);;
    }
};
