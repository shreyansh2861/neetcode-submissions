class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1){
            return nums;
        }
        map<int,int> track;
        int m = INT_MIN;
        vector<int> ans;

        for(int i=0;i<k;i++){
            if(nums[i]>m){
                m=nums[i];
            }
            track[nums[i]]++;
        }

        ans.push_back(m);
        track[nums[0]]--;
        int l=1;
        k++;

        while(k-1<nums.size()){
            track[nums[k-1]]++;
            if(track[m]!=0){
                if(nums[k-1]>m){
                    m=nums[k-1];
                }
            }
            else{
                auto i=track.end();
                while(i->second==0){
                    i--;
                }
                m = i->first;
            }
            ans.push_back(m);
            k++;
            track[nums[l]]--;
            l++;
        }


        return ans;
    }
};
