#ifndef Update_animals_and_questions_h
#define Update_animals_and_questions_h

void save_tree(FILE *fp, node_t *node) {
    if (node == NULL) return;
    
    // Save current node
    fprintf(fp, "%s\n", node->question);
    
    // Recursively save children
    save_tree(fp, node->yes);
    save_tree(fp, node->no);
}

void update_animals_and_questions(node_t *root_node) {
    // Open the file in write mode to overwrite
    FILE *fp = fopen("Animals.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    // Save the entire tree structure
    save_tree(fp, root_node);
    
    fclose(fp);
}

#endif
