class Solution
{
    public:

 pair<int, int> f(vector<int>& nums, int i, int prev,vector<vector<pair<int, int>>>& dp) {
    if (i >= nums.size())
        return {0, 1}; // The length of LIS is 0, and there is one such LIS (an empty LIS).

    if (dp[prev + 1][i].first != -1)
        return dp[prev + 1][i];
     
//    in this qn. we are storing in 'a' is by taking that value and storing the length of the subsequence in a.first
     // and storing the frequency of that suseq. in a.second
     
//   and 'b' is storing the then length of subseq. in b.first and freq. of that subseq. in b.second by not taking that value (means by skipping) ... 

    std::pair<int, int> a = {0, 0}, b = {0, 0};

    if (prev == -1 || nums[i] > nums[prev]) {
        a = f(nums, i + 1, i, dp);
        a.first++;
    }

    b = f(nums, i + 1, prev, dp);
     
     
//   in this condn. if my length of longest subseq. by taking ele. and not taking that ele. are equal then we just add up the freq.   
    if (a.first == b.first) {
        dp[prev + 1][i] = {a.first, a.second + b.second};
    }
//   if a has longest subseq. lenght then we take a   
     else if (a.first > b.first) {
        dp[prev + 1][i] = a;
    } else {
        dp[prev + 1][i] = b;
    }

    return dp[prev + 1][i];
}

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();

    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(n, {-1, -1}));

    return f(nums, 0, -1, dp).second;
}

   
    
    


};
