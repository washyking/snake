#include "grid.h"

void createGrid(struct node **head, int num1, int num2, int x_food, int y_food, int x_pos, int y_pos) {
    struct node *current = NULL, *middle = NULL, *end = NULL;

    // Create the head node
    *head = malloc(sizeof(struct node));
    (*head)->data = '|';
    (*head)->next = NULL;
    current = *head; // Pointer to the start of the row

    // Create the grid rows
    for (int i = 1; i < num2; i++) {
        // Create the cells in the row
        for (int j = 0; j < num1; j++) {
            struct node *new_node = malloc(sizeof(struct node)); // Allocate memory for a new cell
            if (i == y_food && j == x_food) {
                new_node->data = 'O'; // Set 'X' for the food position
            } else if (i == y_pos && j == x_pos){
                new_node->data = 'P';
            }else {
                new_node->data = ' '; // Set '-' for regular cells
            }
            new_node->next = NULL; // Set the next pointer of the new cell to NULL
            current->next = new_node; // Link the new cell to the current row
            current = current->next; // Move to the next cell
        }
        if (i < num2 -1) {
            // Create the middle node if it's not the last row
            middle = malloc(sizeof(struct node));
            middle->data = '|';
            middle->next = NULL;
            current->next = middle; // Link the middle node to the current row
            current = middle; // Move to the middle node for the next row
        }
        else if (i == num2 - 1) {
            // Create the end node if it's the last row
            end = malloc(sizeof(struct node));
            end->next = NULL;
            current->next = end; // Link the end node to the last row
            current = end; // Move to the end node
        }
        
    }

}

void randomFoodPosition(int minX, int minY, int num1, int num2, int *x_food, int *y_food) {
    // Implement the random food position logic here
    // Generate random x_food and y_food coordinates within the grid
    *x_food = minX + rand() % (num1 - minX);
    *y_food = minY + rand() % (num2 - minY);
}

void randomizePlayerPosition(int minX, int minY, int num1, int num2, int* x_pos, int* y_pos) {
    *x_pos = minX + rand() % (num1 - minX);
    *y_pos = minY + rand() % (num2 - minY);
}