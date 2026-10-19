class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxi = 0;

        for (int bit = 31; bit >= 0; bit--) {
            maxi <<= 1;

            int curr = maxi | 1;
            unordered_set<int> st;

            for (int num : nums) {
                st.insert(num >> bit);
            }

            for (int prefix : st) {
                if (st.count(curr ^ prefix)) {
                    maxi = curr;
                    break;
                }
            }
        }

        return maxi;
    }
};