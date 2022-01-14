# algorithm

## 单调栈

### 困难

[84. 柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)

```
索引： [ 0, 1, 2, 3, 4, 5, 6, 7]
输入： [ 6, 7, 5, 2, 4, 5, 9, 3]
left: [-1, 0,-1,-1, 3, 4, 5, 3]
right:[2 , 2, 3, 8, 7, 7, 7, 8]
输出：16
```

思路：

- 构造 `left[i]`：存储的是元素 `i` 左边高度小于 `i` 的第一个元素的索引 `j`，`j`初始化为`-1`。
- 构造 `right[i]`：存储的是元素 `i` 右边高度小于 `j` 的第一个元素的索引 `k`,  `k`初始化为`n`。
- 如果直接构造 left 和 right 数组需要 $$O(n^2)$$ 的时间复杂度，通过单调栈来构造 left 和 right 的可以将时间复杂度降为 $$O(n)$$​​​​。
- 遍历计算得到面积最大的矩形。

[85. 最大矩形](https://leetcode-cn.com/problems/maximal-rectangle/)

思路：

- 构造 `left[i][j]`：作为矩形中行中的前缀和
- 类似第84题通过单调栈的方式来获取长和宽下界
- 通过入栈维护 `up[i]`，通过出栈来维护 `down[i]`

## 边界计数法

### 中等

[729. 我的日程安排表 I](https://leetcode-cn.com/problems/my-calendar-i/)

[731. 我的日程安排表 II](https://leetcode-cn.com/problems/my-calendar-ii/)

[732. 我的日程安排表 III](https://leetcode-cn.com/problems/my-calendar-iii/)

思路：

- 取区间的集合。
- 排序（如时间）。
- 从小到大遍历，有元素进入，该元素的计数+1，有元素退出，该元素的计数-1。
- 通过一个计数变量来维护当前时间有多少元素。

## 前缀树

### 中等

学习如何实现一个前缀树

[208. 实现 Trie (前缀树)](https://leetcode-cn.com/problems/implement-trie-prefix-tree/)

应用：

1. 通过字母建模

- [648. 单词替换](https://leetcode-cn.com/problems/replace-words/)
- [676. 实现一个魔法字典](https://leetcode-cn.com/problems/implement-magic-dictionary/)
- [820. 单词的压缩编码](https://leetcode-cn.com/problems/short-encoding-of-words/)
- [677. 键值映射](https://leetcode-cn.com/problems/map-sum-pairs/)

2. 通过bit建模

- [421. 数组中两个数的最大异或值](https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/)

## 线段树

### 中等

[729. 我的日程安排表 I](https://leetcode-cn.com/problems/my-calendar-i/)

线段树模板

```c++
class Node {
public:
    int start;
    int end;
    Node *left;
    Node *right;

    Node(int start, int end) {
        this->start = start;
        this->end = end;
        this->left = nullptr;
        this->right = nullptr;
    }

    bool insert(Node *node) {
        if (node->start >= end) {
            if (!right) {
                right = node;
                return true;
            }
            return right->insert(node);
        } else if (node->end <= start) {
            if (!left) {
                left = node;
                return true;
            }
            return left->insert(node);
        } else {
            return false;
        }
    }
};
```

本质上是一个二分搜索

## 哈希表

### 困难

[1036. 逃离大迷宫](https://leetcode-cn.com/problems/escape-a-large-maze/)

思路一：当搜索空间太大，其中的子空间构建哈希表，需要重新定义hash规则。

```c++
auto hash_fn = [fn = hash<long long>()](const pair<int, int>& o) -> size_t {
    auto& [x, y] = o;
    return fn((long long)x << 20 | y);  // 20 表示最大宽度为 2^20 ~= 10^6
};
unordered_set<pair<int, int>, decltype(hash_fn)> hash_blocked(0, hash_fn);
```

思路二：对横纵坐标进行离散化，再用基本的广度优先搜索来建模。

