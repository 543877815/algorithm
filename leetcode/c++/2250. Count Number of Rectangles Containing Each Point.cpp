// 哈希表+二分索引
// 时间复杂度：O(hmlogm+nlogm)
// 空间复杂度：O(m+n)
class Solution {
public:
    vector<int> countRectangles(vector <vector<int>> &rectangles, vector <vector<int>> &points) {
        int n = points.size();
        vector<int> res(n); // 记录结果
        unordered_map < int, vector < pair < int, int>>> p; // 记录每个纵坐标对应点的横坐标和索引
        for (int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1];
            p[y].emplace_back(x, i);
        }

        // 计算高度大于每个纵坐标的所有矩形的长度，并以升序返回
        auto lengths = [&](int y) -> vector<int> {
            vector<int> res;
            for (const auto &rect: rectangles) {
                if (rect[1] >= y) {
                    res.push_back(rect[0]);
                }
            }
            sort(res.begin(), res.end());
            return res;
        };

        for (const auto&[h, plist]: p) {
            vector<int> llist = lengths(h);
            for (const auto&[x, idx]: plist) {
                // 二分查找计算覆盖矩形数量并更新结果数组
                res[idx] = llist.end() - lower_bound(llist.begin(), llist.end(), x);
            }
        }

        return res;
    }
};