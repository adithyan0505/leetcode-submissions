int lengthOfLastWord(char* s) {
    int len = 0, p, q;
    for (int i = 0; s[i] != '\0'; i++)
        len++;
    p = len - 1;
    while ((p >= 0) && (isspace(s[p])))
        p--;
    q = p;
    while ((q >= 0) && (!isspace(s[q])))
        q--;
    return (p - q);
}