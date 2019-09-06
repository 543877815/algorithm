

bool isPowerOfTwo(int n){
    if (n % 2 == 1 && n != 1) return false;
    long long int ans = 1;
    while(ans != n) {
        if (ans > n) return false;
        ans *= 2;
    }
    return true;
}

