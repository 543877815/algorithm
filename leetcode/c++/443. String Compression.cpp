// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    void myreverse(vector<char> &chars, int &idx, int count) {
        int tmp = idx;
        while (count != 0) {
            chars[idx++] = count % 10 + '0';
            count /= 10;
        }
        reverse(chars.begin() + tmp, chars.begin() + idx);
    }

    int compress(vector<char> &chars) {
        int n = chars.size();
        char last = ' ';
        int idx = 0;
        int count = 1;
        for (int i = 0; i < n; i++) {
            if (last != chars[i]) {
                if (last != ' ') {
                    chars[idx++] = last;
                    if (count != 1) myreverse(chars, idx, count);
                }
                last = chars[i];
                count = 1;
            } else {
                count++;
            }
        }
        if (idx < n) {
            chars[idx++] = last;
            if (count != 1) myreverse(chars, idx, count);
        }
        return idx;
    }
};