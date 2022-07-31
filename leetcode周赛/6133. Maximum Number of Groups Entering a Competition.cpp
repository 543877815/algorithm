// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int res = 1;
        sort(grades.begin(), grades.end());
        int lastsum = grades[0];
        int left = 1;
        int count = 2;
        while (left < n) {
            int sum = 0;
            int tmp = 0;
            while (left < n && tmp < count) {
                sum += grades[left];
                left++;
                tmp++;
            }
            if (sum > lastsum && tmp == count) res ++;
            count++;
        }

        return res;
    }
};