#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int x=15,y=8,s=0;

char move ='x';
void draw(int x1[8],int y1[8])
{ system("cls");
printf("              **************** Bird Game created by Yasir Mohi ud din ***************\n");
    for(int i=0;i<=16;i++)
    {
        for(int j=0;j<=30;j++)
        {
               int xp =0;

         for (int xl=xp  ;xl<12; )
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

            if(i==0||i==16||j==0||j==30)
                printf("#");
             else   if(i==1&&(j<15||j>17))
                printf("#");
                   else   if(i==15&&(j>17))
                printf("#");


                     else
                        if(i==y && j==x &&(i==15||i==1) )
                       { printf("OUT");
                           j+=2;
                       }
                      else
                        if(i==y&&j==x)
                        printf("B");

                       else
                        if(i==15&&j<10){
                        printf("Score : %d ",s);
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
//sleeping time
if(s<100)
    usleep(1000000/5);
    else
        if(s<200)
    usleep(1000000/6);
     else
        if(s<400)
    usleep(1000000/7);
     else
        if(s<800)
    usleep(1000000/8);
     else
           if(s<2000)
    usleep(1000000/9);
      else
           if(s<5000)
    usleep(100000);
     else
        usleep(100000/2);
}
 void logic(int x1[8],int y1[8])
 { s+=1;
 for(int i=0;i<12;i++)
 {
     x1[i]--;
 }
     for(int i=0;i<12;i++)
     {
          if(x1[i]==0    )
x1[i]=29;
     }

      if(kbhit())
    move = getch();


     switch (move)
     {
     case '5':
        y--;
        move='x';
        break;
     default:
        y++;
     }
 }

int main()
{  int y1[12]={2,13,7,6,9,12,14,13,8,4,5,13},x1[12]={27,24,38,50,53,47,61,67,69,71,73,75};
    printf("programmer : Yasir Mohi ud din\nInstructions for the game \n1:PRESS 5 TO MOVE BIRD UP \n2: TRY TO KEEP BIRD AWAY FROM X \n3:GAME WILL BE ENDED IF B COINCIDES WITH X OR B MOVES OUT OT BOX \n");
  printf("\n\nPRESS ENTER TO START\n");
   getch();
   while(1) {   draw(x1,y1);

for(int i=0;i<12;i++)
{
   if((x1[i]==x&&y1[i]==y))
    goto out;}
    if(y==15||y==1)
    {
        goto out;
    }


    logic(x1,y1 );

}
out:
    printf("\n         Game Ended \nYour total score is %d   ",s );
getch( );
}
