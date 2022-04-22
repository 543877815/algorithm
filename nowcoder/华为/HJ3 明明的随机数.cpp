#include<iostream>
#include<vector>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> array(501, 0);
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        array[a]=1;
    }

    for (int i = 0; i < 501; i++) {
        if (array[i] != 0) {
            cout << i << endl;
        }
    }

    return 0;
}