#include <stdio.h>
#include <stdlib.h>
#include "deney.h"

int main(void)
{   
    //file name must change 2 points
    //Read a file block
    vector file;
    int i=0;
    char tmp[2];
    FILE *dosya = fopen("p3B.txt","r");
    while (!feof(dosya))
    {
        fscanf(dosya,"%*c %d,",&file.value[i]);
        printf("%d\n",file.value[i]);
        i++;
    }

    rewind(dosya);
    i=0;
    while (!feof(dosya))
    {
        fscanf(dosya,"%c %*d,",tmp);
        file.directory[i] = tmp[0];
        printf("%c",file.directory[i]);
        i++;
    }
    fclose(dosya);
    //block finished
    int last_valuex=0;
    int last_valuey=0;
    int j;
    FILE *answerA = fopen("p3Ba.txt","w");
    for(i =0;i<302;i++)//Değişmeli
    {
        if(file.directory[i] == 'L')
        {
            for(j=last_valuex;last_valuex>j-file.value[i];last_valuex-=1)
            {
                fprintf(answerA,"%d %d\n",last_valuex,last_valuey);
            }
        }
        else if(file.directory[i] == 'R')
        {
            for(j=last_valuex;last_valuex<j+file.value[i];last_valuex++)
            {
                fprintf(answerA,"%d %d\n",last_valuex,last_valuey);
            }   
        }
        else if(file.directory[i] == 'U')
        {
            for(j=last_valuey;last_valuey<j+file.value[i];last_valuey++)
            {
                fprintf(answerA,"%d %d\n",last_valuex,last_valuey);
            }
        }

        else if(file.directory[i] == 'D')
        {
            for (j=last_valuey;last_valuey>j-file.value[i];last_valuey--)
            {
                fprintf(answerA,"%d %d\n",last_valuex,last_valuey);
            }
            
        }
        
        
    }


}
