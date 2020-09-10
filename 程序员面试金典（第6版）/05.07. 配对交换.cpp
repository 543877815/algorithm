// 时间复杂度：O(1)
// 空间复杂度：O(1)
class Solution {
public:
    int exchangeBits(int num) {
        return ((num & 0x55555555) << 1) | ((num & 0xaaaaaaaa) >> 1);
    }
};