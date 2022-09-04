// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(n)
// ����ջ
class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        vector<int> res = {-1, -1};
        int n = array.size();
        if (n == 0) return res;
        stack<int> sk;
        for (int i = 0; i < n; i++) {
            while (!sk.empty() && sk.top() <= array[i]) {
                sk.pop();
            }
            if (!sk.empty()) res[1] = i;
            sk.push(array[i]);

        }
        sk = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!sk.empty() && sk.top() >= array[i]) {
                sk.pop();
            }
            if (!sk.empty()) res[0] = i;
            sk.push(array[i]);
        }
        return res;
    }
};