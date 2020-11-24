#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nconta[25];
    char nome[15];
    char apelidos[30];
    char dni[10];
    char enderezo[30];
    float saldo;
} cliente;

void consultarusuario(){
    char dni[10];  //porque un dni tiene 9 letras y un /0 al final
    int cmp;
    int condicion;
    cliente c;
    FILE* idf;
    if((idf=fopen("archivo.bin","rb"))==NULL) {
        printf("erro");
        return;
    }
    else{
        printf("introduce el dni del usuario:");
        scanf(" %s",dni);
        fseek(idf,0,SEEK_SET); //  poñemonos ao principio
        condicion=!feof(idf);
        while (condicion) { //leer, comprobar se o dni das personas e igual ao que escribiron antes,comprobar si estamos ao final del arquivo
            fread(&c,sizeof(cliente),1,idf);
            cmp=strcmp(c.dni,dni);
            if(cmp==0){
                printf(" %s %s %s %s %s %f\n",c.nconta,c.nome,c.apelidos,c.dni,c.enderezo,c.saldo);
            }
            condicion=!feof(idf) && cmp;
        }
    }
    fclose(idf);
}
void contanova(){
    cliente c;
    FILE* idf;
    if((idf=fopen("archivo.bin","ab"))==NULL){
        printf("erro");
        return;
    }
    else{
        printf("introduce a conta\n");
        scanf(" %s", c.nconta);
        printf("introduce o nome\n");
        scanf(" %s",c.nome);getchar();
        printf("introduce os apelidos\n");
        gets(c.apelidos);
        printf("introduce o dni\n");
        scanf(" %s", c.dni);getchar();
        printf("introduce o enderezo\n");
        gets( c.enderezo);
        printf("introduce o saldo\n");
        scanf(" %f", &(c.saldo));
        fseek(idf,0,SEEK_END);
        fwrite(&c,sizeof(cliente),1,idf);
    }
    fclose(idf);
}
void modificarsaldo(){
    char dni[10];
    int opcion,cmp;
    float dinero;
    FILE* idf;
    cliente c;
    if((idf=fopen("archivo.bin","r+b"))==NULL) {printf("erro");return;}
    else{
        printf("introduce o dni");
        scanf(" %s", dni);
        while(!feof(idf)){
            fread(&c,sizeof(cliente),1,idf);
            cmp=strcmp(c.dni,dni);
            if(cmp==0){
                fseek(idf,(-1*sizeof(cliente)),SEEK_CUR);
                printf("para ingresar pulse 1, para retirar pulse 2");
                scanf(" %d",&opcion);
                if (opcion==1) {
                    printf("cantidad que desea ingresar:"); scanf(" %f",&dinero);
                    c.saldo+=dinero;
                    fwrite(&c,sizeof(cliente),1,idf);
                    return;
                }
                else if (opcion==2) {
                    printf("cantidad que desea retirar:"); scanf(" %f",&dinero);
                    c.saldo-=dinero;
                    fwrite(&c,sizeof(cliente),1,idf);
                    return;
                }
            }
            else printf("non se atopou o dni");
        }
    }
    fclose(idf);
}
void enderezo(){
    FILE* idf;
    cliente c;
    char dni[10];
    int cmp, flag_cambiado;
    if((idf=fopen("archivo.bin","rb+"))==NULL) printf("erro");
    else{
        printf("introduce o dni de quen queres cambiar o enderezo");
        scanf(" %s",dni);
        flag_cambiado=1;
        while(flag_cambiado){
            fread(&c,sizeof(cliente),1,idf);
            flag_cambiado = !feof(idf);
            cmp=strcmp(c.dni,dni);
            if(cmp==0){
                fseek(idf,(-1*sizeof(cliente)),SEEK_CUR);
                printf("introduce o novo enderezo");
                gets(c.enderezo);
                fwrite(&c,sizeof(cliente),1,idf);
                flag_cambiado=0;
            }
        }
    }
    fclose(idf);
}
int main() {
    int opcion;
    do{
        printf("\nque operacion quieres realizar?\n");
        printf("se queres leer dni pulsa 1\n");
        printf("se queeres engadir unha nova conta pulsa 2\n");
        printf("se queres engadir ou retirar diñeiro pulsa 3\n");
        printf("se queres modificar o enderezo pulsa 4\n");
        printf("se queres salir pulsa 0\n");
        scanf(" %d",&opcion);
        switch(opcion){
            case 1:
                consultarusuario();
                break;
            case 2:
                contanova();
                break;
            case 3:
                modificarsaldo();
                break;
            case 4:
                enderezo();
                break;
        }
    }while(opcion!=0);
    return 0;
}
