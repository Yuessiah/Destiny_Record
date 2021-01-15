class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> q;
        for(int i = 0; i < k-1; i++) q.push_back({nums[i], i});
        sort(q.begin(), q.end());

        vector<int> ans;
        for(int i = k-1; i < nums.size(); i++) {
            while(q.size() && q.front().first <= nums[i]) q.pop_front();
            q.push_front({nums[i], i});
            while(q.size() && q.back().second < i-k+1) q.pop_back();

            ans.push_back(q.back().first);
        }

        return ans;
    }
};
