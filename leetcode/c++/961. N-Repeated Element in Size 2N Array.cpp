int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}


int repeatedNTimes(int* A, int ASize){
    qsort(A, ASize, sizeof(int), cmp);
    if (A[ASize / 2 + 1] == A[ASize / 2]) return A[ASize / 2];
    else return A[ASize / 2 - 1];
}

