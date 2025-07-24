#ifndef Learn_new_information_h
#define Learn_new_information_h
#include "Update animals and questions.h"

void learn_new_information(node_t *current_node) {
    char animal[100];
    char question[200];
    char old_animal[100];
    
    printf("What animal were you thinking of? ");
    scanf("%s", animal);
    
    // Store the current animal that was guessed incorrectly
    if (current_node->question != NULL) {
        strcpy(old_animal, current_node->question);
    } else if (current_node->yes_answer != NULL) {
        strcpy(old_animal, current_node->yes_answer);
    } else if (current_node->no_answer != NULL) {
        strcpy(old_animal, current_node->no_answer);
    }
    
    printf("What question would distinguish a %s from a %s?\n", animal, old_animal);
    printf("(Please phrase as a yes/no question): ");
    
    // Clear input buffer
    while (getchar() != '\n');
    fgets(question, sizeof(question), stdin);
    
    // Remove newline character
    question[strcspn(question, "\n")] = 0;
    
    printf("What would be the answer for a %s? (yes/no): ", animal);
    char answer_for_new_animal[10];
    scanf("%s", answer_for_new_animal);
    
    // Create new nodes for the binary tree
    node_t *yes_node = malloc(sizeof(node_t));
    node_t *no_node = malloc(sizeof(node_t));
    
    // Initialize the nodes
    yes_node->yes = NULL;
    yes_node->no = NULL;
    no_node->yes = NULL;
    no_node->no = NULL;
    
    if (strcmp(answer_for_new_animal, "yes") == 0 || strcmp(answer_for_new_animal, "Yes") == 0) {
        // New animal gets "yes" answer
        yes_node->question = malloc(strlen(animal) + 1);
        strcpy(yes_node->question, animal);
        yes_node->yes_answer = NULL;
        yes_node->no_answer = NULL;
        
        no_node->question = malloc(strlen(old_animal) + 1);
        strcpy(no_node->question, old_animal);
        no_node->yes_answer = NULL;
        no_node->no_answer = NULL;
    } else {
        // New animal gets "no" answer
        no_node->question = malloc(strlen(animal) + 1);
        strcpy(no_node->question, animal);
        no_node->yes_answer = NULL;
        no_node->no_answer = NULL;
        
        yes_node->question = malloc(strlen(old_animal) + 1);
        strcpy(yes_node->question, old_animal);
        yes_node->yes_answer = NULL;
        yes_node->no_answer = NULL;
    }
    
    // Update current node to be the distinguishing question
    free(current_node->question);
    current_node->question = malloc(strlen(question) + 1);
    strcpy(current_node->question, question);
    
    if (current_node->yes_answer) {
        free(current_node->yes_answer);
        current_node->yes_answer = NULL;
    }
    if (current_node->no_answer) {
        free(current_node->no_answer);
        current_node->no_answer = NULL;
    }
    
    current_node->yes = yes_node;
    current_node->no = no_node;
    
    printf("Thank you! I've learned about the %s.\n", animal);
}

#endif /* Learn_new_information_h */
