//Cabecera: void nuevapartida()
//Precondición: Las estructuras de objetos, jugadores, salas, conexiones y puzles deben estar inicializadas
//Postcondición: Se añadira un nuevo jugador en el vector de jugadores y se inicializara la partida con los datos del nuevo jugador
void nuevapartida(jugador *j, partida *p, int *jug){
    int Correcto=0, x, y;

    realloc(j, (njug+1)*sizeof(jugador));
    *jug=njug;

    /*Comienzo con la estructura del jugador*/
    //Creación del identificador del jugador
    if(jug<10){
        sprintf(j[*njug].id_jugador, "%02d", *jug);         //Si el numero es menor a 10 se le añade delante un 0
    }
    else{
        sprintf(j[*njug].id_jugador, "%d", *jug);
    }
    //Petición del nombre Completo del jugador
    do{
        printf("Introduce tu nombre completo: \n");
        scanf("%s", j[*njug].nom_jugador);
        printf("El nombre introducido es: %s, ¿es correcto? Si:1 No:0 \n", j[*jug].nom_jugador);
        scanf("%d", &Correcto);
    }while(Correcto==0);

    Correcto=0;

    //Nombre de usuario
    do{
        printf("Introduce tu nombre de usuario: \n");
        scanf("%s", j[*njug].jugador);
        
        do{
            for (y=0; y<njug; y++){
                if(strcmp(j[*njug].jugador, j[y].jugador)==0){        //Comprobamos que el nombre de usuario no esta repetido
                    printf("El nombre de usuario ya existe, introduce otro: \n");
                    scanf("%s", j[*njug].jugador);
                }
            }
        }while(strcmp(j[*njug].jugador, j[y].jugador)==0);

        printf("El nombre de usuario introducido es: %s, ¿es correcto? Si:1 No:0 \n", j[*njug].jugador);
        scanf("%d", &Correcto);
    while(Correcto==0);

    Correcto=0;

    //Contraseña
    do{
        printf("Introduce tu contraseña: \n");
        scanf("%s", j[*njug].password);
        
        printf("La contraseña introducida es: %s, ¿es correcta? Si:1 No:0 \n", j[*njug].password);
        scanf("%d", &Correcto);
    }while(Correcto==0);


    //El inventario se inicializa vacio y el jugador empieza en la sala de inicio
    int cant_obj=0;
    int tamainv=10;
    malloc(j[*njug].inventario, tamainv*sizeof(inventario));


    /*Inicialización de la estructura de la partida*/
    //Jugador actual
    strcpy(j[*njug].id_jugador, p.id_jugador);

    //Sala actual
    for(x=0; x<numsal; x++){
        if(strcmp(s[x].tipo, INICIO)==0){
            strcpy(p.sala_actual, s[x].id_sala);
        }
    }

    //La partida empieza sin conexiones desbloqueadas ni puzles resueltos
    p.num_conexunlocked=0;
    malloc(p.conex_desbloqueadas, p.num_conexunlocked*sizeof(conexunlocked));

    p.num_puzles=0;
    malloc(p.puzles_estado, p.num_puzles*sizeof(puzleestado));

}