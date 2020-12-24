// 贪心算法
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        vector<int> left(n);
        for (int i = 0; i < n; i++) {
            if (i > 0 && ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            } else {
                left[i] = 1;
            }
        }

        int right;
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1 && ratings[i] > ratings[i + 1]) {
                right++;
            } else {
                right = 1;
            }

            res += max(right, left[i]);
        }

        return res;
    }
};


// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        int res = 1;
        int pre = 1;  // 上一个同学的糖果数目
        int dec = 0;  // 当前递减序列长度
        int inc = 1;  // 最近递增序列长度
        for (int i = 1; i < n; i++) {
            if (ratings[i] >= ratings[i - 1]) {
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                res += pre;
                inc = pre;
                dec = 0;
            } else {
                dec++;
                if (dec == inc) dec++;
                res += dec;
                pre = 1;
            }
        }
        return res;
    }
};