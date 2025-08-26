// Question Link : https://leetcode.com/problems/diagonal-traverse/description/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> ans;
        map<int, vector<int>> mp;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mp[i+j].push_back(mat[i][j]);    // Here i+j concept it used, as we have diagonals facing upwards
            }
        }
        bool flip = true;
        for(auto &it : mp){
            if(flip){
                reverse(it.second.begin(), it.second.end());
            }
            for(int num : it.second){
                ans.push_back(num);
            }
            flip = !flip;
        }

        return ans;
    }
};
