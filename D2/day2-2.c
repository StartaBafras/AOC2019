
#include <stdio.h>
#include <stdlib.h>
int experimenter(int *dataset, int counter,int  val1,int val2);


int main(void)
{
    FILE *dosya = fopen("p2.txt","r");
    char a;
    int file[132];//3 yerden değiştirilmeli
    int temp[3];
    int stroge_counter=0;
    int temp_counter=0;


    while(!feof(dosya))
    {

        a = getc(dosya);

        if (a == ',')
        {

            if (temp_counter == 3)
            {

                file[stroge_counter] = (temp[0]*100) + (temp[1]*10) + temp[2];
                stroge_counter +=1;
            }

            else if (temp_counter == 2)
            {

                file[stroge_counter] = (temp[0]*10) + temp[1];
                stroge_counter +=1;
            }
             
            else
            {
                file[stroge_counter] = temp[0];
                stroge_counter +=1;
            }

            // Must be clean temp?
            temp_counter = 0;
            
        }

        else
        {
            temp[temp_counter] = converter(a);
            temp_counter +=1;

        }
        
    }
    //printf("Counter: %d \n",stroge_counter);

    file[1] = 12;
    file[2] = 2;
    for(int i=0;i<99;i++)
    {
        for(int p=0;p<99;p++)
        {
           experimenter(&file,stroge_counter,i,p); 
        }
    }
    


}
int experimenter(int *dataset, int counter,int  val1,int val2)
{
    int file[counter];
    for(int i=0;i<=132;i++)
    {
        file[i] = dataset[i];
    }

    file[1] = val1;
    file[2] = val2;

    for(int i=0;i<132;i+=4)
        {

            if(file[i] == 1)
            {   
                file[file[i+3]] = file[file[i+1]] + file[file[i+2]];
            }

            else if(file[i] == 2)

            {
                file[file[i+3]] = file[file[i+1]] * file[file[i+2]];
            }

            if (file[0] == 19690720)
            {
               printf("%d   %d     %d\n",file[1],file[2],file[0]);
            }
        
        }

}


int converter(char *number)
{
    if (number == '1') return 1;
    else if(number == '2') return 2;
    else if(number == '3') return 3;
    else if(number == '4') return 4;
    else if(number == '5') return 5;
    else if(number == '6') return 6;
    else if(number == '7') return 7;
    else if(number == '8') return 8;
    else if(number == '9') return 9;
    else if(number == '0') return 0;

}