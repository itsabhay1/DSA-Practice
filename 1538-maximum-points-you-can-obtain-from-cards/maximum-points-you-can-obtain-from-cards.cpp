class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum=0, rightSum=0, maxScore=0;
        for(int i=0; i<k; i++){
            leftSum += cardPoints[i];
        }
        maxScore = leftSum;
        int j = cardPoints.size()-1;
        for(int i = k-1; i>=0; i--){
            leftSum -= cardPoints[i];
            rightSum += cardPoints[j];
            j--;
            maxScore = max(maxScore, leftSum+rightSum);
        }
        return maxScore;
    }
};