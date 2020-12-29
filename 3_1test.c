#include <stdio.h>
#include <stdlib.h>

int main ()
{
 //Dosyayı okuma ve diziye yerleştirme kısmı
FILE *input1 = fopen("/home/ubuntu/input1.txt","r+");
FILE *input2 = fopen("/home/ubuntu/input2.txt","r+");
FILE *history1 = fopen("/home/ubuntu/gecmis.txt","w+");
FILE *history2 = fopen("/home/ubuntu/gecmis.txt","w+");

//dosya sayma
int noktaboyutu1 = 0;
int noktaboyutu2 = 0;
while(!feof(input1))
        {
            char uselessc;
            int  uselessd;
            fscanf(input1,"%c%d,",&uselessc,&uselessd);
            noktaboyutu1++;
        }
while(!feof(input2))
        {
            char uselessc1;
            int  uselessd1;
            fscanf(input2,"%c%d,",&uselessc1,&uselessd1);
            noktaboyutu2++;
        }
//dosyayı başa çekme
rewind(input1);
rewind(input2);


char L1[noktaboyutu1];
char L2[noktaboyutu2];
int X1[noktaboyutu1];
int X2[noktaboyutu2];
int a1 = 0;
int a2 = 0;
 while(!feof(input1))
            {
                while (a1 < noktaboyutu1)
                    {
                        fscanf(input1,"%c%d,",&L1[a1],&X1[a1]);
                        printf("Yer %c Miktar %d\n",L1[a1],X1[a1]);
                        a1++;
                    }

            }
 while(!feof(input2))
            {
                while (a2 < noktaboyutu2)
                    {
                        fscanf(input2,"%c%d,",&L2[a2],&X2[a2]);
                        printf("Yer2 %c Miktar2 %d\n",L2[a2],X2[a2]);
                        a2++;
                    }

            }

a1 = 0;
a2 = 0;
int xn1 = 0;
int xn2 = 0;
int yn1 = 0;
int yn2 = 0;
int xf1 = 0;
int xf2 = 0;
int yf1 = 0;
int yf2 = 0;
 while(a1 < noktaboyutu1)
            {
                if(L1[a1]=='R')
                    {
                        xf1 = xn1 + X1[a1];
                        for (;xf1 <= xn1;xn1++)
                            {
                               fprintf(history1,"(%d,%d),",xn1,yn1);
                            }
                    }

                else if(L1[a1]=='L')
                    {
                        xf1 = xn1 - X1[a1];
                        for (;xf1 >= xn1;xn1--)
                            {
                               fprintf(history1,"(%d,%d),",xn1,yn1);
                            }
                    }

                else if(L1[a1]=='U')
                    {
                        yf1 = yn1 + X1[a1];
                        for (;yf1 <= yn1;yn1++)
                            {
                               fprintf(history1,"(%d,%d),",xn1,yn1);
                            }
                    }

                else if(L1[a1]=='D')
                    {
                        yf1 = yn1 - X1[a1];
                        for (;yf1 >= yn1;yn1--)
                            {
                               fprintf(history1,"(%d,%d),",xn1,yn1);
                            }
                    }
                    a1++;


            }
 while(a2 < noktaboyutu2)
            {
                if(L2[a2]=='R')
                    {
                        xf2 = xn2 + X2[a2];
                        for (;xf2 != xn2;xn2++)
                            {
                               fprintf(history2,"(%d,%d),",xn2,yn2);
                            }
                    }

                else if(L2[a2]=='L')
                    {
                        xf2 = xn2 - X2[a2];
                        for (;xf2 != xn2;xn2--)
                            {
                               fprintf(history2,"(%d,%d),",xn2,yn2);
                            }
                    }

                else if(L2[a2]=='U')
                    {
                        yf2 = yn2 + X2[a2];
                        for (;yf2 != yn2;yn2++)
                            {
                               fprintf(history2,"(%d,%d),",xn2,yn2);
                            }
                    }

                else if(L2[a2]=='D')
                    {
                        yf2 = yn2 - X2[a2];
                        for (;yf2 != yn2;yn2--)
                            {
                               fprintf(history2,"(%d,%d),",xn2,yn2);
                            }
                    }
                    a2++;


            }

//içine yazdığım txt dosyalarını kapatıp okumak için tekrar açıyorum
fclose(history1);
fclose(history2);
history1 = fopen("/home/ubuntu/gecmis.txt","r+");
history2 = fopen("/home/ubuntu/gecmis.txt","r+");

//Yol uzunluklarını buluyorum
int sayar_a1 = 0;
int sayar_a2 = 0;
while(!feof(history1))
    {
    int önemsiz[2];
    fscanf(history1,"(%d,%d) ",&önemsiz[0],&önemsiz[1]);
    sayar_a1++;
    }
    printf("1 rotanın nokta sayısı %d dir",sayar_a1);


while(!feof(history2))
    {
    int önemsiz[2];
    fscanf(history2,"(%d,%d) ",&önemsiz[0],&önemsiz[1]);
    sayar_a2++;
    }
    printf("2 rotanın nokta sayısı %d dir",sayar_a2);

    //okunmuş listeyi başa sarıyorum
    rewind(history1);
    rewind(history2);
    //ortak noktaları kıyasalamak için yeni tanımlamalar yapıyorum.
    int ax1[sayar_a1];
    int ay1[sayar_a1];
    int ax2[sayar_a2];
    int ay2[sayar_a2];
    int aaa = 0;

//noktaları diziye dolduruyorum.
while(!feof(history1))
    {
    fscanf(history1,"(%d,%d) ",&ax1[aaa],&ay1[aaa]);
    aaa++;
    }
     aaa = 0;
while(!feof(history2))
    {
    fscanf(history2,"(%d,%d) ",&ax2[aaa],&ay2[aaa]);
    aaa++;
    }
FILE *same = fopen("konum","w+");

    //for döngüsünün en uzun yola  göre test etmesi gerekiyor. En çok yol alana göre bulması adına bir koşul yazıyorum.

    for(int xxx2 = 0;xxx2<sayar_a2;xxx2++)
        {
            for (int xxx1 = 0;xxx1 < sayar_a1;xxx1++)
            {
                if(ax1[xxx1] == ax2[xxx2])
                {
                    for(int yyy2 = 0; yyy2 < sayar_a2 ; yyy2++)
                    {
                        for(int yyy1 = 0;yyy1 < sayar_a1;yyy1++)
                        {
                            if(ay1[yyy1] == ay2[yyy2])
                            {
                                fprintf(same,"(%d,%d),",ax1[xxx1],ay2[yyy2]);
                            }
                        }
                    }
                }
            }
        }
fclose (same);
fclose (history1);
fclose (history2);
same =fopen ("","r")
int ortaksayımik
while (!feof(same))
                {
                fscanf()
                }

        // Manhattan uzaklıklarını hesaplama zamanıı

