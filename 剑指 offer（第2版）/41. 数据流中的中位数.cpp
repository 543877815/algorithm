/*
 * 数据结构         插入的时间复杂度        得到中位数的时间复杂度
 * 没有排序的数组   O(1)                    O(n)
 * 排序的数组       O(n)                    O(1)
 * 排序的链表       O(n)                    O(1)
 * 二叉搜索树       平均O(logn)，最差O(n)   平均O(logn)，最差O(n)
 * AVL树            O(logn)                 O(1)
 * 最大堆和最小堆   O(logn)                 O(1)
 */

// 最大堆和最小堆
// 最大堆降序
// 最小堆升序
// 元素 最小堆>=最大堆
// 最大堆所有的数据都要小于最小堆中的数据

// 使用vector
class MedianFinder {
private:
    vector<int> min_heap;
    vector<int> max_heap;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        // 如果是偶数
        if (((min_heap.size() + max_heap.size()) & 1) == 0) {
            if (max_heap.size() > 0 && num < max_heap[0]) {
                max_heap.push_back(num);
                push_heap(max_heap.begin(), max_heap.end(), less<int>());

                num = max_heap[0];

                pop_heap(max_heap.begin(), max_heap.end(), less<int>());
                max_heap.pop_back();
            }
            min_heap.push_back(num);
            push_heap(min_heap.begin(), min_heap.end(), greater<int>());
        } else { // 如果是奇数
            if (min_heap.size() > 0 && min_heap[0] < num) {
                min_heap.push_back(num);
                push_heap(min_heap.begin(), min_heap.end(), greater<int>());

                num = min_heap[0];

                pop_heap(min_heap.begin(), min_heap.end(), greater<int>());
                min_heap.pop_back();
            }
            max_heap.push_back(num);
            push_heap(max_heap.begin(), max_heap.end(), less<int>());
        }
    }

    double findMedian() {
        if (((min_heap.size() + max_heap.size()) & 1) == 1) return min_heap[0]; // 如果是奇数
        return ((min_heap[0] + max_heap[0]) / (double) 2); // 如果是偶数
    }
};


// 使用priority_queue
class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> min_heap;
    priority_queue<int, vector<int>, greater<int>> max_heap;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        // 如果是偶数
        if (((min_heap.size() + max_heap.size()) & 1) == 0) {
            if (max_heap.size() > 0 && num > max_heap.top()) {
                max_heap.push(num);
                num = max_heap.top();
                max_heap.pop();
            }
            min_heap.push(num);
        } else {
            if (min_heap.size() > 0 && num < min_heap.top()) {
                min_heap.push(num);
                num = min_heap.top();
                min_heap.pop();
            }
            max_heap.push(num);
        }
    }

    double findMedian() {
        if (((min_heap.size() + max_heap.size()) & 1) == 1) return min_heap.top();
        else return (min_heap.top() + max_heap.top()) / double(2);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */