// 自定义排序
// 时间复杂度：O(mlogm+n)
// 空间复杂度：O(logm+n)

class Solution {
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
        int m = arr1.size(), n = arr2.size();
        unordered_map<int, int> rank;
        for (int i = 0; i < n; i++) {
            rank[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&](int x, int y) {
            if (rank.count(x)) {
                // 如果 x 和 y 都出现在哈希表，则比较它们对应的值
                // 如果 x 在哈希表而 y 不在哈希表，x 应该在前面
                return rank.count(y) ? rank[x] < rank[y] : true;
            } else {
                // 如果 x 和 y 都没有在哈希表，则比较它们本身
                // 如果 x 不在哈希表而 y 在哈希表，则 y 应该在前面
                return rank.count(y) ? false : x < y;
            }
        });
        return arr1;
    }
};


// 计数排序
// 空间复杂度：O(m+n+upper)
// 时间复杂度：O(upper)
class Solution {
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
        int upper = *max_element(arr1.begin(), arr1.end());
        // 计数
        vector<int> frequency(upper + 1);
        for (int x : arr1) {
            frequency[x]++;
        }
        vector<int> ans;
        // 插入
        for (int x : arr2) {
            for (int i = 0; i < frequency[x]; i++) {
                ans.push_back(x);
            }
            frequency[x] = 0;
        }
        // 排序
        for (int x = 0; x <= upper; x++) {
            for (int i = 0; i < frequency[x]; i++) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};