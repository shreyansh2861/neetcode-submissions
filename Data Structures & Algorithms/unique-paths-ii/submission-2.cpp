class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<long long>> mat(m+1,vector<long long>(n+1,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    mat[i][j]=-1;
                }
            }
        }

        if (mat[m-1][n-1] == -1) return 0;
        mat[m-1][n-1]=1;

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i == m-1 && j == n-1) continue;
                if(mat[i][j]==-1){
                    continue;
                }
                if(mat[i+1][j]==-1){
                    mat[i][j]+=mat[i][j+1];
                }
                if(mat[i][j+1]==-1){
                    mat[i][j]+=mat[i+1][j];
                }
                else{
                    mat[i][j] += mat[i+1][j] + mat[i][j+1];
                }
                
                long long down = (mat[i+1][j] == -1) ? 0 : mat[i+1][j];
                long long right = (mat[i][j+1] == -1) ? 0 : mat[i][j+1];
                mat[i][j] = down + right;
            }
        }

        return (int)mat[0][0];
    }
};