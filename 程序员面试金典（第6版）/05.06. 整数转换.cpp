// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int convertInteger(int A, int B) {
        int res = 0;
        for (unsigned C = A ^B; C != 0; C = C >> 1) {
            res += C & 1;
        }
        return res;
    }
};