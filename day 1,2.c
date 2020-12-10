#include <stdio.h>
#include <stdlib.h>

int main() {

int a;
int b;
int c;
int d;
FILE *klas;
klas = fopen("konum","r+");

b = 0;
while(!feof(klas)) {

  fscanf(klas,"%d",&a);

    a = a/3-2;
    b = a + b;
}
d = b;
    while(b/3-2 < 0 ) {
    b = b/3-2 ;
    c = b+c;

    }
c = d + c;


 printf("Total Fuel Mass is %d",c);
 fclose(klas);

return 0 ;

}
