
#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE*dosya;
   int a=0,toplam=0,b=0;
   dosya=fopen("dd1-2.txt","r+");

   while(!feof(dosya))
    {
    fscanf(dosya,"%d",&a);


while((a/3)-2 >= 0)
      {
    a=(a/3)-2;
    toplam+=a;


      }

    }


    printf("%d",toplam);
    fclose(dosya);

    return 0;
}
