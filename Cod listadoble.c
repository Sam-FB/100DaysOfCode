#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int elem;
    int folio;
    char nombre[20];
    char telefono[12];
    struct element *next;
    struct element *prev;
}element;

element *Create(element **tail);
int *Ingresa(int num,element *H,int cont);
int Elimina(int buscar,element* H);
void Imprimir(element *H,element *T);
void Inverso(element *T,element *H);


int main()
{
    element* Header=0;
    element* Tail=0;
    Header=Create(&Tail);
    int salir,op,num,save;
    int cont=0;
    do{
        printf("\nMenu de Opciones:\n");
        printf("1. Añadir elementos\n");
        printf("2. Visualizar la Lista \n");
        printf("3. Invertir lista\n");
        printf("4. Eliminar elemento\n");
        printf("5. salir\n");
        printf("Opcion: ");       
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                {
                    Ingresa(num,Header,cont);
                    cont++;
                }
                break;
            case 2:
                {
                    printf("\nVisualizar Lista\n");
                    Imprimir(Header,Tail);
                }
                break;
            case 3:
                {
                    printf("\nVisualizar Lista invertida\n");
                    Inverso(Header,Tail);
                }
                break;
            case 4: 
                {
                    printf("\nIngrese el folio del elemento a eliminar\n");
                    scanf("%d",&num);
                    Elimina(num,Header);
                    printf("\nSe elimino el elemento\n");
                }
                break;
                
            case 5:
                exit(1);
                break;
            default:
                {
                printf("\nOpcion no valida\n");
                }
                break;
        }
    }
    while(salir!=1);
    return 0;
}

element *Create(element **tail){
    element *H=0;
    element *T=0;
    if((H=malloc(sizeof(element)))==0){
        return 0;
    }
    if((T=malloc(sizeof(element)))==0){
        free(H);
        return 0;
    }
    
    H->next=T;
    H->prev=H;
    T->prev=H;
    T->next=T;
    *(tail)=T;
    return H;
}

int *Ingresa(int num,element *H,int cont){
    int iod;
    if(H==0){
        return 0;
    }
    
    element *aux=H->next;
    element *new=0;

    if((new=malloc(sizeof(element)))==0){
        return 0;
    }
    
      printf("Ingresar elemento: \n");
      printf("Seleccione 1 para Ingresar por derecha\n");
      printf("Seleccione 2 para Ingresar por izquierda\n");
      scanf("%d",&iod);
    
      new->folio=cont;
      printf("Nombre: ");
      scanf("%s",&new->nombre);
      printf("Teléfono: ");
      scanf("%s",&new->telefono);
      printf( "\n Nombre: %s\n Telefono: %s\n Folio: %d\n",new->nombre,new->telefono,new->folio);
     
   if(iod==1){
        while((aux!=aux->next)&&(new->folio!=aux->folio)){
        aux=aux->next; 
    }
    
     new->next=aux;
     new->prev=aux->prev;
     aux->prev->next=new;
     aux->prev=new; 
    
    return 1;
      }
    
    if(iod==2){
        while((aux!=aux->prev)&&(new->folio!=aux->folio)){
        aux=aux->prev;
    }
     new->prev=aux;
     new->next=aux->next;
     aux->next->prev=new;
     aux->next=new;
    
        return 1;
    }
    else{
     printf("Eleccion invalida");
    }

    
}

int Elimina(int buscar,element* H){
    if(H == 0){
        return 0;
    }
    if(H->next == H->next->next){
        return 0;
    }
    element *aux = H->next;
    while((aux!=aux->next)&&(buscar!=aux->folio))
    {
        aux=aux->next;
    }
    
    if( buscar==aux->folio){
        aux->next->prev=aux->prev;
        aux->prev->next=aux->next;
        aux->next=0;
        aux->prev=0;
        free(aux);
        return 1;  
    }
    else{
        return 0;
    }
}

void Imprimir(element *H,element *T){
    element *apn=H->next;
    
    while(apn!=T){
        printf( "\n Nombre: %s\n Telefono: %s\n Folio: %d\n",apn->nombre,apn->telefono,apn->folio);
        apn=apn->next;
    }
}

void Inverso(element *T,element *H){
    element *apn=H->prev;
    
    while(apn!=T){
        printf( "\n Nombre: %s\n Telefono: %s\n Folio: %d\n",apn->nombre,apn->telefono,apn->folio);
        apn=apn->prev;
    }
}

