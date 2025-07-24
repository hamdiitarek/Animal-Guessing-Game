#ifndef Play_game_h
#define Play_game_h
#include "Learn new information.h"

void play_game(node_t *current_node) {
    char answer[10];
    
    // If this is a leaf node (animal guess)
    if (current_node->yes == NULL && current_node->no == NULL) {
        printf("Is it a %s? (yes/no): ", current_node->question);
        scanf("%s", answer);
        
        if (strcmp(answer, "yes") == 0 || strcmp(answer, "Yes") == 0) {
            printf("Great! I guessed your animal!\n");
        } else {
            printf("I couldn't guess your animal.\n");
            learn_new_information(current_node);
        }
        return;
    }
    
    // Ask the question
    printf("%s (yes/no): ", current_node->question);
    scanf("%s", answer);

    if (strcmp(answer, "yes") == 0 || strcmp(answer, "Yes") == 0) {
        if (current_node->yes != NULL) {
            play_game(current_node->yes);
        } else {
            printf("Is it a %s? (yes/no): ", current_node->yes_answer);
            scanf("%s", answer);
            if (strcmp(answer, "yes") == 0 || strcmp(answer, "Yes") == 0) {
                printf("Great! I guessed your animal!\n");
            } else {
                printf("I couldn't guess your animal.\n");
                learn_new_information(current_node);
            }
        }
    } else if (strcmp(answer, "no") == 0 || strcmp(answer, "No") == 0) {
        if (current_node->no != NULL) {
            play_game(current_node->no);
        } else {
            printf("Is it a %s? (yes/no): ", current_node->no_answer);
            scanf("%s", answer);
            if (strcmp(answer, "yes") == 0 || strcmp(answer, "Yes") == 0) {
                printf("Great! I guessed your animal!\n");
            } else {
                printf("I couldn't guess your animal.\n");
                learn_new_information(current_node);
            }
        }
    } else {
        printf("Please answer with 'yes' or 'no'.\n");
        play_game(current_node); // Ask the same question again
    }
}

#endif /* Play_game_h */
