/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize){
    int aliceSum = 0;
    int bobSum = 0;
    int avg = 0;
    bool table[200001];
    int* ret = malloc(2 * sizeof(int));
    
    memset(table, false, sizeof(table));
    memset(ret, 0, sizeof(ret));
    
    *returnSize = 2;
    
    for (int i = 0; i < aliceSizesSize; i++) {
        aliceSum += aliceSizes[i];
    }
    for (int i = 0; i < bobSizesSize; i++) {
        bobSum += bobSizes[i];
    }
    
    avg = (aliceSum + bobSum) >> 1;
    if (aliceSum - avg > 0) {
        for (int i = 0; i < bobSizesSize; i++) {
            table[aliceSum - avg + bobSizes[i]] = true;
        }
        for (int i = 0; i < aliceSizesSize; i++) {
            if (table[aliceSizes[i]] == true) {
                ret[0] = aliceSizes[i];
                ret[1] = aliceSizes[i] - (aliceSum - avg);
                break;
            }
        }
    }
    else {
        for (int i = 0; i < aliceSizesSize; i++) {
            table[bobSum - avg + aliceSizes[i]] = true;
        }
        for (int i = 0; i < bobSizesSize; i++) {
            if (table[bobSizes[i]] == true) {
                ret[0] = bobSizes[i] - (bobSum - avg);
                ret[1] = bobSizes[i];
                break;
            }
        }
    }
    
    return ret;    
}