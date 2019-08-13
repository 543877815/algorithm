

int sumOfDigits(int* A, int ASize){
    int min = 9999;
    for (int i = 0; i < ASize; i++) {
        if (min > A[i]) min = A[i];
    }
    int ans = 0;
    while(min != 0){
        int carry = min % 10;
        ans += carry;
        min /= 10;
    }
    return ans % 2 == 0 ? 1 : 0;
}

