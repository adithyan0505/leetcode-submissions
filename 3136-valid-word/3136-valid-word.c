bool isValid(char* word) {
    if (strlen(word) >= 3) {
        bool vowel = false, cons = false, type = true;
        for (int i = 0; i < strlen(word); i++) {
            if (!(isdigit(word[i]) || isalpha(word[i]))) {
                type = false;
                break;
            }
            if (isalpha(word[i])) {
                if (word[i] == 'a' || word[i] == 'A' || word[i] == 'e' ||
                    word[i] == 'E' || word[i] == 'i' || word[i] == 'I' ||
                    word[i] == 'o' || word[i] == 'O' || word[i] == 'u' ||
                    word[i] == 'U')
                    vowel = true;
                else
                    cons = true;
            }
        }
        if (type && vowel && cons)
            return true;
    }
    return false;
}