// 时间复杂度：O(1)
// 空间复杂度：O(1)
class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> cnt;
    DetectSquares() {

    }

    void add(vector<int> point) {
        int x = point[0], y = point[1];
        cnt[y][x]++;
    }

    int count(vector<int> point) {
        int res = 0;
        int x = point[0], y = point[1];
        if (!cnt.count(y)) return 0;
        unordered_map<int, int>& yCnt = cnt[y];
        for (auto&[col, colCnt] : cnt) {
            if (col != y) {
                int d = col - y;
                res += (colCnt.count(x) ? colCnt[x] : 0) * (yCnt.count(x + d) ? yCnt[x + d] : 0) *
                       (colCnt.count(x + d)? colCnt[x + d] : 0);
                res += (colCnt.count(x) ? colCnt[x] : 0) * (yCnt.count(x - d) ? yCnt[x - d] : 0) *
                       (colCnt.count(x - d) ? colCnt[x - d] : 0);
            }
        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */