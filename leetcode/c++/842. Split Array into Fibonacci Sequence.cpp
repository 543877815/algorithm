// 回溯和剪枝
// 时间复杂度：O(nlog^2C)
// 空间复杂度：O(n)
class Solution {
private:
    vector<int>res;
    int count = 0;
    bool found = false;
    void backtrack(string &S, int index) {
        int m = res.size();
        if (m >= 3) {
            long a = res[m - 1], b = res[m - 2], c = res[m - 3];
            if (b + c > INT_MAX) return;
            if (a != b + c) return;
            else if (count == S.size() && index == S.size()) found = true;
        }
        int num = 0;
        for (int i = index; i < S.size(); i++) {
            if (i > index && S[index] == '0') return;
            if (num >= INT_MAX / 10) return;
            num = num * 10 + (S[i] - '0');
            res.push_back(num);
            count+=to_string(num).size();
            backtrack(S, i+1);
            if (found) return;
            count-=to_string(res.back()).size();
            res.pop_back();
        }
    }

public:
    vector<int> splitIntoFibonacci(string S) {
        int index = 0;
        backtrack(S, index);
        return res;
    }
};