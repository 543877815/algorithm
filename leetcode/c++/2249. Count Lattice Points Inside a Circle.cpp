
// 哈希表
// 时间复杂度：O(nwh)
// 空间复杂度：O(n)
class Solution {
public:
    int countLatticePoints(vector <vector<int>> &circles) {
        int res = 0;
        int n = circles.size();
        unordered_map<int, bool> mymap;

        for (int k = 0; k < n; k++) {
            int x = circles[k][0], y = circles[k][1], r = circles[k][2];
            int x_min = x - r, x_max = x + r;
            int y_min = y - r, y_max = y + r;
            for (int i = x_min; i <= x_max; i++) {
                for (int j = y_min; j <= y_max; j++) {
                    if (((i - x) * (i - x) + (j - y) * (j - y)) <= (r * r)) {
                        int index = i + j * 10000;
                        if (mymap.find(index) == mymap.end()) {
                            res++;
                            mymap[index] = true;
                        }
                    }
                }
            }
        }


        return res;
    }
};