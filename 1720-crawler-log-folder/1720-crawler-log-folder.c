int minOperations(char** logs, int logs_size) {
    int folder = 0;
    for(int i = 0;i < logs_size;i++)
    {
        if(strcmp(logs[i],"../") == 0)
        {
            if(folder)
                folder--;
        }
        else if(strcmp(logs[i],"./"))
            folder++;
    }
    return folder;
}