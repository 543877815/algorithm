// 时间复杂度：O(n^2+m^2+nm)
// 空间复杂度：O(n^2+m^2)
class Solution {
public:
    int numTriplets(vector<int> &nums1, vector<int> &nums2) {
        int res = 0;
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<long long, int> nums1_map;
        unordered_map<long long, int> nums2_map;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                nums1_map[(long long) nums1[i] * (long long) nums1[j]]++;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                nums2_map[(long long) nums2[i] * (long long) nums2[j]]++;
            }
        }

        for (auto &i : nums1_map) {
            for (int j = 0; j < m; j++) {
                if (i.first == (long long) nums2[j] * (long long) nums2[j]) res += i.second;
            }
        }

        for (auto &i : nums2_map) {
            for (int j = 0; j < n; j++) {
                if (i.first == (long long) nums1[j] * (long long) nums1[j]) res += i.second;
            }
        }

        return res;
    }
};