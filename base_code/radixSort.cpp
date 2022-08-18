#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

void radixSort(vector<int> &nums) {
    int n = nums.size();
    int max_value = *max_element(nums.begin(), nums.end());
    int exp = 1;
    vector<int> tmp(n);
    while (exp <= max_value) {
        vector<int> cnt(10);
        for (int i = 0; i < n; i++) {
            int digit = (nums[i] / exp) % 10;
            cnt[digit]++;
        }
        for (int i = 1; i < 10; i++) {
            cnt[i] += cnt[i-1];
        }
        for (int i = n - 1; i >= 0; i--) {
            int digit = (nums[i] / exp) % 10;
            tmp[cnt[digit] - 1] = nums[i];
            cnt[digit]--;
        }
        exp *= 10;
        copy(tmp.begin(), tmp.end(), nums.begin());
    }
}

int main() {

    vector<int> arr = {112, 141, 52, 312, 456, 382, 420, 415, 234, 257};
    radixSort(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}