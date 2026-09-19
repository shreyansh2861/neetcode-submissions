class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> m1,m2;

        for(int i=0;i<s1.size();i++){
            m1[s1[i]]++;
        }

        int l=0;
        for(int i=0;i<s2.size();i++){
            m2[s2[i]]++;
            if(m1==m2){
                return true;
            }
            while(m2[s2[i]]>m1[s2[i]]){
                m2[s2[l]]--;
                l++;
            }
        }

        return false;

    }
};
