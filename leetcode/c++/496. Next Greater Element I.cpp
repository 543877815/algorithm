// 暴力求解
// 时间复杂度：O(nm)
// 空间复杂度：O(1)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++) {
            int index = -1;
            for (int j = 0; j < m; j++) {
                if (index != -1 && nums1[i] < nums2[j]) {
                    res[i] = nums2[j];
                    break;
                }
                if (nums1[i] == nums2[j]) index = j;
            }
        }

        return res;
    }
};

// 单调栈
// 时间复杂度：O(n+m)
// 空间复杂度：O(m)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res(n, -1);
        stack<int> s;
        unordered_map<int, int> hash;
        for (int i = 0; i < m; i++) {
            while (!s.empty() && s.top() < nums2[i]) {
                hash[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        while (!s.empty()) {
            hash[s.top()] = -1;
            s.pop();
        }
        for (int i = 0; i < n; i++) {
            res[i] = hash[nums1[i]];
        }
        return res;
    }
};

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res(n, -1);
        stack<int> s;
        unordered_map<int, int> hash;
        for (int i = 0; i < m; i++) {
            while (!s.empty() && s.top() < nums2[i]) {
                hash[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }

        for (int i = 0; i < n; i++) {
            if (hash.count(nums1[i]) != 0)
                res[i] = hash[nums1[i]];
        }
        return res;
    }
};