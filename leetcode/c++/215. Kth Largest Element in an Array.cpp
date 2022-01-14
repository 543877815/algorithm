// 快速排序算法
// 时间复杂度:O(nlogn)
// 空间复杂度:O(1)


// 堆排序
// 时间复杂度:O(n+klogn)=O(nlogn)
// 空间复杂度:O(logn)
void swap(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void HeapShift(int array[], int size, int start) {
    int dad = start; // 父亲节点
    int son = 2 * dad + 1; // 儿子节点
    while (son <= size) {
        // 找子节点的最大值
        if (son + 1 <= size && array[son] > array[son + 1]) {
            son++;
        }
        if (array[dad] < array[son]) {
            return;
        } else {
            swap(&array[dad], &array[son]);
            // 查看交换是否导致子根结构混乱，若是，则向下调整；
            dad = son;
            son = 2 * dad + 1;
        }
    }
}


void HeapSort(int array[], int size) {
    // 构建初始堆
    for (int i = size / 2 - 1; i >= 0; i--) {
        HeapShift(array, size - 1, i);
    }
    for (int j = size - 1; j > 0; j--) {
        // 堆顶元素和堆中的最后一个元素交换
        swap(&array[0], &array[j]);
        // 重新调整结构，使其继续满足堆定义
        HeapShift(array, j - 1, 0);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    int Tarray[k];
    for (int i = 0; i < k; i++) {
        Tarray[i] = nums[i];
    }
    for (int i = k / 2 - 1; i >= 0; i--) {
        HeapShift(Tarray, k - 1, i);
    }

    // 维护小顶堆
    for (int j = k; j < numsSize; j++) {
        if (nums[j] > Tarray[0]) {
            Tarray[0] = nums[j];
            for (int i = k / 2 - 1; i >= 0; i--) {
                HeapShift(Tarray, k - 1, i);
            }
        }
    }
    HeapSort(Tarray, k);
    return Tarray[k - 1];
}


/**
############################################
 **/

// 快排序partition思路
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
};