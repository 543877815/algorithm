
#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int col = 1;
    int num = 1;
    int curr = 1;
    for (int i = 0; i < n; i++) {
        int row = 2 + i;
        for (int j = 0; j < n - i; j++) {
            cout << curr << " ";
            curr += row;
            row++;
        }
        cout << endl;
        curr = col + i + 1;
        col += i + 1;
    }
}