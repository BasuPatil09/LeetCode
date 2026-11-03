class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int currentCount = 1;
        int longestCount = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            else if (nums[i] == nums[i - 1] + 1) {
                currentCount++;
            }
            else {
                currentCount = 1;
            }
            longestCount = max(longestCount, currentCount);
        }
        return longestCount;
    }
};