int scoreOfString(char* s) {
    int score = 0;
    for(int i=1; i < strlen(s);i++)
        score += abs(s[i]-s[i-1]);
    return score;
}