#ifndef Load_animals_and_questions_h
#define Load_animals_and_questions_h

void load_animals_and_questions(node_t **root_node) {
    // Try to open the file in read mode - use relative path
    FILE *fp = fopen("Animals.txt", "r");
    if (fp == NULL) {
        // If file doesn't exist, create a simple initial tree
        (*root_node)->question = malloc(strlen("Is it a mammal?") + 1);
        strcpy((*root_node)->question, "Is it a mammal?");
        
        // Create leaf nodes for initial animals
        node_t *mammal_node = malloc(sizeof(node_t));
        mammal_node->question = malloc(strlen("Dog") + 1);
        strcpy(mammal_node->question, "Dog");
        mammal_node->yes = NULL;
        mammal_node->no = NULL;
        mammal_node->yes_answer = NULL;
        mammal_node->no_answer = NULL;
        
        node_t *non_mammal_node = malloc(sizeof(node_t));
        non_mammal_node->question = malloc(strlen("Fish") + 1);
        strcpy(non_mammal_node->question, "Fish");
        non_mammal_node->yes = NULL;
        non_mammal_node->no = NULL;
        non_mammal_node->yes_answer = NULL;
        non_mammal_node->no_answer = NULL;
        
        (*root_node)->yes = mammal_node;
        (*root_node)->no = non_mammal_node;
        (*root_node)->yes_answer = NULL;
        (*root_node)->no_answer = NULL;
        
        return;
    }

    // Read and parse the file (simplified format for now)
    char line[200];
    if (fgets(line, sizeof(line), fp) != NULL) {
        // Remove newline character
        line[strcspn(line, "\n")] = 0;
        
        // For simplicity, just set the root question
        (*root_node)->question = malloc(strlen(line) + 1);
        strcpy((*root_node)->question, line);
        (*root_node)->yes_answer = NULL;
        (*root_node)->no_answer = NULL;
        
        // Create simple leaf nodes if file has more data
        node_t *yes_node = malloc(sizeof(node_t));
        node_t *no_node = malloc(sizeof(node_t));
        
        if (fgets(line, sizeof(line), fp) != NULL) {
            line[strcspn(line, "\n")] = 0;
            yes_node->question = malloc(strlen(line) + 1);
            strcpy(yes_node->question, line);
        } else {
            yes_node->question = malloc(strlen("Dog") + 1);
            strcpy(yes_node->question, "Dog");
        }
        
        if (fgets(line, sizeof(line), fp) != NULL) {
            line[strcspn(line, "\n")] = 0;
            no_node->question = malloc(strlen(line) + 1);
            strcpy(no_node->question, line);
        } else {
            no_node->question = malloc(strlen("Fish") + 1);
            strcpy(no_node->question, "Fish");
        }
        
        yes_node->yes = NULL;
        yes_node->no = NULL;
        yes_node->yes_answer = NULL;
        yes_node->no_answer = NULL;
        
        no_node->yes = NULL;
        no_node->no = NULL;
        no_node->yes_answer = NULL;
        no_node->no_answer = NULL;
        
        (*root_node)->yes = yes_node;
        (*root_node)->no = no_node;
    }

    fclose(fp);
}

#endif
