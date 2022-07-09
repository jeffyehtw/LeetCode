typedef struct {
    int* stack;
    int size;
} MyStack;

MyStack* myStackCreate() {
    MyStack* ret = malloc(sizeof(MyStack));
    ret->stack = NULL;
    ret->size = 0;
    return ret;
}

void myStackPush(MyStack* obj, int x) {
    int* new = malloc((obj->size + 1) * sizeof(int));
    
    if (obj->stack) {
        memcpy(new, obj->stack, obj->size * sizeof(int));
        free(obj->stack);
    }
    new[obj->size] = x;
    obj->stack = new;
    obj->size++;
}

int myStackPop(MyStack* obj) {
    int ret = myStackTop(obj);
    int* new = malloc((obj->size - 1) * sizeof(int));
    
    memcpy(new, obj->stack, (obj->size - 1) * sizeof(int));
    free(obj->stack);
    obj->stack = new;
    obj->size--;
    
    return ret;
}

int myStackTop(MyStack* obj) {
    return obj->stack[obj->size - 1];
}

bool myStackEmpty(MyStack* obj) {
    return obj->size == 0;
}

void myStackFree(MyStack* obj) {
    free(obj->stack);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/