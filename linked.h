#ifndef LINKED_H
#define LINKED_H

#include <stdio.h>

struct node {
    char data;
    struct node* next;
};


void printList(struct node* head, int width);
//void randomFoodPosition(int minX, int minY, int num1, int num2,struct node* middle, int* x_food, int* y_food);
void randomizePlayerPosition(int minX, int minY, int num1, int num2, int* x_pos, int* y_pos);

#endif
