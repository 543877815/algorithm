// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
// 时间复杂度：O(1)
// 空间复杂度：O(1)
class Solution {
public:
    int rand10() {
        int res = 41;
        while (res > 40) {
            res = (rand7() - 1) * 7 + rand7();
        }
        return res % 10 + 1;
    }
};

// 通过 rand2 和 rand5 来构造
// 时间复杂度：O(1)
// 空间复杂度：O(1)
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

int rand2() {
    int x = 7;
    while (x == 7) {
        x = rand7();
    }
    return x % 2 + 1;
}

int rand5() {
    int x = 6;
    while (x > 5) {
        x = rand7();
    }
    return x % 5 + 1;
}

class Solution {
public:
    int rand10() {
        int x = rand2();
        int y = rand5();
        if (x == 1) {
            return 2 * y;
        } else {
            return 2 * y - 1;
        }
    }
};