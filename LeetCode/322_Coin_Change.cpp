class Solution {
  public:
    int coinChange(vector<int>& coins, int amount) {
      vector<int> dp(amount+10, 1e9);

      dp[0] = 0;
      for(int i = 0; i < coins.size(); i++)
        for(int a = coins[i]; a <= amount; a++)
          dp[a] = min(dp[a], dp[a-coins[i]] + 1);

      return dp[amount]==1e9? -1 : dp[amount];
    }
};
