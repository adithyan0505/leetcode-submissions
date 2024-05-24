char* reversePrefix(char* word, char ch) {
    int i = 0, ind = 0, j;
    while (word[i]!='\0')
        i++;
    while (word[ind] != ch)
        if (ind < i)
            ind++;
        else
            break;
    if (ind != i)
    {    for (j = 0; j <= ind/2; j++)
        {    
            char temp = word[j];
            word[j] = word[ind - j];
            word[ind - j] = temp;
        }
    }
    return word;
}