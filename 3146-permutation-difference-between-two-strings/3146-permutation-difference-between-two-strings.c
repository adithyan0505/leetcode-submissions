int findPermutationDifference(char* s, char* t) {
    int diff = 0;
    int hash[26];
    for (int i = 0; i < strlen(s); i++)
        hash[s[i] - 'a'] = i;
    for (int i = 0; i < strlen(t); i++)
        diff += abs(hash[t[i] - 'a'] - i);
    return diff;
}