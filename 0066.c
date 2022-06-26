/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int carry = 1;
    int* ret = NULL;
    
    for (int i = digitsSize - 1; i > -1; i--) {
        digits[i] += carry;
        carry = digits[i] / 10;
        digits[i] %= 10;
    }
    
    if (carry == 0) {
        *returnSize = digitsSize;
        ret = malloc(digitsSize * sizeof(int));
        memcpy(ret, digits, digitsSize * sizeof(int));
    }
    else {
        *returnSize = digitsSize + 1;
        ret = malloc((digitsSize + 1) * sizeof(int));
        ret[0] = carry;
        memcpy(ret + 1, digits, digitsSize * sizeof(int));
    }
    
    return ret;
}