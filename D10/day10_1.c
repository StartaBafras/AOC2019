#include <stdio.h>


typedef struct 
{
    int astro; 
    int x;
    int y;
    float detected[400];
    int detectedy[400];
    
}asteroid_map;

int main(void)
{
    FILE *file = fopen("p11.txt","r");

    char c[2];
    int caunter = -1;

    while (c[0] != '\n')
    {
        fscanf(file,"%c",c);
        caunter++;
    }
    rewind(file);

    asteroid_map map[caunter][caunter];

    asteroid_map *pd = map;

    while (!feof(file))
    {
        fscanf(file,"%c",c);
        if( c[0] != '\n')
        {
            if(c[0] == '#') pd->astro = 1;

            else pd->astro = 0;

            pd++;
        }

    }

    pd = &map; // Kordinatlar yerleştirildi ama çok uzadı
    for(int y=0;y<caunter;y++)
    {

        for(int x=0;x<caunter;x++)
        {
            pd->x = x;
            pd->y = y;
            //pd->detected[0] = 0;
            pd++;
        }
    }

    pd = &map;
    int slopey = 0;
    int slopex = 0;
    float slope = 0;
    int j = 0;
    int answer = 0;
    while(pd->astro == 0)
    {
        pd++;
    }
    pd = &map[0][1];
    int o = 0;
    int p = 1;

    for(int i=0;i<caunter*caunter;i++)
    {
        for(int y=0;y<caunter;y++)
        {
            for(int x=0;x<caunter;x++)
            {
                if(map[y][x].astro == 1)
                {
                    slopey = (pd->y - y);
                    slopex = (pd->x - x);
                    if( slopey == 0 && slopex == 0)
                    {
                        continue;
                    }

                    else if(slopex == 0)
                    {
                        if(slopey < 1)
                        {
                            slope = -100;
                        }
                        else slope = 100;

                        
                    }

                    else if(slopey == 0)
                    {
                        if(slopex <1)
                        {
                            slope = -200;
                        }
                        else slope = 200;
                        
                    }

                    if(slope == 0)
                    {
                        slope = (float) slopey/slopex;  
                    }
                    
                    int a = 0;
                    for(int c=0;pd->detected[c] != 0;c++)
                    {
                        if(pd->detected[c] == slope)
                        {
                            if(pd->y >= y)
                            {
                                if(pd->detectedy[c] == 1)
                                {
                                    a = 1;
                                }

                            }
                            else
                            {
                                if(pd->detectedy[c] == -1)
                                {
                                    a = 1;
                                }
                            }
                            //a = 1;
                        }
                    }

                    if(a == 1)
                    {
                        slope = 0;
                        continue;
                    } 

                    for(;pd->detected[j] == 0; j++)
                    {   
                        
                    
                        if(pd->detected[j] == 0)
                        {
                            pd->detected[j] = slope;
                            if(pd->y >= y)
                            {
                                pd->detectedy[j] = 1;
                            }
                            else pd->detectedy[j] = -1;
                            j++;
                            break;
                        }
                        
                    }
                }
                slope = 0;  
            }
        }

        printf("x= %d, y = %d, algılanan = %d \n",pd->x,pd->y,j);
        //printf("adres = %p\n",pd);
        pd++;
        
        //p++;
        //pd = &map[o][p];
        if(answer < j) answer = j;
        j = 0;
        printf("\n\n cevap: %d",answer);
        while(pd->astro == 0 && pd != NULL)
        {
            pd++;
        }

    }


}