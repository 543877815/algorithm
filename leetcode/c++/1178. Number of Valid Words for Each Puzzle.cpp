// 哈希表+位运算
// 时间复杂度：O(m|w|+n*2^p)  m 和 n 分别是数组 words 和 puzzles 的长度，|w| 是 word 的最大长度 50， |p| 是 puzzle 的最大长度 7
// 空间复杂度：O(m)
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> frequency;  // work 的字母频率
        for (const auto& word: words) {
            int mask = 0;  // word 的位哈希值
            for (char ch: word) {
                mask |= (1 << (ch - 'a'));
            }
            // 如果 work 太大则丢弃
            if (__builtin_popcount(mask) <= 7) {
                frequency[mask]++;
            }
        }

        vector<int> res;
        for (const auto& puzzle: puzzles) {
            int total = 0;
            int mask = 0;
            for (int i = 1; i < 7; i++) {
                mask |= (1 << (puzzle[i] - 'a'));
            }
            int subset = mask; // puzzle 缺少首字母的位哈希值
            // 枚举二进制子集
            do {
                int s = subset | (1 << (puzzle[0] - 'a'));
                if (frequency.count(s)) {
                    total += frequency[s];
                }
                subset = (subset - 1) & mask;
            } while (subset != mask);

            res.push_back(total);
        }

        return res;
    }
};