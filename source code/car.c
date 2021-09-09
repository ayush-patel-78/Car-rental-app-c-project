#include <stdio.h>
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
