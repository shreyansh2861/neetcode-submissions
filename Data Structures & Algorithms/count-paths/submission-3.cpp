class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> temp(n,-1);
        vector<vector<int>> mat(m,temp);
        return dfs(mat,0,0);
    }

    int dfs(vector<vector<int>>& mat,int m, int n){
        if(m>=mat.size() || n>=mat[0].size()){
            return 0;
        }
        if(mat[m][n]!=-1){
            return mat[m][n];
        }
        if(m==mat.size()-1 && n==mat[0].size()-1){
            return 1;
        }
        return mat[m][n] = dfs(mat,m+1,n) + dfs(mat,m,n+1);

    }
};
