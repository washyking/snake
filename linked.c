#include "linked.h"
#include <stdio.h>
#include <stdlib.h>



void printList(struct node* head, int width) {
    struct node* current = head;

    // Print the top border
    printf("+");
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("+\n");

    // Print each row of the grid
    while (current != NULL) {
        if (current->data == '|') {
            printf("|");
        } else {
            printf("%c", current->data);
        }

        current = current->next;

        if (current == NULL || current->data == '|') {
            printf("|\n");
        }
    }

    // Print the bottom border
    printf("+");
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("+\n");
}

struct snakesegment {
    int x;
    int y;
    
    struct snakesegment* next;
};

struct snake
{
    struct snakesegment* head;
    int length;
    char direction;
};



// void randomizePlayerPosition(int minX, int minY, int num1, int num2, int* x_pos, int* y_pos) {
//     *x_pos = minX + rand() % (num1 - minX);
//     *y_pos = minY + rand() % (num2 - minY);
// }

// void randomFoodPosition(int minX, int minY, int num1, int num2, struct node *head, int* x_food, int* y_food) {
//     *x_food = 1 + rand() % (num1 - minX);
//     *y_food = 1 + rand() % (num2 - minY);

//     // Traverse the linked list to find the node at the food position
//     struct node* current = head;
//     for (int i = 0; i < *y_food; i++) {
//         if (current == NULL) {
//             printf("Error: Grid dimensions exceeded\n");
//             return;
//         }
//         current = current->next;
//     }
//     for (int i = 0; i < *x_food; i++) {
//         if (current == NULL) {
//             printf("Error: Grid dimensions exceeded\n");
//             return;
//         }
//         current = current->next;
//     }

//     // Set the data of the node at the food position to represent the food
//     if (current != NULL) {
//         current->data = 'X';
//     } else {
//         printf("Error: Grid dimensions exceeded\n");
//     }
// }





void anotherLinkedListFunction() {

}



