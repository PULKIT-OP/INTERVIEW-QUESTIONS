// used backTracking approach
class Solution {
public:
    int n;
    vector<vector<int>> result;
    void solve(unordered_map<int, int> &mp, vector<int> &temp){
        if(temp.size() == n){
            result.push_back(temp);
            return;
        }
        for(auto [num, count] : mp){
            if(count == 0){
                continue;
            }
          // take step
            temp.push_back(num);
            mp[num]--;
          // explore
            solve(mp, temp);
          // reverse the step
            temp.pop_back();
            mp[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();

        vector<int> temp;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        sort(begin(nums), end(nums));
        solve(mp, temp);

        return result;
    }
};
