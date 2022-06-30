#include<iostream>
#include<queue>
using namespace std;

int main() {
    int n;
    int k;
    cin >> n;
    cin >> k;
    int num;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> num;
        pq.push(num);
    }

    for (int i = 0; i < k; i++) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}