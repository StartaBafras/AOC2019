#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE*dosya_1;
    dosya_1=fopen("birinci.txt","r");

    FILE*dosya_2;
    dosya_2=fopen("ikinci.txt","r");

  FILE*dosya_3;
    dosya_3=fopen("ucuncu.txt","w+");

  FILE*dosya_4;
    dosya_4=fopen("dorduncu.txt","w+");

   char karakter_1[301];
   int sayi_1[301];

   char karakter_2[301];
   int sayi_2[301];

    int i=0,j=0,c=0,v=0;
    int x=0,y=0,x2=0,y2=0;
    int k=0;


      while(!feof(dosya_1))
       {

        karakter_1[i]=fgetc(dosya_1);
        fscanf(dosya_1,"%d,",&sayi_1[i]);


       if(karakter_1[i]=='R')
        {
            for(k=0;k<sayi_1[i];k++)
            {
            x=x+1;
            fprintf(dosya_3,"%d,%d\n",x,y);
            }
        }

        else if(karakter_1[i]=='L')
        {
            for(k=0;k<sayi_1[i];k++)
            {

            x=x-1;
            fprintf(dosya_3,"%d,%d\n",x,y);
            }

        }


        else if(karakter_1[i]=='U')
        {
            for(k=0;k<sayi_1[i];k++)
            {
             y=y+1;
             fprintf(dosya_3,"%d,%d\n",x,y);
            }
        }

        else if(karakter_1[i]=='D')
        {
            for(k=0;k<sayi_1[i];k++)
            {

             y=y-1;
             fprintf(dosya_3,"%d,%d\n",x,y);
            }
        }


    i++;
    }




        while(!feof(dosya_2))
        {
        karakter_2[j]=fgetc(dosya_2);
        fscanf(dosya_2,"%d,",&sayi_2[j]);


        if(karakter_2[j]=='R')
        {
            for(k=0;k<sayi_2[j];k++)
            {
            x2=x2+1;
            fprintf(dosya_4,"%d,%d\n",x2,y2);
            }
        }

         else if(karakter_2[j]=='L')
        {
           for(k=0;k<sayi_2[j];k++)
            {

            x2=x2-1;
            fprintf(dosya_4,"%d,%d\n",x2,y2);
            }
        }

        else if(karakter_2[j]=='U')
        {
            for(k=0;k<sayi_2[j];k++)
            {
            y2=y2+1;
            fprintf(dosya_4,"%d,%d\n",x2,y2);
            }
        }

         else if(karakter_2[j]=='D')
        {
            for(k=0;k<sayi_2[j];k++)
            {
            y2=y2-1;
            fprintf(dosya_4,"%d,%d\n",x2,y2);
            }
        }


        j++;
        }

    fclose(dosya_1);
    fclose(dosya_2);
    fclose(dosya_3);
    fclose(dosya_4);

return 0;
}
