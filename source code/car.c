#include <stdio.h>
#include <string.h>
#include "conio2.h"
#include "car.h"

void addAdmin()
{
    FILE *fp=fopen("admin.bin","rb");
    if(fp==NULL)
    {
        fp=fopen("admin.bin","wb");
        User u[2]={{"admin","test","ravi"},{"super","demo","anil"}};
        fwrite(u,sizeof(u),1,fp);

    }
    fclose(fp);
}

User* getInput()
{
    int i;
    clrscr();
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<=80;i++)
        printf("%c",247);

    gotoxy(32,5);
    printf("* LOGIN PANEL *");

    gotoxy(1,7);
    textcolor(LIGHTCYAN);
    for(i=1;i<=80;i++)
        printf("%c",247);

    gotoxy(1,15);
    for(i=1;i<=80;i++)
      printf("%c",247);

    gotoxy(60,8);
    textcolor(WHITE);
    printf("Press 0 to exit");
    textcolor(LIGHTCYAN);
    gotoxy(25,10);
    printf("Enter Userid:");
    textcolor(WHITE);
    static User u;
    fflush(stdin);
    fgets(u.userid,20,stdin);
    char *pos;
    pos=strchr(u.userid,'\n');
    if(pos!=NULL)
    {
        *pos='\0';
    }
    if(strcmp(u.userid,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(30,17);
        printf("Login Cancelled");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    textcolor(LIGHTCYAN);
    gotoxy(25,11);
    printf("Enter Password:");
    fflush(stdin);
    i=0;
    textcolor(WHITE);
    for(;;)
    {
        u.pwd[i]=getch();
        if(u.pwd[i]==13)
        {
            break;
        }
        printf("*");
        if(u.pwd[i]==8)
        {
            printf("\b\b  \b\b");
            i=i-2;
        }
        i++;
    }
    u.pwd[i]='\0';
    if(strcmp(u.pwd,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(30,17);
        printf("Login Cancelled");
        getch();
        textcolor(YELLOW);
        return NULL;
    }

    getch();



}

