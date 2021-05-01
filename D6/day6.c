#include <stdio.h>
#include <string.h>


typedef struct planet
{
    int orbit_number;
    struct planet *coordinate;
}planet;


void search(char *planet_name,char *dataset,int data_size)
{   
    
    for(int i=0; i<data_size;i++)
    {
    
        if(!strcmp(planet_name,dataset))
        {   
            printf("\narama %p",dataset);
            printf("konum %d ",i);
            //if(i%2 == 0) draw();
        }
        //printf("%s",dataset[i]);
        dataset+=4;
    }
    
}

void draw()
{
    printf("Çalştı");
}


int main(void)
{   

    FILE *file = fopen("p6.txt","r");

    char box[8];
    int size = 0;
    char *ayrac = ")";
    char *box2;
    while (!feof(file))
    {
        fscanf(file,"%s",box);
        size++;
    }

    rewind(file);

    char dataset[size*2][4];
    char *pd = dataset;
    int i=-1;
    while (!feof(file))
    {
        fscanf(file,"%s",box);
        box2 = strtok(box,ayrac);

        i++;

        for(int j=0; j<4;j++) dataset[i][j] = box2[j];
        
        box2 = strtok(NULL,ayrac);
        i++;

        for(int j=0; j<4;j++) dataset[i][j] = box2[j];
    }
    for(int j=0;j<size*2;j++) printf("%s\n",dataset[j]);

    char a[4]="GGG";
    char *pp = a;
    
    /*
    for(int j=0;j<size*2;j++)
    {
        if(!strcmp(pp,pd))
        {
            printf("\n%p",pd);
            printf("\nkonum 2 %d",j);
            
        }
        pd+=4;
    }
    */

    for(int k=0;k<22;k++)
    {
        printf("%p\n",dataset[k]);
    }


    search(&a,&dataset,size*2);

    //for(int j=0;j<size*2;j++) printf("%s\n",dataset[j]);


}