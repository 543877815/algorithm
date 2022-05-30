class Solution {
public:
    int findKth(vector<int> a, int n, int K) {
        // write code here
        sort(a.begin(), a.end(), greater<int>());
        return a[K - 1];
    }
};