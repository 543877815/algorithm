long long F[90]= {0};

int climbStairs(int n){
    F[1] = 1;
    F[2] = 2;
    for (int i = 3; i < 90; i++){
        F[i] = F[i-1] + F[i-2];
    }
    return F[n];
}

