#ifndef Update_animals_and_questions_h
#define Update_animals_and_questions_h

void update_animals_and_questions(node_t *root_node) {
    // Open the file in append mode
    FILE *fp = fopen("C:\\Users\\Hamdi\\CLionProjects\\final project\\Animals.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Traverse through the linked list and write each node to the file
    while (root_node != NULL) {
        fprintf(fp, "%s,%s,%s\n", root_node->question, root_node->yes_answer, root_node->no_answer);
        root_node = root_node->no;
    }

    fclose(fp);
}

#endif
