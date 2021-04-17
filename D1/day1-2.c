#include <stdio.h>
#include <stdlib.h>


int main(){
    int i = 0, fuel = 0;
    FILE *dosya = fopen("p1.txt", "r");

    
    while(!feof(dosya))
        {   

            fscanf(dosya,"%d",&i);

            while ((i/3)-2>0)
            {
                fuel += (i/3)-2;
                i = (i/3)-2;
            }
            
        }
    printf("%d \n",fuel);



    

  return 0;
}