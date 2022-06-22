// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int heightChecker(vector<int> &heights) {
        int n = heights.size();
        vector<int> expected(heights);
        sort(heights.begin(), heights.end());
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (heights[i] != expected[i]) res++;
        }
        return res;
    }
};