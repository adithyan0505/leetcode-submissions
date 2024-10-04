void count_sort(int* skill,int skillSize){
    int max=0;
    for(int i=0;i<skillSize;i++){
        if(skill[i]>max)
            max=skill[i];
    }
    int count[max+1];
    for(int i=0;i<=max;i++) count[i]=0;
    for(int i=0;i<skillSize;i++) count[skill[i]]++;
    for(int i=1;i<=max;i++) count[i] += count[i-1];
    int out[skillSize];
    for(int i=skillSize-1;i>=0;i--){
        out[count[skill[i]]-1] = skill[i];
        count[skill[i]]--;
    }
    for(int i=0;i<skillSize;i++)
        skill[i] = out[i];
}

long long dividePlayers(int* skill, int skillSize) {
    count_sort(skill,skillSize);
    int equal_skill = skill[0]+skill[skillSize-1];
    long long chemistry = skill[0]*skill[skillSize-1];
    for(int i=1;i<skillSize/2;i++){
        if(skill[i]+skill[skillSize-i-1]==equal_skill)
            chemistry += skill[i]*skill[skillSize-i-1];
        else
            return -1;
    }
    return chemistry;
}