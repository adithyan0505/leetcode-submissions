char bitwiseXOR(char p, char q) {
    if (((p == '0') && (q == '1')) || ((p == '1') && (q == '0')))
        return '1';
    return '0';
}

char bitwiseOR(char p, char q) {
    if ((p == '0') && (q == '0'))
        return '0';
    return '1';
}

char bitwiseAND(char p, char q) {
    if ((p == '1') && (q == '1'))
        return '1';
    return '0';
}

char* addBinary(char* a, char* b) {
    int k;
    if (strlen(a) > strlen(b))
        k = strlen(a) + 1;
    else
        k = strlen(b) + 1;
    char* sum_array = (char*)malloc(k + 1);
    int i = strlen(a) - 1, j = strlen(b) - 1;
    sum_array[k--] = '\0';
    char carry = '0';
    while ((i >= 0) && (j >= 0)) {
        sum_array[k--] = bitwiseXOR(bitwiseXOR(a[i], b[j]), carry);
        carry = bitwiseOR(bitwiseAND(a[i--], b[j--]),
                          bitwiseAND(bitwiseXOR(a[i], b[j]), carry));
    }
    while (i >= 0) {
        sum_array[k--] = bitwiseXOR(bitwiseXOR(a[i], '0'), carry);
        if (carry != '0')
            carry = bitwiseOR(bitwiseAND(a[i--], '0'),
                              bitwiseAND(bitwiseXOR(a[i], '0'), carry));
        else
            i--;
    }
    while (j >= 0) {
        sum_array[k--] = bitwiseXOR(bitwiseXOR('0', b[j]), carry);
        if (carry != '0')
            carry = bitwiseOR(bitwiseAND('0', b[j--]),
                              bitwiseAND(bitwiseXOR('0', b[j]), carry));
        else
            j--;
    }
    if (carry == '1') {
        sum_array[k] = carry;
        return sum_array;
    }
    return sum_array + 1;
}