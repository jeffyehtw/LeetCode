void swap(int* p1, int* p2) {
    int i = *p1;
    *p1 = *p2;
    *p2 = i;
}

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    for (int i = 0; i < *matrixColSize >> 1; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            swap(&matrix[i][j], &matrix[*matrixColSize - 1 - i][j]);
        }
    }
    for (int i = 0; i < *matrixColSize; i++) {
        for (int j = 0; j < i; j++) {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }
}