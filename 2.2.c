#include <stdio.h>
#include <stdlib.h>

int main()

{
int a;
int b;
int Array_Sayac = 0;
int Anlik_Sayac = 0;
int onemsiz = 0;

    
       FILE *kaynak = fopen("p2.txt","r+");

    while(!feof(kaynak))
    {
        fscanf(kaynak,"%d,",&onemsiz);
        Array_Sayac++;
    }
    rewind(kaynak);
            int SayiH[Array_Sayac];
            int AsılDize[Array_Sayac];
            while(!feof(kaynak))
                {
                    //fscanf(kaynak,"%d,",&SayiH[Anlik_Sayac]);
                    fscanf(kaynak,"%d,",&AsılDize[Anlik_Sayac]);
                    Anlik_Sayac++;
                }
for (int x = 0;x < Array_Sayac;x++)
    {
        SayiH[x] = AsılDize[x];
    }

    for (a=1;a<99;a++)
    {
        for (int x = 0;x < Array_Sayac;x++)
            {
                SayiH[x] = AsılDize[x];
            }
        for (b=1;b<99;b++)
        {
            //printf ("a=%d b=%d\n",a,b);
            SayiH[1]= a;
            SayiH[2] = b;

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
                if (SayiH[0] == 19690720)
                {
                   printf("Başardı %d %d\n",SayiH[1],SayiH[2]);
                   //printf("%d\n",SayiH[0]);

                }
                
                for (int x = 0;x < Array_Sayac;x++)
                {
                SayiH[x] = AsılDize[x];
                }
                
        }
    }



    return 0;
}