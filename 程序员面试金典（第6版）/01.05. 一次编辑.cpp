// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    bool oneEditAway(string first, string second) {
        if (first == second) return true;
        int n = first.size(), m = second.size();
        // 删除两次或者插入两次
        if (std::abs(n - m) >= 2) return false;

        int i = 0, j = n - 1, k = m - 1;
        while (i < n && i < m && first[i] == second[i]) i++;
        while (j >= 0 && k >= 0 && first[j] == second[k]) {
            j--;
            k--;
        }
        return j - i < 1 && k - i < 1;
    }
};