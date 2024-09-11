int minBitFlips(int start, int goal) {
    int flips = 0, xor = start^goal;
    while(xor){
        flips += xor%2;
        xor = xor/2;
    }
    return flips;
}