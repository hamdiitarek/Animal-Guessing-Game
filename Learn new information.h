#ifndef Learn_new_information_h
#define Learn_new_information_h
#include "Update animals and questions.h"

void learn_new_information(node_t *current_node) {
    char animal[50];
    char question[2][200];
    node_t *new_node = malloc(sizeof(node_t));
    new_node->question = malloc(strlen(question[0]) + 1);
    new_node->yes_answer = malloc(strlen(animal) + 1);
    new_node->no_answer = malloc(strlen(current_node->yes_answer) + 1);
    
    printf("What animal were you thinking of?\n");
    scanf("%s", animal);
    printf("What is the question characteristic of this animal that differentiates it from a %s\n", current_node->yes_answer);
    scanf("%s", new_node->question);
    //node_t *new_node = malloc(sizeof(node_t));
    //new_node->question = malloc(strlen(question[0]) + 1);
    //new_node->yes_answer = malloc(strlen(animal) + 1);
    //new_node->no_answer = malloc(strlen(current_node->yes_answer) + 1);
    //strcpy(new_node->question, question[0]);
    strcpy(new_node->yes_answer, animal);
    strcpy(new_node->no_answer, current_node->yes_answer);
    new_node->yes = current_node;
    new_node->no = current_node;
    current_node->yes = new_node;
    current_node->no = new_node;
    current_node = new_node;

    // Update the animals and questions in the file
    update_animals_and_questions(current_node);
}

#endif /* Learn_new_information_h */
