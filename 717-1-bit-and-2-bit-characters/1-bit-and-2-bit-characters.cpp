class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int cnt = 0;
        for(int i = n-2; i>=0 && bits[i] == 1; i--){
            cnt ++;
        }
        return (cnt%2 == 0);
    }
};