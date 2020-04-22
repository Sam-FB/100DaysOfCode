/*COLA*/
#include <stdio.h>
#include <stdlib.h>

typedef struct persona{
     char nombre[20];
     char asunto[10];
     int codigo;
    struct persona *siguiente;
}persona;

typedef struct persona Nodo;
Nodo *final= NULL;
Nodo *inicio= NULL;

void menu();
int *Insertar();
void Imprime();
int *Elimina();
int Delete();
int Busca_elemento();
int cont=0,cod=0,elim=0;
int main(){
        int salir,op;
        char in;

   do{   
      menu();
      scanf("%d",&op);
      
      switch(op){
        case 1:
        Insertar();
        break;
        
        case 2:
  
         printf("\nPara visualizar un elemento seleccione 'a'\n");
         printf("Seleccione otra letra para visualizar toda la Cola\n");
         printf("Opcion: ");
         scanf("%s",&in);
            if(in=='a'){
             Busca_elemento(cont);
            }
            else{
             Imprime();
            }
        break;
        
        case 3:
        Elimina();
        break;
        
        case 4:
        Delete();
        break;
        
        case 5:
        exit(1);
        break;
        
        default:
        printf("\nOpcion no valida\n");
        break;
      
      }
      
    }while(salir!=1);
  return 0;
}

void menu(){
      printf("\n______Menu de Opciones______\n");  
      printf("1. Insertar elemento\n");
      printf("2. Visualizar\n");
      printf("3. Eliminar elemento\n");
      printf("4. Vaciar Cola\n");
      printf("5. salir\n");
      printf("Opcion: ");    
}
int *Insertar(){
     Nodo *nodo=inicio;
     Nodo *nuevo = (struct persona*)malloc(sizeof(struct persona));
     if(NULL == nuevo){
        printf("\n Error en creacion de nodo \n");
     }
      if(inicio == NULL){
     printf("\nNombre: ");
     scanf("%s",&nuevo->nombre);
     printf("Asunto: ");
     scanf("%s",&nuevo->asunto);
     nuevo->codigo=cod;
     printf("Codigo de cliente: ");
     printf("%d",nuevo->codigo+1);
     
     nuevo->siguiente = NULL;
     inicio=nuevo; 
     final = nuevo;
     cont++;
      }
      else{
        printf("\nNombre: ");
        scanf("%s",&nuevo->nombre);
        printf("Asunto: ");
        scanf("%s",&nuevo->asunto);
        cod++;
        nuevo->codigo=cod;
        printf("Codigo de cliente: ");
        printf("%d",nuevo->codigo+1);
            /*if(cod==cont){ 
             printf("\nOpcion no valida");
             printf("\nCodigo de cliente repetido\n");
             nodo=nodo->siguiente;
            }
            else{*/
             nuevo->siguiente = NULL;
             final->siguiente= nuevo;
             final=nuevo;
             cont++;
      }
 return 1;
} 
void Imprime(){
 
    if(NULL == final){
        printf("\n____Cola vacia____\n");
    }
    else{
        Nodo *nodo = inicio;
        printf("\n ______Cola______\n");
        
        while(nodo != NULL)
        {
         printf( "\n Nombre: %s\n Asunto: %s\n Codigo: %d\n",nodo->nombre,nodo->asunto,nodo->codigo+1);
         printf("\n ________________ \n");
          nodo = nodo->siguiente;
        }
    }
}

int Busca_elemento(){
    Nodo *nodo=inicio;
    int busca;
    printf("\nIngrese el codigo de la persona: ");
    scanf("%d",&busca);
    busca=elim+(busca-1);
    if(NULL == inicio){
        printf("Cola vacia\n");
    }
    if(busca<=cont){
    for(int i=0;i<cod;i++){
     if(nodo->codigo!=busca){nodo=nodo->siguiente;}
    }
    if(nodo->codigo==busca){
     printf( "\n Nombre: %s\n Asunto: %s\n Codigo: %d\n",nodo->nombre,nodo->asunto,nodo->codigo+1);
    }else{printf("El codigo no existe\n");}
    }
    printf("El codigo no existe\n");
    
}

int *Elimina(){
    Nodo *nodo=inicio;
    if(NULL==nodo){
        printf("\n___Cola vacia___\n");
    }
    else{
        inicio = nodo->siguiente;
       printf("\n__Elemento Removido__\n");
       printf( "\n Nombre: %s\n Asunto: %s\n Codigo: %d\n",nodo->nombre,nodo->asunto,nodo->codigo+1);
       free(nodo);
    }
    if(inicio==NULL){ final = NULL;}
    return 1;
}

int Delete(){
 Nodo *nodo=inicio;
    while(inicio != NULL){ 
     inicio=nodo->siguiente;
     free(nodo); 
     nodo=inicio;
     
    }if(inicio==NULL){ 
        final=NULL;
    printf("Cola vacia\n");
    }

}


