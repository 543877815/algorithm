// 空间复杂度：O(1)
// 时间复杂度：O(n)
class Solution {
public:
    vector <vector<int>> threeSum(vector<int> &num) {
        vector <vector<int>> res;
        int n = num.size();
        if (n < 3) return res;
        sort(num.begin(), num.end());
        for (int i = 0; i < n - 2; i++) {
            if (num[i] > 0) break;
            if (i > 0 && num[i] == num[i - 1]) continue;
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = num[i] + num[left] + num[right];
                if (sum == 0) {
                    vector<int> tmp = {num[i], num[left--], num[right--]};
                    res.push_back(tmp);
                    while (left < right && num[left] == num[left - 1]) left++;
                    while (left < right && num[right] == num[right + 1]) right--;
                } else if (sum > 0) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return res;
    }
};