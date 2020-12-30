#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	 int deger=0,mando=0;
    int toplam=0,sayac=0;
    int grogu=0,ashoka=0;
    int jedi=0,sith=0;
    int yatay=0,dikey=0;
    char anakin;
    char ikinci;
   FILE *dosya ;
    dosya= fopen("C:\\Users\\Yonis\\Desktop\\dosya.txt","r+");
	FILE *iki;
	iki= fopen("C:\\Users\\Yonis\\Desktop\\iki.txt","r+");
	FILE *ucuncu;
	ucuncu= fopen("ucuncu.txt","r+");
	FILE *dorduncu;
	dorduncu=fopen("dorduncu.txt","r+");
	
	while(!feof(iki)){
		fscanf(iki,"%c%d,",&anakin);
		grogu++;
	}
	char yoda[grogu];
	int master[grogu];
	
	while(!feof(dosya)){
		fscanf(dosya,"%c%d,",&ikinci);
		toplam++;
	}
	char karakter[toplam];
	int sayi[toplam];
	//printf("%d",toplam);
rewind(dosya);
rewind(iki);
  while(!feof(iki)){
		fscanf(iki,"%*c %d,",&master[mando]);
		mando++;
	}
  while(!feof(dosya)){
    fscanf(dosya,"%*c %d,",&sayi[deger]);
    //printf("%d\n",sayi[deger]);
    deger++;
    }
rewind(iki);
rewind(dosya);
	while(!feof(iki)){
		fscanf(iki,"%c %*d,",&yoda[ashoka]);
		ashoka++;
	}
    while(!feof(dosya)){
    fscanf(dosya,"%c %*d,",&karakter[sayac]);
    //printf(" %c\n",karakter[sayac]);
	 sayac++;
   }
   int i=0;
   int k;
   int h;
   int x=0,y=0;
   rewind(dosya);
   rewind(iki);
   for( h=0;h<toplam;h++){
   
    if(karakter[i]=='R')
        {
            for( k=0;k<sayi[i];k++)
            {
            x=x+1;
            fprintf(ucuncu,"%d,%d\n",x,y);
            }
        }
	else if(karakter[i]=='L')
        {
            for( k=0;k<sayi[i];k++)
            {
            x=x-1;
            fprintf(ucuncu,"%d,%d\n",x,y);
            }
        }
        else if(karakter[i]=='U')
        {
            for( k=0;k<sayi[i];k++)
            {
            y=y+1;
            fprintf(ucuncu,"%d,%d\n",x,y);
            }
        }
        else if(karakter[i]=='D')
        {
            for( k=0;k<sayi[i];k++)
            {
            y=y-1;
            fprintf(ucuncu,"%d,%d\n",x,y);
            }
        }
		i++;}
int j=0;

int x2=0,y2=0;
int g;

	for( g=0;g<grogu;g++)
        {
        


        if(yoda[j]=='R')
        {
            for(k=0;k<master[j];k++)
            {
            x2=x2+1;
            fprintf(dorduncu,"%d,%d\n",x2,y2);
            }
        }

         else if(yoda[j]=='L')
        {
           for(k=0;k<master[j];k++)
            {

            x2=x2-1;
            fprintf(dorduncu,"%d,%d\n",x2,y2);
            }
        }

        else if(yoda[j]=='U')
        {
            for(k=0;k<master[j];k++)
            {
            y2=y2+1;
            fprintf(dorduncu,"%d,%d\n",x2,y2);
            }
        }

         else if(yoda[j]=='D')
        {
            for(k=0;k<master[j];k++)
            {
            y2=y2-1;
            fprintf(dorduncu,"%d,%d\n",x2,y2);
            }
        }


        j++;
        }
        
        rewind(ucuncu);
        rewind(dorduncu);
       
	   
int kontrol_1[154640];
int kontrol_2[154640];
int kontrol_3[157490];
int kontrol_4[157490];

int c=0,v=0;
int step1;
int step;
step1=-1;


for(c=0;c<154530;c++)
{
fscanf(ucuncu,"%d,%d",&kontrol_1[c],&kontrol_2[c]);
}

for(v=0;v<157570;v++)
{
fscanf(dorduncu,"%d,%d",&kontrol_3[v],&kontrol_4[v]);
}


    for(c=0;c<154530;c++)
    {
        for(v=0;v<157570;v++)
        {
            if(kontrol_1[c]==kontrol_3[v] &&kontrol_2[c]==kontrol_4[v])
            {
              
                
                 printf("%d %d",kontrol_1[c],kontrol_2[c]);
                 printf("%d",step+step1);//3.2
                 
                
                
            }
        }
        rewind(ucuncu);//3.2
        step++;//3.2
        

    }


    fclose(dosya);
    fclose(iki);
    fclose(ucuncu);
    fclose(dorduncu);
	return 0;
}
