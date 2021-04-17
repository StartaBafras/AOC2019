#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{

    FILE *file = fopen("p5.txt","r");
    int box;
    int size =0;
    int parameter_mod[4];
    int parameter_value[2];
    short int input = 1;
    short int output =  NULL;


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

    //printf("%d",dataset[224]);
    //dataset[225] = 1;



    for(int i=0;i<size;)
    {
        //printf("%d %d %d %d \n",file[i],file[i+1],file[i+2],file[i+3]);
        if(dataset[i] == 1)
        {   
            dataset[dataset[i+3]] = dataset[dataset[i+1]] + dataset[dataset[i+2]];
            i+=4;
        }

        else if(dataset[i] == 2)
        {
            dataset[dataset[i+3]] = dataset[dataset[i+1]] * dataset[dataset[i+2]];
            i+=4;
        }

        else if(dataset[i] == 3)
        {
            dataset[dataset[i+1]] = input;
            i+=2;
        }

        else if(dataset[i] == 4)
        {
            
            output = dataset[dataset[i+1]];
            printf("%d",output);
            i+=2;

        }

        else if(dataset[i] == 99)
        {
            break;
        }

        else
        {   

            parameter_mod[0] = (dataset[i]-(dataset[i]%1000))/1000;
            parameter_mod[1] = (dataset[i]%1000-(dataset[i]%100))/100;
            parameter_mod[2] = (dataset[i]%100-(dataset[i]%10))/10;
            parameter_mod[3] = (dataset[i]%10-(dataset[i]%1))/1;
            

            if(parameter_mod[1] == 1)
            {
                parameter_value[0] = dataset[i+1];
            }

            if(parameter_mod[1] == 0)
            {
                parameter_value[0] = dataset[dataset[i+1]];
            }

            if(parameter_mod[0] == 1)
            {
                parameter_value[1] = dataset[i+2];
            }

            if(parameter_mod[0] == 0)
            {
                parameter_value[0] = dataset[dataset[i+2]];
            }

            if(parameter_mod[3] == 1)
            {
                dataset[dataset[i+3]] = parameter_value[0] + parameter_value[1];
            }

            if(parameter_mod[3] == 2)  
            {
                dataset[dataset[i+3]] = parameter_value[0] * parameter_value[1];
            }  

            i+=4;

        }
        

    }
        

}

