// 排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        sort(input.begin(), input.end());
        for (int i = 0; i < k; i++) {
            res.push_back(input[i]);
        }

        return res;
    }
};