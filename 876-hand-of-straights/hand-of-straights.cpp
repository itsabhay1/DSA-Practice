class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        sort(hand.begin(), hand.end());
        unordered_map<int,int> freq;
        for (int card : hand) freq[card]++;

        for (int card : hand) {
            if (freq[card] == 0) continue;  // already used
            int count = freq[card];
            for (int i = 0; i < groupSize; i++) {
                int nextCard = card + i;
                if (freq[nextCard] < count) return false;
                freq[nextCard] -= count;
            }
        }

        return true;
    }
};
