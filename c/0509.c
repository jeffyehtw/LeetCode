int fib(int n) {
    int table[31];
    
    memset(&table, 0, sizeof(table));
    
    table[0] = 0;
    table[1] = 1;
    for (int i = 2; i <= n; i++) {
        table[i] = table[i - 1] + table[i - 2];
    }
    
    return table[n];
}