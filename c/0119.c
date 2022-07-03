/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int table[34][34] = { 0 };
    int* ret;
    
    table[0][0] = 1;
    table[1][0] = 1;
    table[1][1] = 1;
    
    for (int i = 2; i <= rowIndex; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0 || j == i) {
                table[i][j] = 1;
            }
            else {
                table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
            }
        }
    }
        
    *returnSize = rowIndex + 1;
    ret = malloc((rowIndex + 1) * sizeof(int));
    memcpy(ret, &table[rowIndex], (rowIndex + 1) * sizeof(int));
    
    return ret;
}