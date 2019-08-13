

int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int Perimeter = 0;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < *gridColSize; j++){
            if(grid[i][j] == 1){
                Perimeter += 4;
                if(i>0){
                    if(grid[i-1][j] == 1){
                        Perimeter -= 2;
                    }
                }
                if(j>0){
                    if(grid[i][j-1] == 1){
                        Perimeter -= 2;
                    }
                }
            }

        }
    }
    return Perimeter;
}

