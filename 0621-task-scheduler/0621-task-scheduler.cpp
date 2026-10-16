
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> frequency;
        int maxFrequency = 0;
        for (char task : tasks) {
            frequency[task]++;
            maxFrequency = max(maxFrequency, frequency[task]);
        }
        int minTime = (maxFrequency - 1) * (n + 1);
        for (auto entry : frequency) {
            if (entry.second == maxFrequency) {
                minTime++;
            }
        }
        return max((int)tasks.size(), minTime);
    }
};
