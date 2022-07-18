// 时间复杂度：O(log^2n)
// 空间复杂度：O(1)
class Solution {
public:
    // 十叉树+前序遍历
    int findKthNumber(int n, int k) {
        long curr = 1;
        k--;
        while (k > 0) {
            int nodes = getNode(n, curr);
            if (k >= nodes) {
                k -= nodes;
                curr++;   // go right
            } else {
                k -= 1;
                curr *= 10; // go down
            }
        }

        return (int) curr;
    }

    int getNode(int n, long curr) {
        long next = curr + 1;
        long totalNodes = 0;
        while (curr <= n) {
            totalNodes += min(n - curr + 1, (int) next - curr);
            next *= 10;
            curr *= 10;
        }

        return (int) totalNodes;
    }
};