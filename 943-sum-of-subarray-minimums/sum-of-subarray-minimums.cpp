class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        arr.push_back(0);   // sentinel to flush stack
        long long mod = 1e9 + 7;
        
        stack<int> st;  // stack of indices
        long long result = 0;

        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {

                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;

                long long L = mid - left;
                long long R = right - mid;

                long long contrib = (L * R) % mod * arr[mid] % mod;
                result = (result + contrib) % mod;
            }
            st.push(i);
        }

        return (int)result;
    }
};
