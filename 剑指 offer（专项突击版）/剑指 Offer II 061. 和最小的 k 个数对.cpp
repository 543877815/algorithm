// 优先队列
// 时间复杂度：O(nmlogk)
// 空间复杂度：O(k)
class Solution {
public:
    vector <vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
            return a.first + a.second < b.first + b.second;
        };
        priority_queue < pair < int, int >, vector < pair < int, int >>, decltype(cmp) > pq(cmp);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pq.push(make_pair(nums1[i], nums2[j]));
                if (pq.size() > k) pq.pop();
            }
        }
        vector <vector<int>> res;
        while (!pq.empty()) {
            auto top = pq.top();
            vector<int> tmp = {top.first, top.second};
            res.push_back(tmp);
            pq.pop();
        }

        return res;
    }
};

// 时间复杂度：O(min(n,k))
// 空间复杂度：O(min(n,k))
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