class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c : tasks) freq[c - 'A']++;

        priority_queue<int> pq;
        for (int f : freq) {
            if (f > 0) pq.push(f);
        }

        int time = 0;

        while (!pq.empty()) {
            int cycle = n + 1;
            vector<int> next;

            int executed = 0;

            while (cycle-- && !pq.empty()) {
                int f = pq.top(); pq.pop();
                if (--f > 0) next.push_back(f);
                executed++;
            }

            for (int f : next) pq.push(f);

            time += pq.empty() ? executed : n + 1;
        }

        return time;
    }
};
