#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"

int main()
{
    int i;
    int type;
    User * usr;
    gotoxy(25,10);
    textcolor(YELLOW);
    printf("WELCOME TO CAR RENTAL SYSTEM");
    gotoxy(20,13);
    textcolor(LIGHTGREEN);
    printf("*RENT A CAR AND GO WHEREVER YOU NEED*");
    getch();
    textcolor(YELLOW);
    addAdmin();
    while(1)
    {
        clrscr();
        textcolor(LIGHTRED);
        gotoxy(32,2);
        printf("CAR RENTAL SYSTEM");
        gotoxy(1,8);
        textcolor(YELLOW);
        for(i=0;i<80;i++)
        {
            printf("*");
        }
        gotoxy(1,18);
        for(i=0;i<80;i++)
        {
            printf("*");
        }

        gotoxy(32,10);
        textcolor(YELLOW);
        printf("1. Admin");
        gotoxy(32,12);
        printf("2. Employee");
        gotoxy(32,14);
        printf("3. Quit");
        gotoxy(32,16);
        textcolor(WHITE);
        printf("Select your role:");
        do
        {
            scanf("%d",&type);
            if(type==1)
            {
                //code for admin login
                usr=getInput();
                if(usr==NULL)
                    break;
                else
                {
                    //call for checkUserExist();
                }
            }
            else if(type==2)
            {
                //code for employee login
            }
            else if(type==3)
            {
                clrscr();
                textcolor(GREEN);
                gotoxy(30,12);
                printf("Thank you for using the app");
                getch();
                exit(0);
            }
            else
            {
                textcolor(RED);
                gotoxy(30,20);
                printf("Invalid Choice");
                getch();
                gotoxy(30,20);
                printf("\t\t\t\t");
                gotoxy(49,16);
                printf("\t\t\t\t");
                textcolor(WHITE);
                gotoxy(49,16);
            }

        }while(1);
        getch();
    }


    return 0;
}

