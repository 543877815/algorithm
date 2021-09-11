// 贪心算法
// 时间复杂度：O(m) 单词长度之和
// 空间复杂度：O(1)
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        int n = words.size();
        int left = 0, right = 0;
        vector<string> res;
        while (left < n) {
            int letter_count = 0, blank_count = 0;
            while (right < n && letter_count + blank_count + words[right].size() <= maxWidth) {
                letter_count += words[right].size();
                blank_count++;
                right++;
            }
            int num = right - left;
            string tmp = "";
            if (num == 1) { // 只有一个单词
                tmp += words[left++] + string(maxWidth - letter_count, ' ');
            } else if (right == n) { // 最后一行
                while (left != right) {
                    tmp += words[left++];
                    if (tmp.size() < maxWidth) tmp += " ";
                }
                tmp += string(maxWidth - tmp.size(), ' ');
            } else {  // 平常情况
                blank_count = maxWidth - letter_count;
                while (left < right - 1) {
                    int avg_blank = blank_count / (num - 1);
                    int remain_blank = blank_count % (num - 1);
                    avg_blank += remain_blank == 0 ? 0 : 1;
                    tmp += words[left++];
                    tmp += string(avg_blank, ' ');
                    blank_count -= avg_blank;
                    num--;
                }
                tmp += words[left++];
                int tmpsize = tmp.size();
                int b = 0;
            }
            res.push_back(tmp);
        }

        return res;
    }
};