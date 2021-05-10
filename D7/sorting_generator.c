#include <stdio.h>
#include <time.h>

int main(void)
{   
    srand(time(NULL));
    int dizi[5] = {5,6,7,8,9};
    int dizi2[5] = {0};
    int counter = 1;
    int counter2 = 0;
    FILE *dosya = fopen("p7-3.txt","r+");

    
    for(int p=0;p<1250;p++)
    {    
        
        int i = rand()%5;
        int j = rand()%5;
        if(i != j)
        {
            int tmp;

            tmp = dizi[i];
            dizi[i] = dizi[j];
            dizi[j] = tmp;
            counter = 0;
            
            while (!feof(dosya))
            {
                fscanf(dosya,"%d,%d,%d,%d,%d",&dizi2[0],&dizi2[1],&dizi2[2],&dizi2[3],&dizi2[4]);
                if(dizi[0] == dizi2[0] && dizi[1] == dizi2[1] && dizi[2] == dizi2[2] && dizi[3] == dizi2[3] && dizi[4] == dizi2[4])
                {
                    counter = 0;
                    printf("\nAynı");
                    break;
                }
                else
                {
                    counter = 1;
                }
                
                
            }
            
            if(counter != 0)
            { 
                fprintf(dosya,"%d,%d,%d,%d,%d\n",dizi[0],dizi[1],dizi[2],dizi[3],dizi[4]);
                for(int k=0;k<5;k++)
                {
                    printf("%d,",dizi[k]);
                }
                printf("\n");
            }
            rewind(dosya);
            
        }

    }

}