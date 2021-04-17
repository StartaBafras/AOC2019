#include <stdio.h>
#include <math.h>



void select(int i,int *pass)
{

    for(int j=1,b=4;j<6;j++,b--)
    {

        pass[b] = ( (i%(int)pow(10,j) - i%(int) pow(10,(j-1)) )/(int) pow(10,j-1) );


    }

}





int main(void)
{

    FILE *file = fopen("p5.txt","r");
    int box;
    int size = 0;

    int input,output;
    input = 5;
    output = 0;

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
        select(dataset[i],m);

        if(m[4] == 1)
        {
            if(m[1] == 0 && m[2] == 0)
            {
                dataset[dataset[i+3]] = dataset[dataset[i+2]] + dataset[dataset[i+1]];
            }

            else if(m[1] == 1 && m[2] == 0)
            {
                dataset[dataset[i+3]] = dataset[i+2] + dataset[dataset[i+1]];
            }

            else if(m[1] == 1 && m[2] == 1)
            {
                dataset[dataset[i+3]] = dataset[i+2] + dataset[i+1];
            }

            else if(m[1] == 0 && m[2] == 1)
            {
                dataset[dataset[i+3]] = dataset[dataset[i+2]] + dataset[i+1];
            }

            else
            {
                printf("Hata");
            }
            i+=4;
        }

        else if(m[4] == 2)
        {
            if(m[1] == 0 && m[2] == 0)
            {
                dataset[dataset[i+3]] = dataset[dataset[i+2]] * dataset[dataset[i+1]];
            }

            else if(m[1] == 1 && m[2] == 0)
            {
                dataset[dataset[i+3]] = dataset[i+2] * dataset[dataset[i+1]];
            }

            else if(m[1] == 1 && m[2] == 1)
            {
                dataset[dataset[i+3]] = dataset[i+2] * dataset[i+1];
            }

            else if(m[1] == 0 && m[2] == 1)
            {
                dataset[dataset[i+3]] = dataset[dataset[i+2]] * dataset[i+1];
            }

            else
            {
                printf("Hata");
            }
            i+=4;
        }

        else if(m[4] == 3)
        {
            dataset[dataset[i+1]] = input;
            i+=2;
        }

        else if(m[4] == 4)
        {
            if(m[2] == 1)
            {
                output = dataset[i+1];
                printf("%d",output);
            }
            else
            {
                output = dataset[dataset[i+1]];
                printf("%d",output);
            }
            i+=2;
        }

        else if(m[4] == 9)
        {
            printf("\nHata 99");
            break;
        }
    }





}
