#include <stdio.h>

int main(void)
{
    FILE *file = fopen("p8.txt","r");

    fseek(file, 0, SEEK_END);
    unsigned long int len = ftell(file);
    rewind(file);

    int dataset[len/150][150];

    while (!feof(file))
    {   
        for(int i=0;i<len/150;i++)
        {
            for(int j=0;j<150;j++)
            {
                fscanf(file,"%1d",&dataset[i][j]);
            }
        }
    }

    int answer[3] = {200,0,0};
    int counter=0;

    for(int i=0;i<len/150;i++)
    {
        for(int j=0;j<150;j++)
        {
            if(dataset[i][j] == 0)
            {
                counter++;
            }
        }

        if(answer[0] > counter)
        {
            answer[0] = counter;
            answer[1] = i;
        }
        counter = 0;
    }

    answer[0] = 0;
    answer[2] = 0;


    for(int j=0;j<150;j++)
    {
        {
            if(dataset[answer[1]][j] == 1)
            {
                answer[0] = answer[0] += 1;
            }
            else if(dataset[answer[1]][j] == 2)
            {
                answer[2] = answer[2] += 1;
            }
        }
    }
    
    int picture[150];
    for(int j=0;j<150;j++)
    {
        for(int i=0;i<100;i++)
        {
            if(dataset[i][j] == 0)
            {
                picture[j] = 0;
                break;
            }

            else if(dataset[i][j] == 1)
            {
                picture[j] = 1;
                break;
            }
        }
    }

       printf("\n");
        for(int i=0,j=1;i<150;i++,j++)
        {
            if(picture[i] == 0) printf(" ");
            if(picture[i] == 1) printf("█");//█
            if(j == 25) j=0,printf("\n");
        }

        
        

    
}