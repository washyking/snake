#include "linked.h"
#include "grid.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <ctype.h>
#include "buffer.h"

// Function declarations
int getInput(const char* prompt, int min, int max);

int main() {
    srand(time(NULL));

    int minX = 5, maxX = 25;
    int minY = 5, maxY = 25;

    int num1 = getInput("Enter width X: ", minX, maxX);
    int num2 = getInput("Enter height Y: ", minY, maxY);

    // Initialize player position
    int x_pos, y_pos;
    randomizePlayerPosition(minX, minY, num1, num2, &x_pos, &y_pos);

    printf("Player position:\n");
    printf("x position: %d and y position: %d \n", x_pos, y_pos);

    // Initialize head of the linked list
    struct node *head = malloc(sizeof(struct node));
    
    int x_food, y_food;
    randomFoodPosition(minX + 1, minY + 1, num1, num2, &x_food, &y_food);
    createGrid(&head, num1, num2, x_food, y_food, x_pos, y_pos);
    printList(head, num1);
    printf("Food position:\n");
    printf("x_food position: %d and y_food position: %d \n", x_food, y_food);

    
    disableBuffer();
    int points = 0;
   while (1) {

        
        char key = tolower(getchar());
        //scanf("%c", &key); // Read the user input
        
        if (key == 'd') {
            if(x_food < num1 - 1){
                x_food++;
            }
            else{
                x_food = 0;}
        } else if (key == 'a') {
            if(x_food > 1){
                x_food--;
            }
            else{
                x_food = num1 - 1;}
        } else if (key == 's') {
            if(y_food < num2 - 1){
                y_food++; 
            }
            else{
                y_food = 0;}
        } else if (key == 'w') {
            if(y_food > 1){
                y_food--;
            }
            else{
                y_food = num2 - 1;}
        } else if (key == 'q') {
            break; // Exit the loop if the user inputs 0
        } else {
            printf("Please use WASD or q to quit'.\n");
            continue; // Skip the rest of the loop and ask for input again
        }

        // Update the grid and display the changes
        createGrid(&head, num1, num2, x_food, y_food, x_pos, y_pos);
        system("clear"); // Clear the terminal screen
        printList(head, num1); // Print the updated grid
        printf("Food position:\n");
        printf("x_food position: %d and y_food position: %d \n", x_food, y_food);

        if (x_food == x_pos && y_food == y_pos)
        {
            points++;
            randomizePlayerPosition(minX, minY, num1, num2, &x_pos, &y_pos);
        }
        printf("points: %d \n", points);
        
    }
    
    // Free memory
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

// Function definitions
int getInput(const char* prompt, int min, int max) {
    int num;
    do {
        printf("%s", prompt);
        if (scanf("%d", &num) != 1) {
            printf("Invalid input\n");
            while (getchar() != '\n');
        } else if(num < min || num > max)
        {
            printf("Invalid input out of range\n");
        }
        else {
            break; // Exit the loop if input is valid
        }
    } while (1);
    return num;
}