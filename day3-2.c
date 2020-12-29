#include <stdio.h>
#include <stdlib.h>
#include "deney.h"

int main(void)
{   
    FILE *fileA = fopen("p3Aa.txt","r");
    FILE *fileB = fopen("p3Ba.txt","r");
    int xa,ya;
    int xb,yb;
    int lineA=1,lineB=1;

    while (!feof(fileA))
    {   
        
        fscanf(fileA,"%d %d",&xa,&ya);
        printf("%d %d\n",xa,ya);
        

        while (!feof(fileB))
        {   
            
            fscanf(fileB,"%d %d",&xb,&yb);

            if(xa == xb && ya == yb )
            {
                printf("%d %d uzaklık %d adım sayısı %d (%d,%d)\n",xa,ya,xa+ya,lineB+lineA-2,lineA,lineB); //mutlak değer almalı
            }//ya sıfırlar dosyalardan silinmeli ya da -2 çıkarılmalı
            lineB++;
        }
        rewind(fileB);
        lineB=1;
        lineA++;
    }
    
}