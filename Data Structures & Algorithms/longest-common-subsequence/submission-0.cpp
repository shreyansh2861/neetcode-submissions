class Solution {
public:
    vector<vector<int>> memo;
    int longestCommonSubsequence(string text1, string text2) {
        memo.assign(text1.size(),vector<int>(text2.size(),0));
        return dfs(text1,text2,0,0);
    }
    int dfs(string& t1, string& t2, int i, int j){
        if(i>=t1.size() || j>=t2.size()){
            return 0;
        }

        if(t1[i]==t2[j]){
            return 1+dfs(t1,t2,i+1,j+1);
        }

        if(memo[i][j]){
            return memo[i][j];
        }

        memo[i][j]=max(dfs(t1,t2,i+1,j),dfs(t1,t2,i,j+1));
        return memo[i][j];
    }
};
