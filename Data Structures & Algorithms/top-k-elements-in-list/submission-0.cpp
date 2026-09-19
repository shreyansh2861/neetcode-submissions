class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;

        for(int i=0;i<nums.size();i++){
            cnt[nums[i]]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

        for(auto& c : cnt){
            q.push({c.second,c.first});
            if(q.size()>k){
                q.pop();
            }
        }

        vector<int> ans;

        for(int i=0;i<k;i++){
            ans.push_back(q.top().second);
            q.pop();
        }

        return ans;
    }
};
