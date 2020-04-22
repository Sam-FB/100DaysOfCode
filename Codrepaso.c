#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct empleado{
     int folio;
     char nombre[15];
     char edad[3];
     char num[11];
     float salario;
     char freeday[10];
     char turno[10];
     char contrato[10];
     int flag;
}empleado;

void vertodos(empleado *a);
void registrar(empleado *a,int emp);
void changeinfo( empleado *a,int aux, int emp);
void ver(empleado *a,int aux2[10],int emp,int aux);
void delete(empleado *a, int aux, int emp);
void bye(char b);

int main(){
    empleado a[10];
    for(int i=0;i<10;i++){
        a[i].flag=0;
    }
        int emp;
        int aux, aux2[10];
        int can;
        char rp;
        int b=1;  
    
do{   
    
    int op;
        printf("Seleccione la accion a realizar\n");
        printf(" 1 Para registrar empleados\n");
        printf(" 2 Para modificar informacion de empleados\n");
        printf(" 3 Para visualizar empleados\n");
        printf(" 4 Para eliminar un empleado\n");
        printf(" 5 Si desea salir del programa\n");
        scanf("%d",&op);
        
    switch(op){
        
        case 1:
        registrar(a,emp);
        break;
        
        case 2:
        printf("Ya registro a los empleados?\n si(s) no(n)\n");
        scanf("%s",&rp);
        if(rp=='s'){
            aux=0;
            changeinfo(a,aux,emp);
        }else{
        printf("Primero registre los empleados\n"); 
        }
        break;
        
        case 3:
        printf("Si quiere buscar uno seleccione 1\n");
        printf("Si quiere visualizar todos seleccione otro numero\n");
        scanf ("%d",&can);
        if(can!=1){
        vertodos(a);
        }else{
            ver(a,aux2,emp,aux);
        }
        break;
        
        case 4:
        delete(a, aux, emp);
        break;
  
        case 5: 
        printf("Salio del sistema\n");
        b++;
        break;

        default:
        printf("Error\n");
        break;
    }
}while(b==1);
    return 0;
}

void registrar (empleado *a,int emp){
    
     printf("Numero de empleados que va a registrar:\n");
    scanf("%d",&emp);
        int cont=0;
        if(emp>0){
            for(int i=0;i<emp;i++){
                if(a[i].flag==0){
                printf("Nombre del empleado: ");
                scanf ("%s",&a[i].nombre);
                printf("Folio del empleado: ");
                scanf ("%d",&a[i].folio);        
                printf("Edad: ");
                scanf ("%s",&a[i].edad);
                printf("Numero de celular: ");
                scanf ("%s",&a[i].num);
                printf("Salario: "); 
                scanf ("%f",&a[i].salario);
                printf("Dia libre: ");
                scanf ("%s",&a[i].freeday);
                printf("Turno laboral: ");
                scanf ("%s",&a[i].turno);
                printf("(Temporal/Indefinido/Practicas)\nTipo de contrato: ");
                scanf ("%s",&a[i].contrato);
                printf("\n");
                a[i].flag=1;
                }else{
                    cont++;
                    emp++;
                }
            }
        }  
        if(cont==10){
            printf("no hay espacio");
        }
}
void changeinfo(  empleado *a,int aux, int emp){
    int  cont=0;
        printf("Ingrese el Folio del empleado: \n");
        scanf("%d",&aux);
        
        for(int i=0;i<10;i++){
            if(aux==a[i].folio){
                printf("Modificar\n");
                printf("Nombre del empleado: ");
                scanf ("%s",&a[i].nombre);
                printf("Folio del empleado: ");
                scanf ("%d",&a[i].folio);        
                printf("Edad: ");
                scanf ("%s",&a[i].edad);
                printf("Numero de celular: ");
                scanf ("%s",&a[i].num);
                printf("Salario: "); 
                scanf ("%f",&a[i].salario);
                printf("Dia libre: ");
                scanf ("%s",&a[i].freeday);
                printf("Turno laboral: ");
                scanf ("%s",&a[i].turno);
                printf("(Temporal/Indefinido/Practicas)\nTipo de contrato: ");
                scanf ("%s",&a[i].contrato);
                printf("\n");
                break;
            }else{
                cont++;
            }
          
                
        }   
          if(cont==10){
                printf("Usuario inexistente");
            }
        
        
}//caso 2
void ver(struct empleado *a,int aux2[10],int emp,int aux){
       int cont=0;
            printf("Ingrese el Folio del empleado: \n");
            scanf("%d",&aux);
            for(int i=0;i<10;i++){
                if(aux==a[i].folio){
                printf("Nombre:              %s\n",a[i].nombre);
                printf("Folio:               %d\n",a[i].folio);
                printf("Edad:                %s\n",a[i].edad);
                printf("Numero celular:      %s\n",a[i].num);
                printf("Salario:             %.2f\n",a[i].salario);
                printf("Dia libres:          %s\n",a[i].freeday);
                printf("Turno laboral:       %s\n",a[i].turno);
                printf("Tipo de contrato:    %s\n",a[i].contrato);
                printf("\n");
                }else{
                    cont++;
                }
            }
            if(cont==10){
                printf("inexistente\n");
            }
        
}//caso 3
void vertodos(empleado *a){
    for(int i=0; i<10;i++){
        if(a[i].flag==1){
        printf("Nombre:              %s\n",a[i].nombre);
                        printf("Folio:               %d\n",a[i].folio);
                        printf("Edad:                %s\n",a[i].edad);
                        printf("Numero celular:      %s\n",a[i].num);
                        printf("Salario:             %.2f\n",a[i].salario);
                        printf("Dia libres:          %s\n",a[i].freeday);
                        printf("Turno laboral:       %s\n",a[i].turno);
                        printf("Tipo de contrato:    %s\n",a[i].contrato);
                        printf("\n");
        
        }
    }
}
void delete( empleado *a, int aux, int emp){
        printf("Ingrese el Folio del empleado: \n");
        scanf("%d",&aux);
        a[aux-1].flag=0;
}//caso 4
void bye(char b){
        
        b='n';
}//caso 5

