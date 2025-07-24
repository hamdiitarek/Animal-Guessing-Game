#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structs.h"
#include "Update animals and questions.h"
#include "Play game.h"
#include "Load animals and questions.h"
#include "Learn new information.h"
#include "Start Game.h"

void play_game(node_t *current_node);
void learn_new_information(node_t *current_node);
void load_animals_and_questions(node_t **root_node);
void update_animals_and_questions(node_t *current_node);

int main(int argc, char **argv)
{
    char play_again[10];
    
    do {
        // Initialize the root node with the initial question and answers
        node_t *root_node = malloc(sizeof(node_t));
        root_node->yes = NULL;
        root_node->no = NULL;

        // Load the animals and questions from the file into the linked list
        load_animals_and_questions(&root_node);
        
        printf("\nWelcome to the Animal Guessing Game!\n");
        printf("Think of an animal and press Enter to continue...\n");
        getchar(); // Wait for user to press Enter
        
        play_game(root_node);
        
        printf("\nWould you like to play again? (yes/no): ");
        scanf("%s", play_again);
        
        // Clear input buffer
        while (getchar() != '\n');
        
    } while (strcmp(play_again, "yes") == 0 || strcmp(play_again, "Yes") == 0);
    
    printf("Thanks for playing!\n");
    return 0;
}
