
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> maxHeap;
        vector<int> frequency(26, 0);

        for (char task : tasks) {
            frequency[task - 'A']++;
        }

        for (int count : frequency) {
            if (count > 0) {
                maxHeap.push(count);
            }
        }

        int time = 0;

        while (!maxHeap.empty()) {
            vector<int> remaining;
            int cycle = n + 1;

            while (cycle > 0 && !maxHeap.empty()) {
                int maxFrequency = maxHeap.top();
                maxHeap.pop();

                if (maxFrequency > 1) {
                    remaining.push_back(maxFrequency - 1);
                }

                time++;
                cycle--;
            }

            for (int count : remaining) {
                maxHeap.push(count);
            }

            if (maxHeap.empty()) {
                break;
            }

            time += cycle;
        }

        return time;
    }
};
