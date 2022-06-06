// 双指针
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param height int整型vector
     * @return int整型
     */
    int maxArea(vector<int>& height) {
        // write code here
        int n = height.size();
        if (n == 0) return 0;
        int res = 0;
        int left = 0, right = n - 1;

        while (left != right) {
            int area = min(height[left], height[right]) * (right - left);
            res = max(res, area);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return res;
    }
};