// 模拟
// 时间复杂度：O(n)
// 空间复杂度：O(n)
#include <iostream>
#include<sstream>

using namespace std;

int main() {
    string str;
    cin >> str;
    istringstream iss(str);
    string word;
    int x = 0, y = 0;
    while (getline(iss, word, ';')) {
        int n = word.size();
        int alpha_num = 0;
        int num = 0;
        bool isLegal = true;
        char direction = 'X';
        for (int i = 0; i < word.size(); i++) {
            if (isalpha(word[i])) {
                alpha_num++;
                if (alpha_num > 1 || word[i] == 'X') {
                    isLegal = false;
                    break;
                }
                direction = word[i];
            } else if (isdigit(word[i])) {
                num = num * 10 + (word[i] - '0');
            }
        }
        if (isLegal && direction != 'X') {
            if (direction == 'A') {
                x -= num;
            } else if (direction == 'D') {
                x += num;
            } else if (direction == 'S') {
                y -= num;
            } else if (direction == 'W') {
                y += num;
            }
        }
    }
    cout << x << "," << y << endl;
    return 0;
}