class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i ){
            for (int j = 0; j<i; ++j){
                if(nums[i] > nums[j] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }
        }
        return *max_element(dp.begin(), dp.end());
            
        
    }
};

// O(nlogn) - more optimal solution

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        for (int i = 0; i < n; ++i)
        {
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            if (it == dp.end())
                dp.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return dp.size();    
        
    }
};