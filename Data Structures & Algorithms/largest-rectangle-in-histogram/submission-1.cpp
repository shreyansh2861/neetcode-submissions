class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> h;
        int ans=0;

        for(int i=0;i<heights.size();i++){
            if(h.empty()){
                h.push({i,heights[i]});
                continue;
            }
            int temp=i;
            while(!h.empty() && h.top().second>heights[i]){
                ans = max((i-h.top().first)*h.top().second,ans);
                temp = h.top().first;
                h.pop();
            }
            h.push({temp,heights[i]});
        }

        while(!h.empty()){
            int i = heights.size();
            ans = max(ans,(i-h.top().first)*h.top().second);
            h.pop();
        }

        return ans;
    }
};
