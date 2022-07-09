struct Node {
    int val;
    int index;
};

bool compare(const void* p1, const void* p2) {
    struct Node* v1 = (struct Node*)p1;
    struct Node* v2 = (struct Node*)p2;
    return (v1->val == v2->val) ? (v1->index > v2->index) : (v1->val > v2->val);
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    struct Node* node;
    
    if (numsSize < 2) {
        return false;
    }
    
    node = malloc(numsSize * sizeof(struct Node));
    for (int i = 0; i < numsSize; i++) {
        (node + i)->val = nums[i];
        (node + i)->index = i;
    }
    
    qsort(node, numsSize, sizeof(struct Node), compare);
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (((node + i)->val == (node + j)->val)
                && ((node + j)->index - (node + i)->index <= k)) {
                return true;
            }
            else {
                break;
            }
        }
    }
    
    free(node);
        
    return false;
}