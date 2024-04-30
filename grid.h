#ifndef GRID_H
#define GRID_H

#include <stdlib.h>
#include "linked.h"

void createGrid(struct node **head, int num1, int num2, int x_food, int y_food, int x_pos, int y_pos);
void randomFoodPosition(int minX, int minY, int num1, int num2, int *x_food, int *y_food);
void randomizePlayerPosition(int minX, int minY, int num1, int num2, int* x_pos, int* y_pos);
#endif /* GRID_H */
