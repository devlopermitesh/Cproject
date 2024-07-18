#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void operationList();
float calculator(int A, int B, char operation);

int main() {
    int A, B;
    float result;
    char reskip;
    int contin = 1;
    char operation;
    char input;

    printf("\n \t Welcome to smart calculator\n");
    printf("I can perform (+, -, *, /, ^, and many more operations. For details, press 'd'\n");
    printf("Else press any key to continue\n");
    scanf(" %c", &input);
    input = tolower(input);

    if (input == 'd') {
        operationList();
    }

    while (contin) {
        printf("Enter First operand (A): ");
        scanf("%i", &A);
        printf("Enter Second operand (B): ");
        scanf("%i", &B);
        printf("Enter the operation you want to perform: ");
        scanf(" %c", &operation);

        result = calculator(A, B, operation);
        printf("Result is: %.2f\n", result);
        printf("If you want to skip, press 'X'. Press any other key to continue: ");
        scanf(" %c", &reskip);
        reskip = toupper(reskip);
        if (reskip == 'X') {
            contin = 0;
        }
    }

    return 0;
}

void operationList() {
    printf("Enter operands followed by the operator for calculation\n");
    printf("+, for addition\n");
    printf("-, for subtraction\n");
    printf("*, for multiplication\n");
    printf("/, for division\n");
    printf("m, for modulus\n");
    printf("^, for exponentiation\n");
    printf("S, for square root calculation\n");
    printf("A, for area of a shape (triangle, square, rectangle, circle, cylinder)\n");
}

float calculator(int A, int B, char operation) {
    operation = tolower(operation);
    switch (operation) {
        case '+':
            return A + B;
        case '-':
            return A - B;
        case '*':
            return A * B;
        case '/':
            if (B != 0) {
                return (float) A / B;
            } else {
                printf("Error: Division by zero.\n");
                return 0.0;
            }
        case 'm':
            return A % B;
        case '^':
            return pow(A, B);
        case 's':
            return sqrt(A);
        case 'a': {
            char shape[30];
            printf("Which area do you want to find? (triangle, square, rectangle, circle, cylinder)\n");
            scanf("%s", shape);
            if (strcmp(shape, "triangle") == 0) {
                printf("Enter base of the triangle: ");
                scanf("%i", &A);
                printf("Enter height of the triangle: ");
                scanf("%i", &B);
                return 0.5 * A * B;
            } else if (strcmp(shape, "square") == 0) {
                printf("Enter side length of the square: ");
                scanf("%i", &A);
                return A * A;
            } else if (strcmp(shape, "rectangle") == 0) {
                printf("Enter length of the rectangle: ");
                scanf("%i", &A);
                printf("Enter width of the rectangle: ");
                scanf("%i", &B);
                return A * B;
            } else if (strcmp(shape, "circle") == 0) {
                printf("Enter radius of the circle: ");
                scanf("%i", &A);
                return (3.14) * A * A;
            } else if (strcmp(shape, "cylinder") == 0) {
                printf("Enter radius of the cylinder: ");
                scanf("%i", &A);
                printf("Enter height of the cylinder: ");
                scanf("%i", &B);
                return 2 * (3.14) * A * (A + B);
            } else {
                printf("Invalid shape.\n");
                return 0.0;
            }
        }
        default:
            printf("Invalid operation.\n");
            return 0.0;
    }
}
