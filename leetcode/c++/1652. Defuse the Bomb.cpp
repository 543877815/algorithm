// 滑动窗口
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> decrypt(vector<int> &code, int k) {
        int n = code.size();
        vector<int> res(n);
        if (k == 0) {
            for (int i = 0; i < n; i++) {
                res[i] = 0;
            }
        } else if (k > 0) {
            int left = 1;
            int right = 1;
            int summation = 0;
            int counter = 0;
            while (counter < k) {
                summation += code[right];
                right = (right + 1) % n;
                counter++;
            }
            for (int i = 0; i < n; i++) {
                res[i] = summation;
                summation -= code[left];
                summation += code[right];
                left = (left + 1) % n;
                right = (right + 1) % n;
            }
        } else {
            int left = n - 2;
            int right = n - 2;
            int summation = 0;
            int counter = 0;
            while (counter > k) {
                summation += code[left];
                left = (left - 1 + n) % n;
                counter--;
            }
            for (int i = n - 1; i >= 0; i--) {
                res[i] = summation;
                summation += code[left];
                summation -= code[right];
                left = (left - 1 + n) % n;
                right = (right - 1 + n) % n;
            }
        }
        return res;
    }
};
