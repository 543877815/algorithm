

bool isUgly(int num){
    if (num <= 0) return false;
    if (num == 1) return true;
    
    int arr[3] = {2, 3, 5};
    
    for (int i = 0; i < 3; i++) {
        while(num % arr[i] == 0) {
            num /= arr[i];
        }
    }
    
    for (int i = 0; i < 3; i++) {
        if (num == 1) return true;
    }
    return false;
}

