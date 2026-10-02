class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1000000007;

        vector<int> dp(n);
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && st.top().first >= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                dp[i] = arr[i] * (i + 1);
            }
            else {
                int j = st.top().second;
                dp[i] = dp[j] + arr[i] * (i - j);
            }

            st.push({arr[i], i});
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = (ans + dp[i]) % MOD;
        }

        return ans;
    }
};