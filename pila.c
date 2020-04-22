/*PILA*/
#include <stdio.h>
#include <stdlib.h>

typedef struct element{
     int temp;
     int hora;
     float humedad;
    struct element *siguiente;
}element;
typedef struct element Nodo;

Nodo *primero= NULL;
Nodo *actual= NULL;

int *Insertar(int cont);
void Imprime();
int *Elimina();
int Busca_elemento(int cont);

int main(){
        int salir,op;
        char in;
        int cont=1;
   do{   
      printf("\nMenu de Opciones:\n");  
      printf("1. Insertar elemento\n");
      printf("2. Visualizar\n");
      printf("3. Eliminar elemento\n");
      printf("4. Vaciar Pila\n");
      printf("5. salir\n");
      printf("Opcion: ");       
      scanf("%d",&op);
      switch(op){
        case 1:
        Insertar(cont);
        cont++;
        break;
        
        case 2:{
         printf("\nPara visualizar un elemento seleccione 'a'\n");
         printf("Seleccione otra letra para visualizar toda la Pila\n");
         printf("Opcion: ");
         scanf("%s",&in);
            if(in=='a'){
             Busca_elemento(cont);
            }
            else{
             Imprime();
            }
        }
        break;
        
        case 3:
        Elimina();
        cont--;
        break;
        
        case 4:
        Delete();
        break;
        
        case 5:
        exit(1);
        break;
          
      }
      
    }while(salir!=1);
  return 0;
}

int *Insertar(int cont){
    
    Nodo *nuevo = (struct element*)malloc(sizeof(struct element));

    if(NULL == nuevo){
        printf("\n Error en creacion de nodo \n");
    }
    
    printf("Ingrese la temperatura: ");
    scanf("%d",&nuevo->temp);
    printf("Ingrese la humedad: ");
    scanf("%f",&nuevo->humedad);
    
    nuevo->hora =cont++;

    nuevo->siguiente = primero;
    primero = nuevo;
    
    printf("\n%d°C\n",nuevo->temp);
    printf("%.2f%\n",nuevo->humedad);
    printf("%d:00\n",nuevo->hora);
    
        return 1;
} 

void Imprime(){
 
    if(NULL == primero){
        printf("Pila vacia\n");
    }
    else{
        Nodo *nodo = primero;
        printf("\n -------Inicio de la Pila------- \n");
        
        while(nodo != NULL)
        {
            printf("\n%d°C\n",nodo->temp);
            printf("%.2f%\n",nodo->humedad);
            printf("%d:00\n",nodo->hora);
            nodo = nodo->siguiente;
            printf("\n -------------- \n");
        }
    }
}

int Busca_elemento(int cont){
    int num;
    printf("\nIngrese la Hora del elemento: \n");
    scanf("%d",&num);
    
    
    if(NULL == primero){
        printf("Pila vacia\n");
    }
    if(num>cont){
        printf("Elemento inexistente\n");
    }
    else{
     Nodo *busca=primero;
        while(busca->hora!=num){ 
         busca= busca->siguiente;
         
        }
      printf("\n%d\n°C",busca->temp);
      printf("%.2f%\n",busca->humedad);
      printf("%d:00\n",busca->hora);
    }
    
    
}

int *Elimina(){
    
    if(NULL == primero){
        printf("La pila esta vacia\n");
    }
    else{
        printf("\n-Elemento Removido-\n");
        Nodo *nodo = primero;
         printf("\n%d°C\n",nodo->temp);
         printf("%.2f%\n",nodo->humedad);
         printf("%d:00\n",nodo->hora);
        primero=nodo->siguiente;
        free(nodo);
    }
    return 1;
}

int Delete(){
 Nodo *nodo = primero;
    while(nodo != NULL){ 
      primero=nodo->siguiente;
      free(nodo);
      nodo=nodo->siguiente;
    }
 printf("Pila esta vacia\n");
}
