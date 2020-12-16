#include <stdio.h>
#include <stdlib.h>

int main() {
    int Array_Sayac = 0;
    int Anlik_Sayac = 0;    
    int onemsiz = 0;


    FILE *kaynak;
        kaynak = fopen("/home/ubuntu/kaynak.txt","r+");

    while(!feof(kaynak)) 
    {
        fscanf(kaynak,"%d,",&onemsiz);
        Array_Sayac = Array_Sayac + 1;
    }
     rewind(kaynak);
            int SayiH[Array_Sayac];
             while(!feof(kaynak)) {
                 fscanf(kaynak,"%d,",&SayiH[Anlik_Sayac]);
                Anlik_Sayac += 1;
       }
    SayiH[1] = 12;
    SayiH[2] = 2;

    for(int mod = 0; mod < Array_Sayac; mod += 4)
    {
      if (SayiH[mod] == 1)
        {
            SayiH[SayiH[mod+3]] = SayiH[SayiH[mod+1]] + SayiH[SayiH[mod+2]];
        }
        else if (SayiH[mod] == 2)
        {
            SayiH[SayiH[mod+3]] = SayiH[SayiH[mod+1]] * SayiH[SayiH[mod+2]];
        }
        else if (SayiH[mod] == 99)
        {
            break;
        }
    }
 printf("%d",SayiH[0]);
    return 0;
}