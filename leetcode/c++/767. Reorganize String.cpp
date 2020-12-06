// 最大堆，优先队列，m是字符集
// 时间复杂度：O(nlog(m|+|m|)
// 空间复杂度：O(|m|)
class Solution {
public:
    string reorganizeString(string S) {
        int m = S.size();
        if (m <= 2) return S;
        vector<int> record(26, 0);
        int maxcount = 0;
        for (int i = 0; i < m; i++) {
            int tmp = S[i] - 'a';
            record[tmp]++;
            maxcount = max(maxcount, record[tmp]);
        }
        if (maxcount * 2 > m + 1) return "";
        auto cmp = [&](const char &letter1, const char &letter2) {
            return record[letter1 - 'a'] < record[letter2 - 'a'];
        };
        priority_queue<char, vector<char>, decltype(cmp)> queue{cmp};
        for (char c = 'a'; c <= 'z'; c++) {
            if (record[c - 'a'] > 0) {
                queue.push(c);
            }
        }
        string res;
        while (queue.size() > 1) {
            char letter1 = queue.top();
            queue.pop();
            char letter2 = queue.top();
            queue.pop();
            res += letter1;
            res += letter2;
            int index1 = letter1 - 'a', index2 = letter2 - 'a';
            record[index1]--;
            record[index2]--;
            if (record[index1] > 0) queue.push(letter1);
            if (record[index2] > 0) queue.push(letter2);
        }
        if (queue.size() > 0) res += queue.top();
        return res;
    }
};

// 基于计数的贪心算法，m为字符集
// 时间复杂度：O(n+m)
// 空间复杂度：O(n+m)
class Solution {
public:
    string reorganizeString(string S) {
        int m = S.size();
        if (m <= 2) return S;
        vector<int> record(26, 0);
        int maxcount = 0;
        for (int i = 0; i < m; i++) {
            int tmp = S[i] - 'a';
            record[tmp] ++;
            maxcount = max(maxcount, record[tmp]);
        }
        if (maxcount * 2 > m + 1) return "";
        string new_S(m, ' ');
        int evenIndex = 0, oddIndex = 1;
        int halfLength = m / 2;
        for (int i = 0; i < 26; i++) {
            char c = ('a' + i);
            while (record[i] > 0 && record[i] <= halfLength && oddIndex < m) {
                new_S[oddIndex] = c;
                record[i] --;
                oddIndex += 2;
            }
            while (record[i] > 0) {
                new_S[evenIndex] = c;
                record[i] --;
                evenIndex += 2;
            }
        }
        return new_S;

    }
};