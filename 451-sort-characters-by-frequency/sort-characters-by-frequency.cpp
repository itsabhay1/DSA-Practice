class Solution {
public:
    struct Compare {
       bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
           return a.second < b.second; 
       }
    };
    string frequencySort(string s) {
        string ans;
        priority_queue<pair<char,int>, vector<pair<char,int>>, Compare>pq;
        unordered_map<char,int>mpp;
        for(char ch:s){
            mpp[ch]++;
        }
        for(auto& p: mpp){
            pq.push(p);
        }
        while(!pq.empty()){
            auto [ch, count] = pq.top();
            pq.pop();
            ans.append(count, ch);
        }
        return ans;
    }
};