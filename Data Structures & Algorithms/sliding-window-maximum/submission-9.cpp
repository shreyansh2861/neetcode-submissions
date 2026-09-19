class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> track;
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            track.push({nums[i],i});
            if(i>=k-1){
                while(track.top().second <=i-k){
                    track.pop();
                }
                ans.push_back(track.top().first);
            }
        }

        return ans;
    }
};