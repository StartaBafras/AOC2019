#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct planet
{
    char orbit_name[4];
    struct planet *next_coordinate[5];//5 ten fazla olabilir mi?
    struct planet *previous_coordinate;
}planet;

//fdata her zaman bütün listeyi taraması için var onu göndermeden önce dataset hep kullanıldığı için kaldığı yerden arama yapıyordu
void search(char *planet_name,char *dataset,int data_size,planet *p,char *fdata)
{   
    
    for(int i=0; i<data_size;i++)
    {
    
        if(!strcmp(planet_name,dataset))
        {   
            //printf("\narama %p",dataset); Adresler doğru mu denemesi
            //printf("konum %d ",i);

            if(i%2 == 0)//Gezegen ararken istenen şey sol tarafta olmasıdır böylece yörüngede olan gezegen sağ tarafta kalır A)B deki A gibi datasette bu konumdakiler her zaman çift sayıya denk gelen indiste
            {
                draw(planet_name,dataset+4,p,data_size,fdata);
            }
        }
        dataset+=4;
    }

}

void draw(char *planet_name,char *dataset,planet *p,int data_size,char *fdata)
{   
    for(int i=0;i<5;i++)
    {
        if(p->next_coordinate[i] == NULL)
        {
            p->next_coordinate[i] = malloc(sizeof(planet));
            strcpy(p->next_coordinate[i]->orbit_name,dataset);
            p->next_coordinate[i]->next_coordinate[0] = NULL;
            p->next_coordinate[i]->previous_coordinate = p;
            p = p->next_coordinate[i];
            search(dataset,fdata,data_size,p,fdata);
            break;
        }
    }
    //printf("Çalştı");
}

void explorer(planet *p,int counter,int *answer,char *pre_planet)
{
    if(strcmp("COM",p->orbit_name))
    {
        if(strcmp(pre_planet,p->previous_coordinate) )
            {
                
                explorer(p->previous_coordinate,counter+1,answer,p->orbit_name);

            }
    }
    for(int i=0;i<5;i++)
    {
        if(p->next_coordinate[i] != NULL)
        {   

            explorer(p->next_coordinate[i],counter+1,answer,p->orbit_name);//arttırma azaltmaya çözüm lazım
        }
        
        if(!strcmp(p->orbit_name,"YOU")) printf("\nShortest Path: %d",counter-2);// YOU ve SAN değerlerini gezegen gibi yazdığımız için cevapta bunları hesaba katmamalıyız bu yüzden 2 çıkardık

    }
    //printf("\n %s :%d",p->orbit_name,counter);
    //*answer += counter;
    
}

planet *explorer2(planet *p,char *searched_planet,int *answer)
{
    for(int i=0;i<5;i++)
    {   
        if(p->next_coordinate[i] != NULL)
        {
            if(!strcmp(p->next_coordinate[i]->orbit_name,searched_planet)) 
            {   
                p = p->next_coordinate[i];
                //return p; neden adres döndürmüyor?
                explorer(p,0,answer,searched_planet);
            }
            else
            {
                explorer2(p->next_coordinate[i],searched_planet,answer);
            }
            
        }

    }
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
        box2 = strtok(box,ayrac);// ilk kısım alındı

        i++;

        for(int j=0; j<4;j++) dataset[i][j] = box2[j];//ilk kısım yazıldı
        
        box2 = strtok(NULL,ayrac);//2. kısım alındı
        i++;

        for(int j=0; j<4;j++) dataset[i][j] = box2[j];//2. kısım yazıldı
    }
    //for(int j=0;j<size*2;j++) printf("%s\n",dataset[j]); belleğe alınan listeyi yazdırır

    char aranan[4]="COM";

    planet *p;

    p = malloc(sizeof(planet));
    strcpy(p->orbit_name,"COM");
    p->next_coordinate[0] = NULL;
    search(&aranan,&dataset,size*2,p,&dataset);


    //printf("\n%s",p->orbit_name); yukarıdaki satırların gerçekleşip gerçekleşemdiğinin kontrülü
    //printf("\n%s",p->next_coordinate[0]->orbit_name);


    int *a = malloc(sizeof(int));
    *a = 0;

    explorer2(p,"SAN",a);//2. soruda a işaretçisi kullanılmasa da olur


    



}