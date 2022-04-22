// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        unordered_map<int, int> hashmap;
        int n = numbers.size();
        for (int i = 0; i < n; i++) {
            hashmap[numbers[i]]++;
            if (hashmap[numbers[i]] > n / 2) return numbers[i];
        }

        return 0;
    }
};