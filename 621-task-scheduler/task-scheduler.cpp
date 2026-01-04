class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mp(26,0);
        for(char &ch: tasks){
            mp[ch-'A']++;
        }
        sort(mp.begin(), mp.end(),greater<>());

        int maxFreq = mp[0];
        int gaps = maxFreq-1;
        int idealSlots = gaps*n;

        for(int i=1; i<mp.size(); i++){
            idealSlots -= min(mp[i], gaps);
        }
        if(idealSlots>0){
            return tasks.size() + idealSlots;
        }else{
            return tasks.size();
        }
    }
};