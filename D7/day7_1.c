#include <stdio.h>
#include <math.h>
#include <stdlib.h>



void extract(int i,int *pass)
{
    for(int j=1,b=4;j<6;j++,b--)
    {
        pass[b] = ( (i%(int)pow(10,j) - i%(int) pow(10,(j-1)) )/(int) pow(10,j-1) );
    }
}


void check(int *m,int *data,int j)
{   
    int k=2;
    for(int i=1; i<3;i++,k--)
    {
        
        if(m[i] == 0 && m[4] != 3 && m[4] != 4 && m[4] != 9) 
        {
            m[i] = data[data[j+k]];
        }

        else if(m[i] == 1 && m[4] != 3 && m[4] != 4 && m[4] != 9)
        {
            m[i] = data[j+k];
        }
    }
}

int Amplifier(int input[],int *answer)
{
    

        FILE *file = fopen("p7.txt","r");
        int box;
        int size = 0;
        //int input = 0;
        //int output = 0;
        int j = 0;


        while (!feof(file))
        {
            fscanf(file,"%d,",&box);
            size++;
        }

        int dataset[size];
        rewind(file);
        box = 0;
        while (!feof(file))
        {
            fscanf(file,"%d,",&dataset[box]);
            box++;

        }

        int m[5] = {0,0,0,0,0};

        for(int i=0;i<size;)
        {
            extract(dataset[i],m);
            check(&m,&dataset,i);

            if(m[4] == 1)
            {
                dataset[dataset[i+3]] = m[1] + m[2];
                i+=4;
            }

            else if(m[4] == 2)
            {
                dataset[dataset[i+3]] = m[1] * m[2];
                i+=4;
            }

            else if(m[4] == 3)
            {
                //printf("İnput: ");
                //scanf("%d",&input);
                dataset[dataset[i+1]] = input[j];
                j++;
                i+=2;
            }

            else if(m[4] == 4)
            {
                if(m[2] == 1)
                {
                    *answer = dataset[i+1];
                    //printf("\n%d",*answer);
                }
                else
                {
                    *answer = dataset[dataset[i+1]];
                    //printf("\n%d",*answer);
                }
                i+=2;
            }

            else if(m[4] == 5)// 5 ve 6 sıkıntılı
            {   

                if(m[2] != 0)
                {
                    i = m[1];
                    continue;
                }
                i+=3;

            }

            else if(m[4] == 6)
            {
                if(m[2] == 0)
                {
                    i = m[1];
                    continue;
                }
                i+=3;
            }

            else if(m[4] == 7)
            {
                if(m[2] < m[1])
                {
                    dataset[dataset[i+3]] = 1;
                }
                else
                {
                    dataset[dataset[i+3]] = 0;
                }
                i+=4;
            }

            else if(m[4] == 8)
            {
                if(m[1] == m[2])
                {
                    dataset[dataset[i+3]] = 1;
                }
                else
                {
                    dataset[dataset[i+3]] = 0;
                }
                i += 4;  
            }

            else if(m[4] == 9)
            {
                //printf("\nHata 99");
                break;
            }
        }
    

}

int main(void)
{
    int *answer = malloc(sizeof(int));
    *answer = 0;

    FILE *file = fopen("p7-2.txt","r");
    int phase[5] = {0};
    int signals[120] = {0};
    int counter = 0;

    while (!feof(file))
    {
        fscanf(file,"%d,%d,%d,%d,%d",&phase[0],&phase[1],&phase[2],&phase[3],&phase[4]);

        for(int i=0;i<5;i++)
        {
            int packet[2] = {phase[i],*answer};
            Amplifier(packet,answer);
        }
        signals[counter] = *answer;
        counter++;
        *answer = 0;
    }

    int temp = 0;

    for (int i=0;i<120;i++) 
    {
        for(int j=0;j<120;j++) 
        {
            if(signals[i]>signals[j])
            {
                temp=signals[i];
                signals[i]=signals[j];
                signals[j]=temp;
            }
        }
    }
    printf("%d",signals[0]);
}


