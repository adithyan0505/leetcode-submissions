bool isPalindrome(int x) {
    if(x<0)
        return false;
    long int rev=0,temp = x;
    while(temp!=0)
    {
        rev = temp%10 + 10*rev;
        temp = temp/10;
    }
    if(rev==x) 
        return true;
    return false;
}