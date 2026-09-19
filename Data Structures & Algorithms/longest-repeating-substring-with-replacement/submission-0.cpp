class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> count;
        int res=0;

        int l=0,maxf=0;

        for(int i=0;i<s.size();i++){
            count[s[i]]++;
            maxf = max(maxf,count[s[i]]);

            while((i-l+1)-maxf>k){
                count[s[l]]--;
                l++;
            }

            res = max(res, i-l+1);

        }

        return res;
    }
};
