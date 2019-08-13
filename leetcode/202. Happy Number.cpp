

bool isHappy(int n){
    int iter = 0;
    while(iter!=100){
        int happy = 0;
        while(n!=0) {
            int num = n % 10;
            happy += num * num;
            n /= 10;
        }
        if (happy == 1) return true;
        n = happy;
        iter ++;
    }
    return false;
}

