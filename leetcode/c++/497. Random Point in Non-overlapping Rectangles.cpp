// 前缀和+二分搜索
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> presum;
    vector <vector<int>> rects;

    int countPoint(int x1, int x2, int y1, int y2) {
        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }

    Solution(vector <vector<int>> &rects) {
        this->rects = rects;
        int n = rects.size();
        presum = vector<int>(n);
        for (int i = 0; i < rects.size(); i++) {
            int x1 = rects[i][0], y1 = rects[i][1];
            int x2 = rects[i][2], y2 = rects[i][3];
            if (i == 0) presum[i] = countPoint(x1, x2, y1, y2);
            else presum[i] = presum[i - 1] + countPoint(x1, x2, y1, y2);
        }
    }

    vector<int> pick() {
        int cnt = rand() % presum.back();
        int index = upper_bound(presum.begin(), presum.end(), cnt) - presum.begin();
        int remain = index == 0 ? cnt : cnt - presum[index - 1];
        int x1 = rects[index][0], y1 = rects[index][1];
        int x2 = rects[index][2], y2 = rects[index][3];
        int x = (remain / (y2 - y1 + 1)) + x1, y = (remain % (y2 - y1 + 1)) + y1;
        return {x, y};
    }
};