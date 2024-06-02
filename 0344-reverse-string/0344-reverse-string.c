void reverseString(char* s, int size) {
    int i = 0;
    while(i < size-1-i)
    {
        char temp = s[size-1-i];
        s[size-1-i] = s[i];
        s[i++] = temp;
    }
}