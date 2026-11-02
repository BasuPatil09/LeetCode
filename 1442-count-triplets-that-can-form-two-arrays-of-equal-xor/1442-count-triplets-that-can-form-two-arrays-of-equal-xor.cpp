class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        unordered_map<int,int> cnt,sum;
        int prefXor = 0;
        cnt[prefXor] = 1;
        for(int k = 0; k < n; ++k) {
            prefXor ^= arr[k];
            int val = prefXor;
            ans += cnt[val]*k - sum[val];
            cnt[val] += 1;
            sum[val] += k+1;
        }
        return ans;
    }
};