void fulan(int** grid, int gridSize, int* gridColSize, int* time, int** mark) {
   
    
    // 更新状态
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if(mark[i][j] != -1) mark[i][j] = grid[i][j]; 
        }
    }
    
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            printf("%d ", mark[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    int flag = 0; // 标志更改位
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (mark[i][j] == 2) {
                mark[i][j] = -1;
                flag = 1;
                if (i > 0 && grid[i-1][j] == 1 && mark[i-1][j] != -1) grid[i-1][j] = 2;
                if (j > 0 && grid[i][j-1] == 1 && mark[i][j-1] != -1) grid[i][j-1] = 2;
                if (i < gridSize - 1 && grid[i+1][j] == 1 && mark[i+1][j] != -1) grid[i+1][j] = 2;
                if (j < gridColSize[i] - 1 && grid[i][j+1] == 1 && mark[i][j+1] != -1) grid[i][j+1] = 2;
            }
        }
    }

    if (flag == 1) {
        (*time)++;
        fulan(grid, gridSize, gridColSize, time, mark);
    } else {
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridColSize[i]; j++) {
                if(mark[i][j] == 1) {
                    (*time) = 0;
                    return;
                }
            }
        }
    }
}

int orangesRotting(int** grid, int gridSize, int* gridColSize){
    // 统计有没有1
    int flag = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) break;
    }
    if (flag == 0) return 0;
    
    // 拷贝一份
    int ** mark = (int **)malloc(sizeof(int*) * gridSize);
    for (int i = 0 ; i < gridSize; i++) {
        mark[i] = (int *)malloc(sizeof(int)* gridColSize[i]);
    }
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            mark[i][j] = grid[i][j];
        }
    }
    // 
    int time = 0;
    fulan(grid, gridSize, gridColSize, &time, mark);
    return time - 1;
}

