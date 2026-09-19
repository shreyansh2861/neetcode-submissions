class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> temps(temperatures.size(),0);

        stack<pair<int,int>> track;

        for(int i=0;i<temperatures.size();i++){
            if(track.empty()){
                track.push({temperatures[i],i});
                continue;
            }
            while(!track.empty() && temperatures[i]>track.top().first){
                temps[track.top().second] = i-track.top().second;
                track.pop();
            }
            track.push({temperatures[i],i});
        }

        return temps;
    }
};
