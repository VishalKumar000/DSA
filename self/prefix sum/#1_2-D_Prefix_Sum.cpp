/*
    TODO: Matrix Block Sum
    ? https://leetcode.com/problems/matrix-block-sum/description/
*/

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    void prefix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        dp.resize(n, vector<int> (m,0));
        dp[0][0] = mat[0][0];
        for(int i=1;i<n;i++) dp[i][0] = dp[i-1][0] + mat[i][0];
        for(int i=1;i<m;i++) dp[0][i] = dp[0][i-1] + mat[0][i];
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j] = mat[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
    }
    int query(int r1,int r2,int c1,int c2) {
        if(r1 == 0 and c1 != 0) return dp[r2][c2] - dp[r2][c1-1];
        else if(c1 == 0 and r1 != 0) return dp[r2][c2] - dp[r1-1][c2];
        else if(r1 == 0 and c1 == 0) return dp[r2][c2];
        else return dp[r2][c2] - dp[r2][c1-1] - dp[r1-1][c2] + dp[r1-1][c1-1];
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        prefix(mat);
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // row
                int r1 = max(0,i-k), r2 = min(n-1,i+k);
                // column
                int c1 = max(0,j-k), c2 = min(m-1,j+k);
                ans[i][j] = query(r1,r2,c1,c2);
            }
        }
        return ans;
    }
};