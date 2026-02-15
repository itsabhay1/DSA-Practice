class Solution {
public:
    static bool comp(const vector<int>&a, const vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int totalUnits = 0;
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int n = boxTypes.size();
        for(auto &box: boxTypes){
            int boxes = box[0];
            int units = box[1];
            if(boxes <= truckSize){
                totalUnits += boxes*units;
                truckSize -= boxes;
            }
            else{
                totalUnits += truckSize*units;
                break;
            }
        }
        return totalUnits;
    }
};