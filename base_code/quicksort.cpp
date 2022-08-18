#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &arr, int left, int right) {
    int pos = arr[left];
    while (left < right) {
        while (left < right && arr[right] >= pos) right--;
        arr[left] = arr[right];
        while (left < right && arr[left] <= pos) left++;
        arr[right] = arr[left];
    }
    arr[left] = pos;
    return left;
}

void quicksort(vector<int> &arr, int left, int right) {
    if (left == right) return;
    int pos = partition(arr, left, right);
    quicksort(arr, left, pos - 1);
    quicksort(arr, pos + 1, right);

}

int main() {
    vector<int> arr = {3, 4, 5, 2, 4, 1, 5, 7, 8, 3};

    int n = arr.size();
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}