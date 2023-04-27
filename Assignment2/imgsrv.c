#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>

int main(){
    printf("imgsrv Program Running:\n");
    while(1){
    Sleep(1000);
    FILE* readfile = fopen("image-service.txt", "r");
    int randNum = 0;
    fscanf(readfile, "%d", &randNum);
    fclose(readfile);
    if(randNum != 0){
        FILE* writefile = fopen("image-service.txt", "w");
        fprintf(writefile, "C:/Users/owend/VS Code Projects/CS 361/Assignment2/images/%d.jpg", randNum);
        fclose(writefile);
    }
    }
    return 0;
}