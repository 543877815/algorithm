// 时间复杂度：O(1)
// 空间复杂度：O(1)
class Solution {
private:
    static constexpr int TARGET = 24;
    static constexpr double EPSILON = 1e-6;
    static constexpr int ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVIDE = 3;
public:
    bool judgePoint24(vector<int> &nums) {
        vector<double> numbers;
        for (const int &num : nums) numbers.emplace_back(static_cast<double>(num));
        return solve(numbers);
    }

    bool solve(vector<double> &numbers) {
        int n = numbers.size();
        if (n == 0) return false;
        if (n == 1) return fabs(numbers[0] - TARGET) < EPSILON;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    vector<double> list;
                    for (int k = 0; k < n; k++) {
                        if (k != i && k != j) {
                            list.emplace_back(numbers[k]);
                        }
                    }
                    for (int k = 0; k < 4; k++) {
                        if (k < 2 && i > j) continue; // 加法和乘法满足交换律，可以跳过
                        if (k == ADD) list.emplace_back(numbers[i] + numbers[j]);
                        else if (k == MULTIPLY) list.emplace_back(numbers[i] * numbers[j]);
                        else if (k == SUBTRACT) list.emplace_back(numbers[i] - numbers[j]);
                        else if (k == DIVIDE) {
                            if (fabs(numbers[j]) < EPSILON) continue;
                            list.emplace_back(numbers[i] / numbers[j]);
                        }

                        if (solve(list)) return true;
                        list.pop_back();
                    }
                }
            }
        }
        return false;
    }
};