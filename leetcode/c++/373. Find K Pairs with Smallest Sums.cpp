// 时间复杂度：O(n^2logk)
// 空间复杂度：O(k)
class Solution {
public:
    vector <vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        auto cmp = [&nums1, &nums2](const pair<int, int> &a, const pair<int, int> &b) -> bool {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue < pair < int, int >, vector < pair < int, int >>, decltype(cmp) > pq(cmp);
        vector <vector<int>> res;
        pq.emplace(0, 0);
        while (k-- > 0 && !pq.empty()) {
            auto top = pq.top();
            pq.pop();
            res.push_back({nums1[top.first], nums2[top.second]});
            if (top.first + 1 < n) pq.emplace(top.first + 1, top.second);
            if (top.first == 0 && top.second + 1 < m) pq.emplace(top.first, top.second + 1);
        }

        return res;
    }
};

// 二分查找
// 时间复杂度：O(k+(m+n)xlog(diff(nums1)+diff(nums2))
// 空间复杂度：O(1)
class Solution {
public:
    int check(vector<int> &nums1, vector<int> &nums2, int mid, int k) {
        int n = nums1.size();
        int m = nums2.size();
        long long count = 0;
        int i = n - 1, j = 0;
        while (i >= 0 && j < m) {
            if (nums1[i] + nums2[j] <= mid) {
                count += i + 1;
                j++;
            } else {
                i--;
            }
        }

        return count - k;
    }

    vector <vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        int left = nums1[0] + nums2[0];
        int right = nums1[n - 1] + nums2[m - 1];

        int diff = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            diff = check(nums1, nums2, mid, k);
            if (diff >= 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }


        int last = m - 1;
        vector <vector<int>> res;
        for (int i = 0; i < n; i++) {
            while (last >= 0 && nums1[i] + nums2[last] >= left) last--;
            for (int j = 0; j <= last && k > 0; j++, k--) {
                res.push_back({nums1[i], nums2[j]});
            }
        }

        last = m - 1;
        for (int i = 0; i < n; i++) {
            while (last >= 0 && nums1[i] + nums2[last] > left) last--;
            for (int j = i; k > 0 && j >= 0 && nums1[j] + nums2[last] == left; j--, k--) {
                res.push_back({nums1[i], nums2[last]});
            }
        }

        return res;
    }
};
