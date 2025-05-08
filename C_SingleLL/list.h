//
// Created by bhattacharya on 4/24/2025.
//

#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int data;
    strruct Node* next;
} Node;

Node* create_node(int data);

void print_list(Node* head);

void free_list(Node* head);
#endif //LIST_H
