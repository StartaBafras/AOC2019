#include <stdio.h>
#include <stdlib.h>


int main(){
    int i = 0, toplam = 0;
    FILE *dosya = fopen("p1.txt", "r");

    
    while(!feof(dosya))
        {
            fscanf(dosya,"%d",&i);
            //printf("%d \n",i);

            toplam += (i/3)-2;

        }
    printf("%d",toplam);


    

  return 0;
}