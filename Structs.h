#ifndef functions_h
#define functions_h

typedef struct node {
    char *question;
    char *yes_answer;
    char *no_answer;
    struct node *yes;
    struct node *no;
} node_t;

#endif
