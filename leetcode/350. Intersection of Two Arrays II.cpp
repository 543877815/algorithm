// 时间复杂度：O(m+n)
// 空间复杂度：O(min(m,n))
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> record;
        vector<int> resultVector;

        for (int i = 0; i < nums1.size(); i++) {
            record[nums1[i]]++;
        }

        for (int i = 0; i < nums2.size(); i++) {
            if (record[nums2[i]] > 0) {
                resultVector.push_back(nums2[i]);
                record[nums2[i]] --;
            }
        }

        return resultVector;
    }
};


// c++11
// 使用unordered_map
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> record;
        vector<int> resultVector;

        for (int i : nums1) {
            record[i]++;
        }

        for (int i : nums2) {
            if (record[i] > 0) {
                resultVector.push_back(i);
                record[i] --;
            }
        }

        return resultVector;
    }
};