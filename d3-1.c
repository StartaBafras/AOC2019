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
    int k=0,l=0,u=0,m=0;//birinci dongu elemanlarý
    int q=0,w=0,e=0,r=0;//ikinci gongu elemanlarý

       while(!feof(dosya_1))
       {

        karakter_1[i]=fgetc(dosya_1);
        fscanf(dosya_1,"%d,",&sayi_1[i]);


       if(karakter_1[i]=='R')
        {
            for(l=0;l<sayi_1[i];l++)
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
            for(u;u<sayi_1[i];u++)
            {
             y=y+1;
             fprintf(dosya_3,"%d,%d\n",x,y);
            }
        }

        else if(karakter_1[i]=='D')
        {
            for(m=0;m<sayi_1[i];m++)
            {

             y=y-1;
             fprintf(dosya_3,"%d,%d\n",x,y);
            }
        }









        karakter_2[j]=fgetc(dosya_2);
        fscanf(dosya_2,"%d,",&sayi_2[j]);


        if(karakter_2[j]=='R')
        {
            for(q=0;q<sayi_2[j];q++)
            {
            x2=x2+1;
            fprintf(dosya_4,"%d,%d\n",x2,y2);
            }
        }

         else if(karakter_2[j]=='L')
        {
           for(w=0;w<sayi_2[j];w++)
            {

            x2=x2-1;
            fprintf(dosya_4,"%d,%d\n",x2,y2);
            }
        }

        else if(karakter_2[j]=='U')
        {
            for(e=0;e<sayi_2[j];e++)
            {
            y2=y2+1;
            fprintf(dosya_4,"%d,%d\n",x2,y2);
            }
        }

         else if(karakter_2[j]=='D')
        {
            for(r;r<sayi_2[j];r++)
            {

            y2=y2-1;
            fprintf(dosya_4,"%d,%d\n",x2,y2);
            }
        }

        i++;
        j++;

    }




int kontrol_1[5814];
int kontrol_2[5814];
int kontrol_3[5944];
int kontrol_4[5944];


while(!feof(dosya_3))
{
fscanf(dosya_3,"%d,%d",&kontrol_1[c],&kontrol_2[c]);

  //printf("%d,%d\n",kontrol_1[c],kontrol_2[c]);
  c++;
}


while(!feof(dosya_4))
{
fscanf(dosya_4,"%d,%d",&kontrol_3[v],&kontrol_4[v]);

 // printf("%d,%d\n",kontrol_3[v],kontrol_4[v]);
  v++;
}

    for(c=0;c<5814;c++)
    {
        for(v=0;v<5944;v++)
        {
            if(kontrol_1[c]==kontrol_3[v] &&kontrol_2[c]==kontrol_4[v])
            {
                printf("%d,%d",kontrol_1[c],kontrol_2[v]);
            }
        }

    }





    fclose(dosya_1);
    fclose(dosya_2);
    fclose(dosya_3);
    fclose(dosya_4);
    return 0;
}
