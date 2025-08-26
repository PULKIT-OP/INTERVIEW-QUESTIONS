// Question Link : https://leetcode.com/problems/sort-the-matrix-diagonally/description/

// steps involved are: take a map then populate it as per the diagonal it belongs then sort accordingly at last update the matrix and return 
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        map<int, vector<int>> mp;
        vector<vector<int>> result(m, vector<int>(n));
      
        // populating the mp map
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mp[i-j].push_back(mat[i][j]);
            }
        }

      // sort diagonals 
        for(auto &it : mp){
            sort(it.second.begin(), it.second.end());
        }

      // now populate the matrix with sorted diagonals
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                result[i][j] = mp[i-j].back();
                mp[i-j].pop_back();
            }
        }

        return result;
    }
};
