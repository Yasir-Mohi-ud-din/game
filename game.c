#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

// intial coordinates of B and score "s" =0
int x=15,y=8,s=1;

char move ='x';
// x1 ans y1 are the co-ordinates of of X
void draw(int x1[24],int y1[24])
{ system("cls");
printf("              **************** Bird Game created by Yasir Mohi ud din ***************\n");
// two for loops to make box of size 16X30 for the game
    for(int i=0;i<=16;i++)
    {
        for(int j=0;j<=30;j++)
        {
               int xp =0;
// loop to check coincidence of X and B => game over
         for (int xl=xp  ;xl<24; )
{   if(i==y1[xl]&&j==x1[xl]&& (x1[xl]==x&&y1[xl]==y))
    { printf("OUT");
    xp++;
    j+=3;
    break;

    }


     else
    if(i==y1[xl]&&j==x1[xl])
    { printf("X");
    xp++;
    j++;
    break;

    }
   xl++;
}
// To print borders
            if(i==0||i==16||j==0||j==30)
                printf("#");
             else   if(i==1&&(j<15||j>17))
                printf("#");
                   else   if(i==15&&(j>17))
                printf("#");


                     else
                        // B moving out of box => Game over
                        if(i==y && j==x &&(i==15||i==1) )
                       { printf("OUT");
                           j+=2;
                       }
                      else
                        // x and y are coordiantes of B 
                        if(i==y&&j==x)
                        printf("B");

                       else
                        // to print score inside box of game
                        if(i==15&&j<10){
                        printf("Score : %d ",s);
                        // to make space for no. of digits for printing score inside box
                        if(s<10)
                        j+=9;
                        else if(s<100)
                        j+=10;
                     else    if(s<1000)
                        j+=11;
                      else   if(s<10000)
                        j+=12;

                        else   if(s<100000)
                        j+=13;

                        else   if(s<1000000)
                        j+=14;
                        else
                        j+=15;

                        }

                       else
                        printf(" ");




        }
        printf("\n");
    }
//sleeping time  : sleeping time will decrease on progressing => b will move faster on progressing
   if(s<10)
        usleep(1000000/3);
  else 
    if(s<100)
    usleep(1000000/6);
    else
        if(s<200)
    usleep(1000000/8);
     else
        if(s<400)
    usleep(100000);
     else
        if(s<800)
    usleep(100000/5);
     else
           if(s<2000)
    usleep(10000);
      else
           if(s<5000)
    usleep(10000);
     else
        usleep(10000/6);
    
   /** Trying to replace above if else statements for usleep()
      int slp = 2*1000000/s;
    usleep(slp);
    **/
}
 void logic(int x1[24],int y1[24])
 { // for each itteration score (s) will increase by 1 .
    s+=1;
 for(int i=0;i<24;i++)
 { // to move each X towards LHS
     x1[i]--;
     
 }
     for(int i=0;i<24;i++)
     {
          if(x1[i]==0    )
x1[i]=29;
     }

      if(kbhit())
    move = getch();


     switch (move)
     {
     case '5':
     // to move B up by hitting 5
        y--;
        move='x';
        break;
        case 'p':
        move = getch();
        break;
     default:
     // By default B will move downwards
        y++;
     }
 }

//main function
int main(){
    system("cls ");
  int y1[ ]={2,13,7,6,9,12,6,13,8,4,5,13,3,14,8,7,11,13,15,2,1,6,2,9},x1[ ]={27,24,38,50,53,47,61,67,69,71,73,75,77,78,89 ,98,100,102,105,107,105,129,132,140};
    printf("\nprogrammer : Yasir Mohi ud din\n\nInstructions for the game :-\n1 : PRESS 5 TO MOVE BIRD UP \n2 : TRY TO KEEP BIRD AWAY FROM X \n3 : GAME WILL BE OVER IF B COINCIDES WITH X OR B MOVES OUT OT BOX \n4 : PRESS P TO PAUSE\n ");
  printf("\n\nPRESS ANY KEY TO START\n");
   getch();
   while(1) {

    draw(x1,y1);

for(int i=0;i<24;i++)
{  // game will be over if B coincides with X
   if((x1[i]==x&&y1[i]==y) )
   
{printf("\n         Game Over \nYour total score is %d   ",s );
getch( );
return 0;
}
}
// game will be over if B moves out of box from upper side (y==1) or lower side (y=15)
    if(y==15||y==1)
    {
      
        printf("\n         Game Over \nYour total score is %d   ",s );
getch( );
return 0;
    }


    logic(x1,y1 );

}

}
