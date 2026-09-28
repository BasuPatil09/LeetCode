class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        long long xorResult = 0;
        for (int number : nums)
        {
            xorResult ^= number;
        }
        long long rightmostSetBit = xorResult & -xorResult;
        vector<int> result = {0, 0};
        for (int number : nums)
        {
            if ((number & rightmostSetBit) == 0)
            {
                result[0] ^= number;
            }
            else
            {
                result[1] ^= number;
            }
        }
        return result;
    }
};