class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        
        int ml = height[0];
        for (int i = 1; i < height.size(); i++) {
            maxLeft[i] = ml;
            ml = max(ml, height[i]);
        }
        
        int mr = height[height.size()-1];
        for (int i = height.size()-2; i >= 0; i--) {
            maxRight[i] = mr;
            mr = max(mr, height[i]);
        }
        
        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            int water = min(maxLeft[i], maxRight[i]) - height[i];
            if (water > 0) {
                ans += water;
            }
        }
        
        return ans;
    }
};