#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sayi1=0;
    int toplam=0,a;
    FILE *dosya ;
    dosya= fopen("C:\\Users\\Yonis\\Desktop\\dosya.txt","r+");



  while(!feof(dosya)){
    fscanf(dosya,"%d",&sayi1);
    //printf("%d\n",sayi1);
    while((sayi1/3)-2>0){
        toplam += (sayi1/3)-2;
        sayi1=(sayi1/3)-2;
    }

   /* a=floor(sayi1/3)-2;
   toplam+=a;*/


    }
    printf("toplam %d",toplam);
    fclose(dosya);
    return 0;
}
