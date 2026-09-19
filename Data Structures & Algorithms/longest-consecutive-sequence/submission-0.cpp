class Solution {
public:
    unordered_set<int> temp,starts;
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        for(int i=0;i<nums.size();i++){
            temp.insert(nums[i]);
        }

        for(auto& i : temp){
            if(!temp.count(i-1)){
                starts.insert(i);
            }
        }
        int t = 0;
        for(auto& i : starts){
            
            int c = count(i,1);

            if(t<c) t=c;
        }

        return t;
    }
    int count(int i, int length){
        if(temp.count(i+1)){
            return count(i+1, length + 1);
        }
        return length;
    }
};
