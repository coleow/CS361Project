#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include <Windows.h>



int main(){
    printf("Prng Program Running:\n");
    char test[] = "Run";
    srand(time(NULL));
    while(1){
        Sleep(1000);
        FILE* readfile = fopen("prng-service.txt", "r");
        if(readfile == NULL){
            printf("File didn't open correctly. Terminating.");
            return 1;
        }
        char isRun[10];
        fscanf(readfile, "%s", isRun);
        int result = strcmp(test, isRun);
        
        if(result == 0){
            int randNum = rand() % 5 + 1;
            fclose((fopen("prng-service.txt", "w")));
            FILE* writefile = fopen("prng-service.txt", "w");
            fprintf(writefile, "%d", randNum);
            fclose(writefile);
        }
        fclose(readfile);
    }
    return 0;
}