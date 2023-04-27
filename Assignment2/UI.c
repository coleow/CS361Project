#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>


int runner(){
    while(1){
        printf("Press 1 to generate a picture. Press 2 to quit: ");
        int choice;
        char test[] = "Run";
        scanf("%d", &choice);
        if(choice == 1){
            FILE* writefile = fopen("prng-service.txt", "w");
            fprintf(writefile, "%s", test);
            fclose(writefile);
            
            printf("Waiting...\n");

            for(int i = 0; i < 5; i++){
                Sleep(1000);
                printf(".\n");
            }

            FILE* readfile = fopen("prng-service.txt", "r");
            int randNum;
            fscanf(readfile, "%d", &randNum);
            fclose(fopen("image-service.txt", "w"));
            fclose(readfile);

            FILE* writefile2 = fopen("image-service.txt", "w");
            fprintf(writefile2, "%d", randNum);
            fclose(writefile2);

            printf("Waiting...\n");

            for(int i = 0; i < 5; i++){
                Sleep(1000);
                printf(".\n");
            }

            FILE* readfile2 = fopen("image-service.txt", "r");
            char url[100];
            fgets(url, 100, readfile2);
            printf("Your picture is located here: %s\n", url);
            fclose(readfile2);
        }
        else if(choice == 2){
            printf("Goodbye!!");
            return 0;
        }
        else{
            printf("Invalid choice\n");
            runner();
            return 0;
        }
    }
}

int main(){
    runner();
    return 0;
}