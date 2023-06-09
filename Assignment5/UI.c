#include <stdlib.h>
#include <stdio.h>
#include <string.h> 


void choice_1_final(char* name, char* wordphrase, char* username){
    printf("Program running until you input 0: \n");
    while(1){
        int inputted_value;
        scanf("%d", &inputted_value);
        if(inputted_value == 0){
            return;
        } 
    }
}

void choice_1_next_next(char* name, char* wordphrase){
    printf("If you would like, please enter a username you would like to track: ");
    char* inputted_string;
    scanf("%s", &inputted_string);
    choice_1_final(name, wordphrase, inputted_string);
}

void choice_1_next(char* name){
    printf("If you would like, please enter a word or phrase you would like to track: ");
    char* inputted_string;
    scanf("%s", &inputted_string);
    choice_1_next_next(name, inputted_string);
}


void choice_1_start(){
    printf("Please enter the name of a twitch channel whose chat you would like to track: \n");
    char* inputted_string;
    scanf("%s", &inputted_string);
    choice_1_next(inputted_string);
    return;
}

void choice_2(){
    printf("Welcome to Twitch Chat Reading.\n");
    printf("Through this program, you will first input the name of the Twitch streamer whose chat you would like to track. Then you will be prompted to input a specific word you would like to track.\n");
    printf("If you choose to track a specific word, then only messages that contain that word will be tracked.\n");
    printf("After you are prompted to pick a word, you will be prompted to pick a username. If you input a username, then all of the messages from the inputted user will be tracked.\n\n\n");
    return;
}

void main_program(){
    printf("Welcome to Twitch Chat Reading:\n");
    printf("Please enter the number that correlates with the option you want. :)\n\n");
    printf("1. Begin the program\n");
    printf("2. Read the instructions for the program.\n");
    printf("3. Exit the program.\n");
    int userchoice;
    scanf("%d", &userchoice);

    printf("\n\n\n\n");

    if(userchoice == 1){
        choice_1_start();
        main_program();
        return;
    }

    else if(userchoice == 2){
        choice_2();
        main_program();
        return;
    }

    else if(userchoice == 3){
        printf("Thanks for using the program. Goodbye! :)\n");
        return;
    }

    else{
        printf("Invalid input, try again\n");
        main_program();
        return;
    }
}

int main(){
    main_program();
    return 0;
}