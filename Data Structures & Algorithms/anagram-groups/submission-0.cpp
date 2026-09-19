class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp = strs;

        for(int i=0;i<temp.size();i++){
            sort(temp[i].begin(),temp[i].end());
        }

        map<string,vector<int>> m;

        for(int i=0;i<temp.size();i++){
            m[temp[i]].push_back(i);
        }

        vector<vector<string>> ans;

        for(auto i=m.begin();i!=m.end();i++){
            vector<string> group;
            for(int j=0;j<i->second.size();j++){
                group.push_back(strs[i->second[j]]);
            }
            ans.push_back(group);
        }

        return ans;
    }
};
