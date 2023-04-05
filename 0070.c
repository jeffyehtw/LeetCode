int climbStairs(int n) {
    int table[46] = { 0 };
    
    table[0] = 1;
    table[1] = 1;
    for (int i = 2; i <= n; i++) {
        table[i] = table[i - 2] + table[i - 1];
    }
    
    return table[n];
}