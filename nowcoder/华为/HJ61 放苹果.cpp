#include<iostream>

using namespace std;

int res = 0;
void dfs(int apple, int plate, int num, int totalApple) {
    if (apple < 0) return;
    if (plate == 1 && apple >= num) {
        res++;
        return;
    }
    for (int i = num; i <= totalApple; i++) {
        dfs(apple - i, plate-1, i, totalApple);
    }
}

int main() {
    int apple, plate;
    cin >> apple >> plate;
    dfs(apple, plate, 0, apple);

    cout << res;
}