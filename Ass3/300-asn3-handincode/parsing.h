#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int parsingNumberOfInputFiles(char* path) {
  
    FILE * fp;
    fp = fopen(path, "r");

    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }
    char line[256];
    int num;
    

   
    while(fgets(line,20,fp)){
        int hasInt = 0;
        for(int i = 0; line[i]!='\0';i++){
            if(isdigit(line[i])){
            num = atoi(&line[i]);
            hasInt = 1;
            break;
            }
        }    
        if(hasInt){
            break;
        }
    }
    fclose(fp);
    return num;

}