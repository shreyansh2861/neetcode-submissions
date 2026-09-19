class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(),1);
        vector<int> suffix(nums.size(),1);

        int n=1;
        for(int i=1;i<nums.size();i++){
            n*=nums[i-1];
            prefix[i]*=n;
        }

        n=1;
        for(int i=nums.size()-2;i>=0;i--){
            n*=nums[i+1];
            suffix[i]*=n;
        }

        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            cout<<prefix[i]<<" "<<suffix[i]<<endl;
            ans.push_back(prefix[i]*suffix[i]);
        }

        return ans;
    }
};
