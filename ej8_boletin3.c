#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define D 20

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
    int cmp; /////////borrar//////
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
        fseek(idf,0,SEEK_SET); // Nos ponemos al principio
            condicion=!feof(idf);
            while (condicion) { //leer, comprobar si el dni de las personas es igual al que escribieron antes,comprobar si estamos al final del archivo
                fread(&c,sizeof(cliente),1,idf);
                cmp=strcmp(c.dni,dni);
                if(cmp==0){
                    printf(" %s %s %s %s %s %f",c.nconta,c.nome,c.apelidos,c.dni,c.enderezo,c.saldo);
                }
                condicion=!feof(idf) && !cmp;
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
        scanf(" %s", c.nconta); //metemos el resto
        printf("introduce o enderezo\n");
        scanf(" %s", c.enderezo); //metemos el resto
        printf("introduce o dni\n");
        scanf(" %s", c.dni); //metemos el resto
        printf("introduce o saldo\n");
        scanf(" %f", &(c.saldo)); //metemos el resto
        fseek(idf,0,SEEK_END);
        fwrite(&c,sizeof(cliente),1,idf);
    }//al modificar datos estamos leyendo un struct, al leer un struct vamos a querer un fseek  para situarnos al final del archivo
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
                        fwrite(&c,sizeof(cliente),1,idf), sizeof(cliente);
                        return;
            } else if (opcion==2) {
                        printf("cantidad que desea retirar:"); scanf(" %f",&dinero);
                        c.saldo-=dinero;
                        fwrite(&c,sizeof(cliente),1,idf);
                        return;
            } else {
                return; //CAMBIAR
            }
            }
            else printf("non se atopou o dni");
        }
    }
    fclose(idf);
}
void enderezo(){
    /*char dni[10];
    int i,cmp;
    if(idf=fopen("archivo.bin","r+b")==NULL) printf("erro");
    else{
        printf("introduce o dni de quen queres cambiar o enderezo");
        scanf(" %s",&dni);
        while(feof(idf)){
            fread(&c[i],sizeof(cliente),6,idf);
            cmp=strcmp(c[i].dni,dni);
            if(cmp==0){
                printf("introduce o novo enderezo");
                gets(&c[i].enderezo);
                fwrite(&c[i].enderezo,sizeof(char),15,idf);
            }
            i++;
        }
    }
    fclose(idf);*/
}
 //fwrite(&c,cliente.dni)
int main() {
    int opcion,i;
    do{
        printf("que operacion quieres realizar?\n");
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