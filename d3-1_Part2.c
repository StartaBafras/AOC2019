#include <stdio.h>
#include <stdlib.h>

int main()
{
FILE*dosya_3;
dosya_3=fopen("ucuncu.txt","r");

FILE*dosya_4;
dosya_4=fopen("dorduncu.txt","r");


int kontrol_1[154530];
int kontrol_2[154530];
int kontrol_3[157570];
int kontrol_4[157570];

int c=0,v=0;


for(c=0;c<154530;c++)
{
fscanf(dosya_3,"%d,%d",&kontrol_1[c],&kontrol_2[c]);
}

for(v=0;v<157570;v++)
{
fscanf(dosya_4,"%d,%d",&kontrol_3[v],&kontrol_4[v]);
}


    for(c=0;c<154530;c++)
    {
        for(v=0;v<157570;v++)
        {
            if(kontrol_1[c]==kontrol_3[v] &&kontrol_2[c]==kontrol_4[v])
            {
               if(kontrol_1[c]<0 && kontrol_2[c]<0)
                {
                 printf("(%d,%d)=",kontrol_1[c],kontrol_2[c]);
                 printf("%d\n",(-1*kontrol_2[c])+(-1*kontrol_1[c]));
                }
                else if(kontrol_2[c]<0 && kontrol_1[c]>=0)
                {
                 printf("(%d,%d)=",kontrol_1[c],kontrol_2[c]);
                 printf("%d\n",(-1*kontrol_2[c])+kontrol_1[c]);
                }
                else if(kontrol_1[c]<0  && kontrol_2[c]>=0)
                {
                printf("(%d,%d)=",kontrol_1[c],kontrol_2[c]);
                printf("%d\n",(-1*kontrol_1[c])+kontrol_2[c]);

                }
                else
                {
                printf("(%d,%d)=",kontrol_1[c],kontrol_2[c]);
                printf("%d\n",kontrol_1[c]+kontrol_2[c]);
                }
            }
        }

    }



    fclose(dosya_3);
    fclose(dosya_4);
    return 0;
}
