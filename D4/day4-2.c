#include <stdio.h>
#include <math.h>

int main(void)
{
    int pass[6];
    int counter = 0;
    int inspector = 0;
    int mod =6;

    for(int i=146810;i<612564;i++)//aralıkları giriniz
    {

        inspector =0;
        for(int j=0;mod>1;mod--,j++)
        {
            pass[j] = ( (i%(int)pow(10,mod) - i%(int) pow(10,(mod-1)) )/(int) pow(10,mod-1) );
        }
        pass[5] = (int) (i%(int) pow(10,1));
        mod = 6;
        for(int j=0;j<5;j++)
            {
                if(pass[j]<=pass[j+1])
                {
                    inspector++;
                }
            }
        if (inspector != 5) continue;

        inspector =0;
        int parser[6] = {0,0,0,0,0,0};
        for(int j=0;j<6;j++)
        {

            for(int k = 0;k<6;k++)
            {
                if(pass[j] == pass[k])
                {
                    parser[j]++;
                }
            }

        }

        for(int j=0;j<6;j++)
        {
            if (parser[j] == 2)
            {
                counter++;
                break;
            }

        }

    }
    printf("%d",counter);

}
