#ifndef Load_animals_and_questions_h
#define Load_animals_and_questions_h

void load_animals_and_questions(node_t **root_node) {
    // Open the file in read mode
    FILE *fp = fopen("C:\\Users\\Hamdi\\CLionProjects\\final project\\Animals.txt", "r");
    if (fp == NULL) {
        // The file does not exist, return without doing anything
        return;
    }

    // Read the first line from the file, which is the initial question and answers
    char line[100];
    if (fgets(line, 100, fp) != NULL) {
        // Parse the question, yes answer, and no answer from the line
        char *question = strtok(line, ",");
        char *yes_answer = strtok(NULL, ",");
        char *no_answer = strtok(NULL, ",");
        // Update the root node with the initial question and answers
        (*root_node)->question = malloc(strlen(question) + 1);
        (*root_node)->yes_answer = malloc(strlen(yes_answer) + 1);
        (*root_node)->no_answer = malloc(strlen(no_answer) + 1);
        strcpy((*root_node)->question, question);
        strcpy((*root_node)->yes_answer, yes_answer);
        strcpy((*root_node)->no_answer, no_answer);
    }

    // Read the rest of the lines from the file, which contain the animals and questions
    node_t *current_node = *root_node;
    while (fgets(line, 100, fp) != NULL) {
        // Parse the question, yes answer, and no answer from the line
        char *question = strtok(line, ",");
        char *yes_answer = strtok(NULL, ",");
        char *no_answer = strtok(NULL, ",");
        // Create a new node with the animal and question
        node_t *new_node = malloc(sizeof(node_t));
        new_node->question = malloc(strlen(question) + 1);
        new_node->yes_answer = malloc(strlen(yes_answer) + 1);
        new_node->no_answer = malloc(strlen(no_answer) + 1);
        strcpy(new_node->question, question);
        strcpy(new_node->yes_answer, yes_answer);
        strcpy(new_node->no_answer, no_answer);
        new_node->yes = NULL;
        new_node->no = NULL;
        // Insert the new node into the linked list
        current_node->yes = new_node;
        current_node->no = new_node;
        current_node = new_node;
    }

    // Close the file
    fclose(fp);
}

#endif
