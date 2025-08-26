// Question link : https://leetcode.com/problems/sort-matrix-by-diagonals/description/

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // populate the map
        map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                mp[i-j].push_back(grid[i][j]);
            }
        }

        // sort diagonals accordingly, if i-j < 0 then sort it in ascending order otherwise sort it in descending order
        for(auto &it : mp){
            if(it.first < 0){
                sort(it.second.begin(), it.second.end());
            }
            else{
                sort(it.second.begin(), it.second.end(), greater<int>());
            }
        }
      
        // populate the result matrix with sorted diagonals
        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                grid[i][j] = mp[i-j].back();
                mp[i-j].pop_back();
            }
        }

        return grid;
    }
};
