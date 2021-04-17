#include <stdio.h>
#include <math.h>

int main(void)
{
    int pass[6];
    int i = 146810;
    int mod=6;
    int counter = 0;
    int inspector = 0;

    for(;i<612564;i++)
    {   
        for(int j=0;mod>1;mod--,j++)
        {

            pass[j] = ( (i%(int)pow(10,mod) - i%(int) pow(10,(mod-1)) )/(int) pow(10,mod-1) );

        }
        pass[5] = (int) (i%(int) pow(10,1));
        mod =6;

        for(int j=0;j<5;j++)
        {

            if(pass[j] == pass[j+1])
            {
                inspector++;
            }

        }

        if (inspector == 0)
        {
            continue;
        }

        else
        {
            inspector =0;
            for(int j=0;j<5;j++)
            {
                if(pass[j]<=pass[j+1])
                {
                    inspector++;
                }
            }
            if (inspector == 5)
            {
                printf("%d \n",i);
                counter++;
            }
            inspector =0;
        }
        


    }
    printf("**%d** \n",counter);

}
