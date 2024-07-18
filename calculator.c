//welcome user
//message for show detail
//show detail on d either ask for operand
//take operator
//display resullt
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void operationlist(char input);
float calculator(int A,int B,char operation);
int main(){
int A,B;
float result;
char reskip;
int contin=1;
char operation;
    char input;
printf("\n \t Welcome to smart calculator\n");
printf("i can (+,-,*,/, ^,and many more operation ,for see detail list press d)\nelse press any key to continue\n");
scanf(" %c",&input);
input=tolower(input);
(input=='d')?operationlist(input):"";
while(contin){

printf("Enter First operator(A) :");
scanf("%i",&A);
printf("Enter Second operator(B) :");
scanf("%i",&B);
printf("Enter the operation you want to perform: ");
        char operation;
        scanf(" %c", &operation);

result=calculator(A,B,operation);
printf("result is:%.2f,if you want to skip press X",result);
scanf(" %c",&reskip);
if(reskip=='X'){
contin=0;
}
}

}

void operationlist(char input){
if(input=='d'){
    printf("Enter operator then, operator, for calculation\n");
printf("+, for addition\n");
printf("-, for subtraction\n");
printf("*, for multiplication\n");
printf("/, for division\n");
printf("m, for modules\n");
printf("^, for exponentiation\n");
printf("S, for square root calculation\n");
printf("A, for area of circle ,sqare,cylinder,triangle\n");

}
else{
    printf("something went wrong sorry!!\n");
}
}


float calculator(int A,int B,char operation){
    operation=tolower(operation);
 switch (operation)
 {
 case '+':
    return A+B;
    break;
 case '-':
    return A-B;
    break;
 
 case '*':
    return A*B;
    break;
 case '/':
    return A/B;
    break;
 case 'm':
    return A%B;
    break;
 case '^':
            return pow(A, B);
            break;
        case 's':
            return sqrt(A);
            break;
        case 'a':
        char shape[30];
        printf("which area do you want to find?(trangle,square,rectangle,circle,cyclinder)??\n");
scanf("%s",&shape);
// if(strcmp(shape,"trangle")){
//     printf("enter base of trangle\n");
//     scanf("%i",A);
    
//     printf("enter height of trangle\n");
//     scanf("%i",B);
// return 1/2*(A*B);
// }
    printf("sorry area is not ready\n");
    break;
 default:
  printf("Invalid operation.\n");
  return 0.0;
    break;
 }

}