char findTheDifference(char* s, char* t) {
    int hash[26];
    for (int i = 0; i < 26; i++)
        hash[i] = 0;
    for (int i = 0; t[i] != '\0'; i++)
        hash[t[i] - 'a']++;
    for (int i = 0; s[i] != '\0'; i++)
        hash[s[i] - 'a']--;
    int i;
    for (i = 0; i < 26; i++)
        if (hash[i] == 1)
            break;
    return i + 'a';
}