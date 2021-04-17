#include <stdio.h>
#include <math.h>



void select(int i,int *pass)
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
                printf("%d\n",output);
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
            printf("\nHata 99");
            break;
        }
    }


}
