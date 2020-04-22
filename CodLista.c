#include <stdio.h>
#include <stdlib.h>

 struct agenda {
        char nombre[20];
        char telefono[12];
        struct agenda *siguiente;
        int folio;
        };

 struct agenda *primero, *ultimo;
 
 void anadir_elemento(int conta);
 void mostrar_lista();
 void buscar();
 void eliminar();

 int main() {
     int opcion;
     int conta=0;
     primero = (struct agenda *) NULL;
     ultimo = (struct agenda *) NULL;
     do {
      printf("\n\nMenú:\n=====\n\n");
      printf("1.- Añadir elementos\n");
      printf("2.- Borrar elemento\n");
      printf("3.- Mostrar lista\n");
      printf("4.- Buscar elemento\n\n");
      printf("5.- Salir\n\n");
      printf("Escoge una opción: ");fflush(stdout);
        scanf("%d",&opcion);
             switch ( opcion ) {
                case 1: anadir_elemento(conta);
                        conta++;
                       break;
                case 2: eliminar();
                        break;
                case 3: mostrar_lista(primero);
                        break;
                case 4: buscar();
                        break;
                    
                case 5:exit( 1 );
                default: printf( "Opción no válida\n" );
                         break;
             }
     } while (opcion!=4);
 }
 
 void anadir_elemento(int conta) {
      struct agenda *nuevo;
      nuevo = (struct agenda *) malloc (sizeof(struct agenda));
      if (nuevo==NULL) printf( "No hay memoria disponible!\n");

      nuevo->folio=conta;
      printf("\nNuevo elemento:\n");
      printf("Nombre: ");
      scanf("%s",&nuevo->nombre);
      printf("Teléfono: ");
      scanf("%s",&nuevo->telefono);
      printf("Folio: %d ",nuevo->folio);

      nuevo->siguiente = NULL;
      
      if (primero==NULL) {
         printf( "\nPrimer elemento\n");
         primero = nuevo;
         ultimo = nuevo;
         }
      else {
          
           ultimo->siguiente = nuevo;
           ultimo = nuevo;
      } 
 }

 void mostrar_lista() {
      struct agenda *auxiliar;
      int i;

      i=0;
      auxiliar = primero;
      printf("\nMostrando la lista completa:\n");
      while (auxiliar!=NULL) {
            printf( "Nombre: %s\n Telefono: %s\n Folio: %d\n",auxiliar->nombre,auxiliar->telefono,auxiliar->folio);
            auxiliar = auxiliar->siguiente;
            i++;
      }
      if (i==0) printf( "\nLa lista está vacía!!\n" );
 }
 void buscar(){
    struct agenda *auxiliar;
    int i, a;
    scanf ("%d",&a);
      i=0;
      auxiliar = primero;
      while (auxiliar->folio!=a&&auxiliar!=NULL) {
          auxiliar=auxiliar->siguiente;
      }
      if (auxiliar->folio==a)
      {
          printf( "Nombre: %s, Telefono: %s\nFolio: %d",auxiliar->nombre,auxiliar->telefono,auxiliar->folio);
      }
      else{
           printf( "No existe");
           }
 }
 
 void eliminar(){
    struct agenda *auxi;
    struct agenda *elimina;
    int i, a,s;
    printf( "Ingrese el folio: ");
    scanf ("%d",&a);
    i=0;
      auxi=primero;
      
      if(a!=0){
          while (auxi->folio!=a-1&&auxi!=NULL) {
              auxi=auxi->siguiente;
          }
          if(auxi->folio==a-1){
            elimina=auxi->siguiente;
            auxi->siguiente=auxi->siguiente->siguiente;
            elimina->siguiente=auxi->siguiente;
            free(elimina);
            
            printf( "Elemento eliminado\n");
          }
      }if(auxi->folio==0){
          
        primero=auxi->siguiente;
        auxi->siguiente=auxi;
        free(auxi);
      }
      
      else{
           printf( "No existe\n");
           }
           
 }
 
