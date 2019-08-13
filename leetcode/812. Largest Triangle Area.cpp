
double largestTriangleArea(int** points, int pointsSize, int* pointsColSize){
    double max_area = 0.0;
    for (int i = 0; i < pointsSize; i++) {
        for (int j = i + 1; j < pointsSize; j++) {
            for (int k = j + 1; k < pointsSize; k++) {
                double area = abs((points[i][0]*points[j][1] - points[j][0]*points[i][1])
                                 +(points[j][0]*points[k][1] - points[k][0]*points[j][1])
                                 +(points[k][0]*points[i][1] - points[i][0]*points[k][1])) / 2.0;
                if(area > max_area) max_area = area;
            }
        }
    }
    return max_area;
}

