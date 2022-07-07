/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** ret = NULL;
    
    *returnSize = numRows;
    ret = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    for (int i = 0; i < numRows; i++) {
        ret[i] = (int*)malloc(numRows * sizeof(int));
        ret[i][0] = 1;
        ret[i][i] = 1;
        (*returnColumnSizes)[i] = i + 1;
    }

    for (int i = 2; i < numRows; i++) {
        for (int j = 1; j < i; j++) {
            ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
        }
    }

    return ret;
}