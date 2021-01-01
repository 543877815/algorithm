// 贪心算法
// 时间复杂度：O(m)
// 空间复杂度：O(1)
class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int m = flowerbed.size();
        if (m < n) return false;
        if (m == 1) {
            if (flowerbed[0] == 1) return n <= 0;
            else return n <= 1;
        }
        int i = 0;
        while (i < m) {
            if (flowerbed[i] == 1) i += 2;
            else {
                if (i == 0) {
                    if (flowerbed[i + 1] == 0) {
                        n--;
                        i += 2;
                    } else {
                        i++;
                    }
                } else if (i == m - 1) {
                    if (flowerbed[i - 1] == 0) {
                        n--;
                        i++;
                    }
                } else {
                    if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                        n--;
                        i += 2;
                    } else {
                        i++;
                    }
                }
            }
        }
        return n <= 0;
    }
};

