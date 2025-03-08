int strlen(char *dizi){
    int counter = 0;
    while(*dizi != '\0'){
        dizi++;
        counter++;
    }
    return counter;
}