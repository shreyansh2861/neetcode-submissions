class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<vector<int>,int> temp;
        vector<vector<int>> ans;

        for(int i=0;i<nums.size();i++){
            int m=i+1,n=nums.size()-1;

            while(n>m){
                if(n==i){
                    n--;
                }
                if(nums[i]+nums[m]+nums[n]==0){
                    temp[{nums[i],nums[m],nums[n]}]++;
                    m++;
                    n--;
                }
                if(nums[m]+nums[n]+nums[i]>0){
                    n--;
                }
                if(nums[m]+nums[n]+nums[i]<0){
                    m++;
                }
            }
        }

        for(auto i=temp.begin();i!=temp.end();i++){
            ans.push_back(i->first);
        }

        return ans;
    }
};
