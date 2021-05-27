int hammingWeight(uint32_t n) {
    int num = 0;
    for (int i = 0; i < 32; i++) {
        num += n & 1;
        n = n >> 1;
    }
    return num;
}

int hammingDistance(int x, int y) {
    int tmp = x ^y;
    return hammingWeight(tmp);
}

// 时间复杂度：O(c)
// 空间复杂度：O(1)
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        while (x != 0 || y != 0) {
            if ((x & 1) != (y & 1)) {
                res++;
            }
            x = x >> 1;
            y = y >> 1;
        }
        return res;
    }
};