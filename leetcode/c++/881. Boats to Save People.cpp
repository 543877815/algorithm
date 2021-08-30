// 排序+双指针
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
class Solution {
public:
    int numRescueBoats(vector<int> &people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int left = 0, right = n - 1;
        int res = 0;
        int sum = 0;
        int count = 0;
        while (left <= right) {
            while (right >= 0 && left <= right && (sum + people[right] <= limit) && count < 2) {
                sum += people[right--];
                count++;
            }
            while (left < n && left <= right && (sum + people[left] <= limit) && count < 2) {
                sum += people[left++];
                count++;
            }
            res++;
            sum = 0;
            count = 0;
        }
        return res;
    }
};