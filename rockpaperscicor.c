//rock paper scicroing game
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int game(char user,char computer);
int main(){
    //create variable for use and computer
    char computer,user;
    int result;
    //a tempary varible for specify condtion
char temp;
bool restart=false;
//for get the random number
int n;
do
{
    

srand(time(NULL));

n=rand()%100;

//we generate a random number
//if number <33 then computer=s
//else if n>33 and n<66 computer =p
//else n=computere is z

if(n<33){
    computer='r';

}

else if(n>33 && n<66){
    computer='p';
}
else{
    computer='s';
}

//ask user for input
printf("\n\t\t\t welcome to rockpaperscicor game");
printf("\n\t\t press \"s\" for stone and \"r\" for rock and \"p\" for paper\n");
scanf(" %c",&user);
//for declraing result
result=game(user,computer);
//if result is 0 computer win
//if result is 1 user win
//else -1 in tie
if(result==0){
    printf("\n\n\t\t\t Computer won\n");

}
else if(result==1){
    printf("\n\n\t\t\t You won\n");

}
else{
    printf("\n\n\t\t\t Tie\n");
 //restart   case
 
}

printf("do you want to play agin?? press \"y\"  for play again!\n");
 scanf(" %c",&temp);
 printf("%c",temp);
restart=(temp=='y')?true:false;
    
} while (restart);


return 0;
}
int game(char user,char computer){
//paper and rock->paper win
//rock and scicor->rock win
//scicor and paper ->scicor win
if(user=='p' && computer=='r')return 1;
else if(user=='r' && computer=='p')return 0;

if(user=='r' && computer=='s')return 1;
else if(user=='s' && computer=='r')return 0;

if(user=='s' && computer=='p')return 1;
else if(user=='p' && computer=='s')return 0;
if(user==computer)return -1;
// in default case for registing to crash
}