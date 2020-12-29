#include <stdio.h>
#include <stdlib.h>
#include "deney.h"

int main(void)
{   
    FILE *fileA = fopen("p3Aa.txt","r");//0. satır silinmeli
    FILE *fileB = fopen("p3Ba.txt","r");
    int xa,ya;
    int xb,yb;
    while (!feof(fileA))
    {
        fscanf(fileA,"%d %d",&xa,&ya);
        //printf("%d %d",xa,ya);

        while (!feof(fileB))
        {
            fscanf(fileB,"%d %d",&xb,&yb);

            if(xa == xb && ya == yb )
            {
                printf("%d %d uzaklık %d \n",xa,ya,xa+ya); //mutlak değer almalı
            }
        }
        rewind(fileB);
        
    }
    
}