class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1,ml=height[0],mr=height[height.size()-1], ans=0;

        while(r>l){
            if(ml<=mr){
                l++;
                ml = max(ml,height[l]);
                ans+= ml - height[l];
            }
            else{
                r--;
                mr = max(mr,height[r]);
                ans+=mr-height[r];
            }
        }

        return ans;
    }
};
