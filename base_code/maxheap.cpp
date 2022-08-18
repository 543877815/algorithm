#include<iostream>
#include<vector>

using namespace std;

void heapAdjust(vector<int> &arr, int n, int parent) {
    int max_son = 2 * parent + 1;
    if (max_son >= n) return;
    if (max_son + 1 < n && arr[max_son] < arr[max_son + 1]) max_son++; // 指向左右子节点中最大的值

    if (arr[parent] < arr[max_son]) {
        swap(arr[parent], arr[max_son]);
        heapAdjust(arr, n, max_son);
    }
}

void buildHeap(vector<int> &arr) {  // nlogn
    int n = arr.size();
    for (int i = (n - 1) / 2; i >= 0; i--) {
        heapAdjust(arr, n, i);
    }
}

void HeapSort(vector<int> &arr) {  // nlogn
    int n = arr.size();
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapAdjust(arr, i, 0);
    }
}

void Traversing(const vector<int> &arr) {
    for (int i: arr) {
        cout << i << " ";
    }
}

int main() {
    vector<int> arr = {4, 5, 8, 2, 3, 9, 7, 1};  // 图解 https://blog.csdn.net/qq_28063811/article/details/93034625/
    buildHeap(arr); // 构建大顶堆
    Traversing(arr);
    cout << endl;
    HeapSort(arr);
    Traversing(arr);
    return 0;
}