int appendCharacters(char* s, char* t) {
    int si = 0, ti = 0;
    while ((s[si] != '\0') && (t[ti] != '\0')) {
        if (s[si] == t[ti]) {
            si++;
            ti++;
        } else
            si++;
    }
    return strlen(t) - ti;
}