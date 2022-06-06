// 双指针
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    /**
     *
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int> &arr) {
        // write code here
        unordered_map<int, int> mymap;
        int n = arr.size();
        int left = 0;
        int right = 0;
        int res = 0;
        while (right < n) {
            int repeat = -1;
            while (right < n) {
                mymap[arr[right]]++;
                right++;
                if (right > 0 && mymap[arr[right - 1]] > 1) {
                    repeat = arr[right-1];
                    break;
                }
            }

            res = max(res, right - left - 1);
            while (left < right && mymap[repeat] > 1) {
                mymap[arr[left]]--;
                left++;
            }
            res = max(res, right - left);
        }

        return res;
    }
};