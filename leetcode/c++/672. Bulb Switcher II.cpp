// 时间复杂度：O(1)
// 空间复杂度：O(1)
class Solution {
public:
    int flipLights(int n, int presses) {
        unordered_set<int> seen;
        /**
            编号为 6k+1，受按钮 1,3,4 影响；
            编号为 6k+2,6k+6，受按钮 1,2 影响；
            编号为 6k+3,6k+5，受按钮 1,3 影响；
            编号为 6k+4，受按钮 1,2,4 影响。
        **/

        for (int i = 0; i < 1 << 4; i++) {   // 一共有2^4种情况
            vector<int> pressArr(4);
            for (int j = 0; j < 4; j++) {   // 遍历是否按压
                pressArr[j] = (i >> j) & 1;
            }
            int sum = accumulate(pressArr.begin(), pressArr.end(), 0);  // 按压总次数
            if (sum % 2 == presses % 2 && sum <= presses) {
                int status = pressArr[0] ^ pressArr[1] ^ pressArr[3];
                if (n >= 2) {
                    status |= (pressArr[0] ^ pressArr[1]) << 1;
                }
                if (n >= 3) {
                    status |= (pressArr[0] ^ pressArr[2]) << 2;
                }
                if (n >= 4) {
                    status |= (pressArr[0] ^ pressArr[1] ^ pressArr[3]) << 3;
                }
                seen.emplace(status);
            }
        }
        return seen.size();
    }
};

