class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int maxWater = 0;
        while(r>l){
            maxWater = max(maxWater,min(height[r],height[l])*(r-l));

            if(height[l]<=height[r]){
                l++;
            }
            else{
                r--;
            }
        }

        return maxWater;
    }
};