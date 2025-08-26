// Here we are using sliding window approach 

int lengthOfLongestSubstring(string s) {
    int n = s.length();

    int i = 0;
    int j = 0;
    int maxi = 0;
    vector<int> v(255, -1);

    while(j < n){
        if(v[s[j]] != -1){
            if(v[s[j]] >= i){
                i = v[s[j]] + 1;
            }
        }
        int len = j-i+1;
        maxi = max(maxi, len);
        v[s[j]] = j;
        j++;
    }
    return maxi;
}
