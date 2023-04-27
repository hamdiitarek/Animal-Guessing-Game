#ifndef Play_game_h
#define Play_game_h
#include "Learn new information.h"

void play_game(node_t *current_node) {
    static int x = 0;
    char answer[5];
    printf("%s (Yes/No)\n", current_node->question);
    scanf("%s", answer);

    if (strcmp(answer, "Yes") == 0) {
        // If the answer is "Yes", traverse down the "Yes" branch of the linked list
        if (strcmp(current_node->yes_answer, "next question") != 0) {
            // If the "Yes" branch is NULL, make a guess
            printf("I think you were thinking of a %s.\n", current_node->yes_answer);
            printf("Was I right? (Yes/No)\n");
            scanf("%s", answer);
            if (strcmp(answer, "No") == 0) {
                learn_new_information(current_node);
            }else{
                exit(0);
            }
        } else {
            // If the "Yes" branch is not NULL, continue the game
                play_game(current_node->yes);
        }
    } else if (strcmp(answer, "No") == 0) {
        // If the answer is "No", traverse down the "No" branch of the linked list
        if (strcmp(current_node->no_answer , "next section") == 10) {
            current_node = current_node->no;
            while(strcmp(current_node->no_answer , "next section") != 10){
                current_node = current_node->no;
                if (strcmp(current_node->no_answer, "end") == 10){
                    break;
                }
            }
            x++;
            play_game(current_node);
        } else {
            x++;
            // If the "No" branch is not NULL, continue the game
            if (x<4) {
                play_game(current_node->no);
            }
            learn_new_information(current_node);
            exit(0);
        }
    } else {
        // If the answer is not "Yes" or "No", print an error message and exit
        printf("Invalid answer.\n");
        exit(1);
    }
}

#endif /* Play_game_h */
