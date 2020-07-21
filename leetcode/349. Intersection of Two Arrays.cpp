// 时间复杂度：O(m+n)
// 空间复杂度：O(m+n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> record, resultSet;
        for (int i : nums1) {
            record.insert(i);
        }

        for (int i : nums2) {
            if(record.find(i) != record.end()) {
                resultSet.insert(i);
            }
        }

        vector<int> res;
        for (int iter : resultSet) {
            res.push_back(iter);
        }

        return res;
    }
};

// c++11
// 使用unordered_set
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> record(nums1.begin(), nums1.end());

        unordered_set<int> resultSet;

        for (int i : nums2) {
            if(record.find(i) != record.end()) {
                resultSet.insert(i);
            }
        }

        return vector<int>(resultSet.begin(), resultSet.end());
    }
};