bool isValid(char* s) {
    int len = 0;
    for(int i=0;s[i]!='\0';i++)
        len++;
    if (len % 2 != 0) return false;
    char* stack = (char*)malloc(len);
    int ind = 0;
    int top = -1;
    while ((s[ind] == '[') || (s[ind] == ']') || (s[ind] == '(') ||
           (s[ind] == ')') || (s[ind] == '{') || (s[ind] == '}')) {
        if (s[ind] == '(') {
            top++;
            stack[top] = '(';
            ind++;
        } 
        else if (s[ind] == '[') {
            top++;
            stack[top] = '[';
            ind++;
        } 
        else if (s[ind] == '{') {
            top++;
            stack[top] = '{';
            ind++;
        } 
        else if ((s[ind] == ')') || (s[ind] == ']') || (s[ind] == '}')) {
            if (top == -1)
                return false;
            else if (((s[ind] == ')')&&(stack[top] == '('))||((s[ind] == ']')&&(stack[top] == '['))||((s[ind] == '}')&&(stack[top] == '{'))) {
                top--;
                ind++;
            }
            else
                return false;
        }
    }
    if (top == -1)
        return true;
    else
        return false;
}