// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    bool circularArrayLoop(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            bool positive = nums[i] > 0;
            int index = i;
            vector<int> tmp = {index};
            while (!visited[index]) {
                if ((nums[index] > 0) != positive) break;
                visited[index] = true;
                index = (index + nums[index] + n * 1000) % n;
                tmp.push_back(index);
            }
            int m = tmp.size();
            if (m != 1 && tmp[m - 1] != tmp[m - 2] && visited[index]) return true;
        }

        return false;
    }
};

// 快慢指针+查找循环链表的思路
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    bool circularArrayLoop(vector<int> &nums) {
        int n = nums.size();
        auto next = [&](int curr) {
            return ((curr + nums[curr]) % n + n) % n;
        };

        for (int i = 0; i < n; i++) {
            int slow = i, fast = next(i);

            while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0) {
                if (slow == fast) {
                    if (slow != next(slow)) return true;
                    else break;
                }
                slow = next(slow);
                fast = next(next(fast));
            }

            // 表示已经访问
            int add = i;
            while (nums[add] * nums[next(add)] > 0) {
                int tmp = add;
                add = next(add);
                nums[tmp] = 0;
            }
        }
        return false;
    }
};