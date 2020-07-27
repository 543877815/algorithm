#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <stack>
#include <math.h>

using namespace std;


// 时间复杂度：O(n)
// 空间复杂度：O(n)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string opera = "+-*/";
        stack <char> chars;
        stack <int> nums;
        int result, num1, num2;
        for (int i = 0; i < tokens.size(); i++) {
            if (opera.find(tokens[i]) == opera.npos) {
                nums.push(stoi(tokens[i])); // 操作数
            } else {
                num1 = nums.top();
                nums.pop();
                num2 = nums.top();
                nums.pop();
                switch(opera.find(tokens[i])) {
                    case 0:
                        result = num2 + num1;
                        break;
                    case 1:
                        result = num2 - num1;
                        break;
                    case 2:
                        result = num2 * num1;
                        break;
                    case 3:
                        result = num2 / num1;
                        break;
                }
                nums.push(result);
            }
        }
        return nums.top();
    }
};
int main() {
    vector<string> a= {"4", "13", "5", "/", "+"};

    Solution c = Solution();
    c.evalRPN(a);
}