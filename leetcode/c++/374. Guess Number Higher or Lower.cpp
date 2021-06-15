/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

// 二分查找法
// 时间复杂度：O(logn)
// 空间复杂度：O(1)
class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        int middle = left + (right - left) / 2;
        while (left < right) {
            int pick = guess(middle);
            if (pick == 0) return middle;
            else if (pick == -1) {
                right = middle - 1;
                middle = left + (right - left) / 2;
            } else if (pick == 1) {
                left = middle + 1;
                middle = left + (right - left) / 2;
            }
        }

        return middle;
    }
};