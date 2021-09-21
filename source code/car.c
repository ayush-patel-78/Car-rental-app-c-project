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
        printf("Login cancelled");
        getch();
        textcolor(YELLOW);
        return NULL;
    }

    getch();
    return &u;


}
int checkUserExist(User u,char *usertype)
{
    if(strlen(u.userid)==0|| strlen(u.pwd)==0)
    {
        gotoxy(28,20);
        textcolor(LIGHTRED);
        printf("Both fields are mandatory. Try again");
        getch();
        gotoxy(28,20);
        printf("\t\t\t\t\t\t\t\t\t");
        return 0;
    }
    FILE *fp;
    if(strcmp(usertype,"admin")==0)
    {
       fp=fopen("admin.bin","rb");
    }
    else
    {
        fp=fopen("emp.bin","rb");
    }
    if(fp==NULL)
    {
         gotoxy(28,20);
        textcolor(LIGHTRED);
        printf("Sorry! cannot open the file");
        getch();
        gotoxy(28,20);
        printf("\t\t\t\t\t\t\t\t\t");
        return -1;
    }
    int found=0;
    User user;
    while(fread(&user,sizeof(user),1,fp)==1)
    {
        if(strcmp(u.userid,user.userid)==0&&strcmp(u.pwd,user.pwd)==0)
        {
            found=1;
            break;
        }
    }
    if(found==0)
    {
        gotoxy(28,20);
        textcolor(LIGHTRED);
        printf("invalid userid/password. Try again");
        getch();
        gotoxy(28,20);
        printf("\t\t\t\t\t\t\t\t\t");

    }
    else
    {
        gotoxy(28,20);
        textcolor(LIGHTGREEN);
        printf("LOGIN SUCCESSFULL!");
        getch();
        gotoxy(28,20);
        printf("\t\t\t\t\t\t\t\t\t");

    }
    fclose(fp);
    return found;

}

int adminMenu()
{
    int i,choice;
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
    textcolor(LIGHTGREEN);
    gotoxy(35,6);
    printf("ADMIN MENU\n");
    for(i=1;i<=80;i++)
    {
        printf("*");
    }
    textcolor(YELLOW);
    gotoxy(32,8);
    printf("1. Add Employee");
    gotoxy(32,9);
    printf("2. Add Car Details");
     gotoxy(32,10);
    printf("3. Show Employee");
     gotoxy(32,11);
    printf("4. Show car Details");
     gotoxy(32,12);
    printf("5. Delete Employee");
     gotoxy(32,13);
    printf("6. Delete Car Details");
     gotoxy(32,14);
    printf("7. Exit");
     gotoxy(32,16);
    printf(" Enter Choice:");
    textcolor(WHITE);
    scanf("%d",&choice);
    return choice;


}

void addEmployee()
{
    char empid[10]={"EMP-"};
    char temp[10];
    char choice;
    User u;
    FILE *fp=fopen("emp.bin","ab+");
    fseek(fp,0,SEEK_END);
    long total_rec=ftell(fp)/sizeof(User);
    total_rec++;
    sprintf(temp,"%d",total_rec);
    strcat(empid,temp);
    strcpy(u.userid,empid);
    //above 3 steps can be written in onle line like
    // sprintf(temp,"EMP-%d",total_rec);
    //strcpy(u.userid,temp);
    do
    {

        clrscr();
        gotoxy(32,2);
        textcolor(LIGHTRED);
        printf("CAR RENTAL APP");
        textcolor(LIGHTGREEN);
        int i;
        gotoxy(1,3);
        for(i=0;i<=80;i++)
            printf("~");
        textcolor(WHITE);
        gotoxy(25,5);
        printf("***** Add Employee Details *****");
        gotoxy(1,8);
        textcolor(YELLOW);
        printf("Enter Employee Name:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(u.name,20,stdin);
        char *pos;
        pos=strchr(u.name,'\n');
        if(pos!=NULL)
        {
            *pos='\0';
        }
        textcolor(YELLOW);
        printf("Enter Employee Pwd:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(u.pwd,20,stdin);
        pos=strchr(u.pwd,'\n');
        if(pos!=NULL)
        {
            *pos='\0';
        }
        fwrite(&u,sizeof(u),1,fp);
        gotoxy(30,15);
        textcolor(LIGHTGREEN);
        printf("EMPLOYEE ADDED SUCCESSFULLY!");
        printf("\n EMPLOYEE ID is %s",u.userid);
        getch();

        gotoxy(1,20);
        textcolor(LIGHTRED);
        printf("Do you want to add more employees(Y/N)?");
        textcolor(WHITE);
        fflush(stdin);
        scanf("%c",&choice);
        if(choice=='N')
           break;
        total_rec++;
        sprintf(u.userid,"EMP-%d",total_rec);



    }while(1);
    fclose(fp);
}

void addCarDetails()
{

    char choice;
    Car c;
    FILE *fp=fopen("car.bin","ab+");
    fseek(fp,0,SEEK_END);
    int total_rec=ftell(fp)/sizeof(Car);
    total_rec++;
    c.car_id=total_rec;

    do
    {

        clrscr();
        gotoxy(32,2);
        textcolor(LIGHTRED);
        printf("CAR RENTAL APP");
        textcolor(LIGHTGREEN);
        int i;
        gotoxy(1,3);
        for(i=0;i<=80;i++)
            printf("~");
        textcolor(WHITE);
        gotoxy(25,5);
        printf("***** ADD CAR DETAILS *****");
        gotoxy(1,8);
        textcolor(YELLOW);
        printf("Enter Car Model:");
        fflush(stdin);

        textcolor(WHITE);
        fgets(c.car_name,50,stdin);
        char *pos;
        pos=strchr(c.car_name,'\n');
        if(pos!=NULL)
        {
            *pos='\0';
        }
        textcolor(YELLOW);
        printf("Enter Car Capacity:");
        fflush(stdin);
        textcolor(WHITE);
        scanf("%d",&c.capacity);
        textcolor(YELLOW);
        printf("Enter Car Count:");
        textcolor(WHITE);
        scanf("%d",&c.car_count);
        textcolor(YELLOW);
        printf("Enter Car price for per day:");
        textcolor(WHITE);
        scanf("%d",&c.price);


        fwrite(&c,sizeof(c),1,fp);
        gotoxy(30,15);
        textcolor(LIGHTGREEN);
        printf("CAR ADDED SUCCESSFULLY!");
        printf("\n CAR ID is %d",c.car_id);
        getch();

        gotoxy(1,20);
        textcolor(LIGHTRED);
        printf("Do you want to add more Cars(Y/N)?");
        textcolor(WHITE);
        fflush(stdin);
        scanf("%c",&choice);
        if(choice=='N')
           break;
        total_rec++;
        c.car_id=total_rec;




    }while(1);
    fclose(fp);
}
/*
void viewEmployee()
{
    clrscr();
    User u;
    FILE *fp;
    fp=fopen("emp.bin","rb");
    if(fp==NULL)
    {
        printf("Sorry! Cannot open the file");
        return 1;
    }

        clrscr();
        gotoxy(32,2);
        textcolor(LIGHTRED);
        printf("CAR RENTAL APP");
        textcolor(YELLOW);
        int i;
        gotoxy(1,3);
        for(i=0;i<=80;i++)
            printf("%c",247);
        textcolor(WHITE);
        gotoxy(28,6);
        printf("***** Employee Details *****");
        gotoxy(1,10);
        textcolor(LIGHTGREEN);
         for(i=0;i<=80;i++)
            printf("%c",247);


         gotoxy(2,12);
         printf("\tEMPLOYEE ID\t\t\t");

         printf("NAME\t\t\t");
         printf("PASSWORD");
         gotoxy(1,14);
         for(i=0;i<=80;i++)
            printf("%c",247);
        textcolor(YELLOW);
        while( fread(&u,sizeof(User),1,fp)==1)
        {
            printf("\n");
            printf("\t%s\t\t\t\t",u.userid);
            printf("%s\t\t\t",u.name);
            printf("%s\n",u.pwd);
        }
        getch();


}

*/
void viewEmployee()
{
    FILE *fp=fopen("emp.bin","rb");
    User ur;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(int i=1;i<=80;i++)
    {
        printf("%c",247);
    }
    gotoxy(31,5);
    printf("* EMPLOYEE DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(int i=1;i<=80;i++)
        printf("%c",247);
    
    if(fp==NULL)
    {
        gotoxy(31,9);
        textcolor(LIGHTRED);
        printf("Sorry! No Employee added yet!");
        getch();
        return;
    }
    gotoxy(1,8);
    printf("Employee ID\t\t\tName\t\t\tPassword");
    gotoxy(1,9);
    for(int i=1;i<=80;i++)
        printf("%c",247);
    int row=10;
    textcolor(YELLOW);
    while(fread(&ur,sizeof(ur),1,fp)==1)
    {
        gotoxy(2,row);
        printf("%s",ur.userid);
        gotoxy(33,row);
        printf("%s",ur.name);
        gotoxy(57,row);
        printf("%s",ur.pwd);
        row++;
     
    }
    fclose(fp);
    getch();
        
}




