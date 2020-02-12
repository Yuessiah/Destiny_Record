class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[5010][510];
        memset(dp, 0, sizeof dp);

        coins.push_back(0);
        sort(coins.begin(), coins.end());
        dp[0][0] = 1;

        for(int n = 0; n <= amount; n++)
            for(int last = 1; last < coins.size(); last++)
                for(int i = 0; i <= last; i++)
                    if(n-coins[last] >= 0) dp[n][last] += dp[n-coins[last]][i];

        int sum = 0;
        for(int i = 0; i < coins.size(); i++) sum += dp[amount][i];

        return sum;
    }
};
