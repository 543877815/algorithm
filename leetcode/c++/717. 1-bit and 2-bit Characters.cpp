// 一次遍历
// 空间复杂度：O(1)
// 时间复杂度：O(n)
class Solution {
public:
    bool isOneBitCharacter(vector<int> &bits) {
        int n = bits.size();
        int start = 0;
        while (start < n - 1) {
            if (bits[start] == 1) start += 2;
            else if (bits[start] == 0) start += 1;
        }
        return start == n - 1;
    }
};

