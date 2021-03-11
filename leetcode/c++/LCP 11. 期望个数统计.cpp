// 排序+去重
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    int expectNumber(vector<int> &scores) {
        sort(scores.begin(), scores.end());
        return unique(scores.begin(), scores.end()) - scores.begin();
    }
};

// 使用哈希表
// 时间复杂度：O(n)
class Solution {
public:
    int expectNumber(vector<int> &scores) {
        unordered_set<int> Set;
        for (int i = 0; i < scores.size(); i++) {
            Set.insert(scores[i]);
        }

        return Set.size();
    }
};


class Solution {
public:
    int expectNumber(vector<int> &scores) {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < scores.size(); i++) {
            hashMap[scores[i]]++;
        }

        return hashMap.size();
    }
};