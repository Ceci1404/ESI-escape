#include"menu.h.h"
void menu(int x);
void partida(int p);

void menu(int x){
do{
    printf("        --ESI SCAPE--     \n");
    printf("        ----------\n");
    printf("1. Nueva partida.\n");
    printf("2. Cargar partida.\n"); 
    printf("3. Salir.\n");
    scanf("%d",&x);
if(x<1 || x>3){
    printf("OPCION INCORRECTA,PORFAVOR ELIJA CORRECTAMENTE.\n");
}
} while(x<1 || x>3);
switch(x){
    case 1:

        break;
    
    case 2:

        break;
    
        case 3:

        break;
    

} 
}

void partida(int p){
do{
    printf("   --Sala: %s--\n");//HABRIA QUE ACCEDER A LA SALA ACTUAL DEL JUGADOR
    putchar("\n");
    
    printf("1. Describir sala.\n");
    printf("2. Examinar (objetos y salidas).\n"); 
    printf("3. Entrar en otra sala.\n");
    printf("4. Coger objeto.\n");
    printf("5. Soltar objeto.\n"); 
    printf("6. Inventario.\n");
    printf("7. Usar objeto.\n");
    printf("8. Resolver puzle / introducir código.\n"); 
    printf("9. Guardar partida.\n");
    printf("10. Volver.\n");

        scanf("%d",&p);
if(p<1 || p>10){
    printf("OPCION INCORRECTA,PORFAVOR ELIJA CORRECTAMENTE.\n");
}
} while(p<1 || p>10);

switch(p){
    case 1:

        break;
    
    case 2:

        break;
    
    case 3:

        break;
        
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
        
    case 7:

        break;
    case 8:

        break;
    case 9:

        break;
    case 10:

        break;
    

} 
}


