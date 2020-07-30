// 时间复杂度：O(logn)
// 空间复杂度：O(1)
class Solution {
public:
    int minArray(vector<int> &numbers) {
        int left = 0, right = numbers.size() - 1, middle = left;
        while (numbers[left] >= numbers[right] && left != right) {
            if (right - left == 1) {
                middle = right;
                break;
            }
            middle = (right - left) / 2 + left;

            if (numbers[left] == numbers[middle] && numbers[middle] == numbers[right]) {
                int res = numbers[left];
                for (int i = left + 1; i <= right; i++) {
                    if (res > numbers[i]) res = numbers[i];
                }
                return res;
            }

            if (numbers[middle] >= numbers[left]) {
                left = middle;
            } else if (numbers[middle] <= numbers[right]) {
                right = middle;
            }
        }
        return numbers[middle];
    }
};