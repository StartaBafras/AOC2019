#include <stdio.h>
#include <stdlib.h>

int main() {

int a;
int b;

FILE *klas;
klas = fopen("konum","r+");

b = 0;
while(!feof(klas)) {

  fscanf(klas,"%d",&a);

    a = a/3-2;
    b = a + b;
}
 printf("Total Fuel Mass is %d",b);
 fclose(klas);

return 0 ;

}