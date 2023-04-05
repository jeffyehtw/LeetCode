int numJewelsInStones(char* J, char* S) {
    // var
    int num = 0;
    bool map[256] = { 0 };

    for (int i = 0; i < strlen(J); i++)
        map[J[i]] = 1;

    for (int i = 0; i < strlen(S); i++)
        num += map[S[i]] == 1;

    return num;
}
