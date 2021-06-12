#include <stdio.h>
#include <math.h>



void extract(int i,long int *pass)
{
    for(int j=1,b=4;j<6;j++,b--)
    {
        pass[b] = ( (i%(int)pow(10,j) - i%(int) pow(10,(j-1)) )/(int) pow(10,j-1) );
    }
}

void check(long int *m,long int *data,int j,long int relative_base)
{   
    int i = 3;
    int k=0;

    if(m[4] == 1 || m[4] == 2 || m[4] == 7 || m[4] == 8)
    {
        i = 1;
        k = 3;
        if( m[0] == 0)
        {
            m[0] = data[j+k];
        }

        else if( m[0] == 2)
        {
            m[0] = relative_base + data[j+k];
        }
        k--;
    }

    else if( (m[4] == 3 || m[4] == 4 || m[4] == 9) && m[3] != 9)
    {

        i = 3;
        k = 1;
        if( m[2] == 0)
        {
            m[0] = data[j+k];
        }
        else if (m[2] == 1)
        {
            m[0] = j+k;
        }
        else if( m[2] == 2)
        {
            m[0] = relative_base + data[j+k];
        }
    }

    else if(m[4] == 5 || m[4] == 6)
    {
        i = 1;
        k = 2;
    }

    for(;i<3;i++,k--)
    {
        if(m[i] == 0)
        {
            m[i] = data[data[j+k]];
        }

        else if(m[i] == 1)
        {
            m[i] = data[j+k];
        }

        else if(m[i] == 2)
        {
            m[i] = data[relative_base+ data[j+k] ];
        }
    }
}



int main(void)
{

    FILE *file = fopen("p9.txt","r");
    int box;
    int size = 0;

    long int input,output,relative_base;
    input = 0;
    output = 0;
    relative_base = 0;

    while (!feof(file))
    {
        fscanf(file,"%d,",&box);
        size++;
    }


    long int dataset[size];

    for(int i=0;i<size;i++)
    {
        dataset[i] = 0;
    }
    rewind(file);
    box = 0;
    while (!feof(file))
    {
        fscanf(file,"%ld,",&dataset[box]);
        box++;

    }
    long int m[5] = {0,0,0,0,0};

    for(int i=0;i<size;)
    {
        extract(dataset[i],m);
        check(&m,&dataset,i,relative_base);

        if(m[4] == 1)
        {
            dataset[m[0]] = m[1] + m[2];
            i += 4;
        }

        else if(m[4] == 2)
        {
            dataset[m[0]] = m[1] * m[2];
            i += 4;
        }
        
        else if(m[4] == 3)
        {
            printf("İnput: ");
            scanf("%ld",&input);
            dataset[m[0]] = input;
            i+=2;
        }

        else if(m[4] == 4)
        {
            output = dataset[m[0]];
            printf("%ld\n",output);
            if(output == 99) break;
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
                dataset[m[0]] = 1;
            }
            else
            {
                dataset[m[0]] = 0;
            }
            i+=4;
        }

        else if(m[4] == 8)
        {
            if(m[1] == m[2])
            {
                dataset[m[0]] = 1;
            }
            else
            {
                dataset[m[0]] = 0;
            }
            i += 4;  
        }

        else if(m[4] == 9 && m[3] != 9)
        {
            relative_base = relative_base + dataset[m[0]];
            i+=2;
        }

        else if(m[4] == 9 && m[3] == 9)
        {
            printf("\nHata 99");
            break;
        }

        

    }
    //printf("\n%d",dataset[4]);

}
