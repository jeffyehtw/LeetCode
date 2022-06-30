int count_bits(int x) {
    int count = 0;
    
    while (x > 0) {
        count += (x & 1) == 1;
        x >>= 1;    
    }
    return count;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX 1000001
int* countBits(int n, int* returnSize) { 
    int table[MAX];
    int* ret = malloc((n + 1) * sizeof(int));
    
    memset(&table, -1, sizeof(table));
    memset(ret, 0, (n + 1) * sizeof(int));
    
    table[0] = 0;
    table[1] = 1;
    table[2] = 1;
    table[3] = 2;
    for (int i = 1; i < n + 1; i++) {
        if (table[i] == -1) {
            if (table[i - 1] == -1) {
                table[i] = count_bits(i);
            }
            else {
                table[i] = table[i - 1] + 1;
            }
        }
        for (int j = i << 1; j < n + 1; j <<= 1) {
            if (table[j] == -1) {
                table[j] = table[i];
            }
            else {
                break;
            }
            
        }
    }
    
    *returnSize = n + 1;
    memcpy(ret, &table, (n + 1) * sizeof(int));
    
    return ret;
}