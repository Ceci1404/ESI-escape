# <span style='color:blue'> **Escape-ESI** </span> 

***


## Índice 
1. [Introducción](#introducción)

2. [Documentación de usuario](#usuario)
   - [Descripción funcional](#funcional)
   - [Tecnologías](#tecnología)
   - [Instalación](#instalación)
   - [Acceso al sistema](#acceso)
   - [Manual de referencia](#referencia)
   
3. [Documentación del sistema](#sistema)
   - [Especificación del sistema](#requisitos)
   - [Módulos](#módulos)
   - [Plan de pruebas](#pruebas)  

***
Documentación creada por Cecilia Gallardo Acevedo y revisada por Susana Fernandez Sierra.
Pruebas realizadas y escritas respectivamente por cada uno.

<div id='introducción' />

## Introducción

En este documento documentaremos la información necesaria para el uso del usuario y entendimiento del codigo hecho por los alumnos, ademas de sus pruebas para la demostración del correcto funcionamiento. El programa en concreto consiste en la implementación de un juego de aventura, concretamente un escape room, en donde el jugador en base a objetos y puzles ira abriendo conexiones a las salas hasta llegar a la salida.
  

<div id='usuario' />

# Documentación de usuario
Para el uso del programa el usuario necesitara algún programa el usuario debera tener todos los ficheros .c, .h y .txt que componen el programa en su totalidad. Además de esto el usuario necesitara un software capaz de compilar y ejecutar el programa, como por ejemplo Visual Studio Code.
Trás compilar y ejecutar el código del programa el usuario ya tendrá acceso a todas las funciones para la utilización del programa que mediante elecciones pedidas por pantalla podrá acceder a todas las funciones que implementan la funcionalidad del escape room.


<div id='funcional' />

## Descripción funcional

El sistema, como proposito tiene la intención de implementar un escape room para el usuario.
El usuario mediante el programa tendrá la opción de crear o cargar una nueva partida. Si selecciona la nueva partida, se pediran los datos del jugador por pantalla y comenzara el juego. Si se escoge la opcion de cargar partida se utilizaran los datos de la partida guardada previamente del jugador y se comenzara en el juego. Una vez el jugador comience su aventura tendrá las siguientes opciones para el avance del juego:
  - 1. Describir sala
  - 2. Examinar (objetos y salidas)
  - 3. Entrar en otra sala
  - 4. Coger objeto
  - 5. Soltar objeto
  - 6. Inventario
  - 7. Usar objeto
  - 8. Resolver puzle / introducir código
  - 9. Guardar partida
  - 10. Volver

Una vez el usuario tenga intención de salir del programa podrá salirse desde el menú principal con la opción de salir.
 

<div id='tecnología' />

## Tecnología

Las tecnologías que usamos en la creación del programa se componen de:  
* [Visul::Studio::Code](https://code.visualstudio.com/): Version 1.114

* [Github](https://github.com/)


<div id='instalación' />

## Manual de instalación

Para la instalación del sistema, como anteriormente se ha mencionado, se necesitaran todos los ficheros .c, .h y punto .txt asociados al programa y un software que tenga un compilador capacitado para C y su ejecución.


<div id='acceso' />

## Acceso al sistema
Para acceder al sistema el usuario descargara el proyecto entero y abrira el programa que prefiera para su uso, trás ello solo debera ejecutar el código. Al ejecutarlo el jugador, trás que el juego le de la bienvenida, podrá escoger las opciones de juego por pantalla mediante los menús que dessee.
En el primer menu, el ususario se encontrara con las siguientes opciones:

  - 1. Nueva partida
  - 2. Cargar partifa
  - 3. Salir

El cargar o comenzar una partida llevara al mismo menu (Aunque en Nueva partida sera necesario que le usuario metas sus datos y en Cargar partida necesitara verificar el usuario), mientras que Salir terminara la ejecución del programa.
El segundo menu que nos podremos encontrar sera este:  
 - 1. Describir sala
  - 2. Examinar (objetos y salidas)
  - 3. Entrar en otra sala
  - 4. Coger objeto
  - 5. Soltar objeto
  - 6. Inventario
  - 7. Usar objeto
  - 8. Resolver puzle / introducir código
  - 9. Guardar partida
  - 10. Volver  

El cual ya vimos con anterioridad y permite al usuario el acceso a la jugabilidad y al menu anterior.



<div id='referencia' />

## Manual de referencia

Como ventaja para el usuario en el uso del programa que hemos creado, se obtendra la experiencia de un juego de aventuras tipo escape room en que el usuario podra disdrutar y obtener diversión, asi como llegar al final del juego en base a la resolución y uso de puzles por las distintas salas.



<div id='sistema' />

# Documentación del sistema
El proyecto esta programado en su totalidad en C, se compone de una totalidad de 10 modulos (Con sus respectivos .h y .c, este ultimo siempre que sean necesarios), unos .txt que permiten tener datos para el juego y un main. El funcionamiento de la aplicación se basa en el uso de seis estructuras en las cuales almacenaremos los datos (los cuales coinciden con la información de los .txt) y estas, a su vez, se almacenan en vectores que imitan los objetos de C++. La implementación de las demas funciones y su uso se ha llevado a cabo y comentado teniendo en cuenta estas estructuras y "objetos". Para el mantenimiento orientado a futuro se han llevado a cabo directamente varios comentarios en el código fuente y varias cabeceras que explican con claridad que hace cada parte del código.


<div id='requisitos' />

## Especificación del sistema
En nuestra visión personal para la distribución de los modulos hemos tenido en cuenta tanto que queremos hacer tanto con que tenemos que hacerlo. Sabemos que para la composición de este proyecto hay una gestión de ficheros, unos menús por los cuales podremos navegar en el juego, unas mecanicas que nos haran poder jugar al juego y la necesidad de trabajar con estructura (y sus correspondientes vectores dinamicos) para la facilitación del trabajo. Teniendo en cuenta esto, desglosamos el trabajo en diez modulos, el listado de todos ellos seria el siguiente:

    - 1. Partida
    - 2. Salas
    - 3. Conexión
    - 4. Jugador
    - 5. Objetos
    - 6. Puzles
    - 7. Juego
    - 8. Ficheros
    - 9. Lógica
    - 10. Menú


Esta sección debe describir el análisis y la especificación de requisitos. Cómo se descompone el problema en distintos subproblemas y los módulos asociados a cada uno de ellos, acompañados de su especificación. También debe incluir el plan de desarrollo del _software_.  


<div id='módulos' />

## Módulos
Tanto en partida, salas, conexión, jugador, objetos, puzles encontraremos las estructuras en las cuales almacenaremos las variables y datos que necesitamos durante todo el código para la creación de las funciones que los componen.En juego, siguiendo con la necesidad del uso de las etructura, al disponer de varios datos en los mismos ficheros que usaran a estas, se hace el manejo de los vectores que almacenaran a estas estructuras. En ficheros tendremos todas las funciones que hara todas las actualizaciones necesarias a estos, asi como todo el vertido de estos a las estructuras y vectores. En lógica se podrá encontrar todo lo necesario para el desarrollo de este, es decir funciones como coger objetos, soltarlos, etc. Finalmente, en menú podremos encontrar todos los menus que nos permitiran seleccionar que acción queremos hacer dentro del juego.

<div id='pruebas' />

## Plan de prueba 

### Prueba de los módulos
Debido a la gran cantidad de pruebas realizadas en todo el código, colocaremos una pequeña cantidad como ejemplos, ya que todo el trabajo ha sido probado de la misma manera, y con ello aseguramos la rigurosidad de las pruebas sin la necesidad de tener que meter tal cantidad exuberante de pruebas.
#### Prueba de caja blanca
#### Ejemplo 1 Cecilia:  
De la función  void nuevapartida(jugador *j, partida *p, int *jug) analizare esta parte de petición de nombre usuario
```C
do{
        printf("Introduce tu nombre de usuario: \n");
        scanf("%s", j[*(njug-1)].jugador);

        do{
            for (y=0; y<njug; y++){
                if(strcmp(j[*(njug-1)].jugador, j[y].jugador)==0){        //Comprobamos que el nombre de usuario no esta repetido
                    printf("El nombre de usuario ya existe, introduce otro: \n");
                    scanf("%s", j[*(njug-1)].jugador);
                }
            }
        }while(strcmp(j[*(njug-1)].jugador, j[y].jugador)==0);

        do{
            printf("El nombre de usuario introducido es: %s, ¿es correcto? Si:1 No:0 \n", j[*(njug-1)].jugador);
        scanf("%d", &Correcto);
        }while (Correcto!=1 && Correcto!=0);

    while(Correcto==0);
}
```
El fragmento de código presenta una estructura compuesta por varios bucles do while anidados, junto con un bucle for y una condición if.

El bucle for recorre el vector de jugadores desde la posición inicial hasta el número total de jugadores, permitiendo comparar el nombre introducido con los ya existentes. En caso de coincidencia, la condición if detecta que el nombre está repetido y solicita al usuario la introducción de uno nuevo.

El do while interno garantiza que el proceso se repita hasta que el nombre introducido no coincida con ninguno de los existentes en el sistema.

Posteriormente, otro do while se encarga de solicitar la confirmación del usuario, asegurando que el valor introducido sea válido (0 o 1).

Finalmente, el do while externo controla que, en caso de que el usuario no confirme el nombre (valor 0), se repita todo el proceso desde el inicio.

##### Pruebas de ruta básica
##### Ruta básica Cecilia:
![Ruta basica Cecilia](https://github.com/Ceci1404/ESI-escape/blob/main/rutabasicaCecilia.png?raw=true)
La función a la que se le hare las pruebas de caja blanca, específicamente, caja blanca 
será esta:

Pasada a pseudocódigo para su análisis la función quedaría así:
<pre>```
void: función mostrarinventario(E jugadores: j, E objetos: o, E partidas: p, E entero: jug) 
var 
inicio 
entero: x, y 
    escribir "Los objetos en tu inventario son:" (1)
    desde x ← 0 hasta j[jug].cant_obj (2) 
        desde y ← 0 hasta numobj(3) 
            si j[jug].inv[y].objinv = o[x].id_obj entonces (4) 
            escribir x, o[x].id_obj, o[x].nomb_obj, o[x].desc, o[x].localiz (5) 
            fin_si (6) 
        fin_desde (7) 
    fin_desde (8) 
fin_función
```</pre>

##### Control de flujo:
![Control de flujo Cecilia](https://github.com/Ceci1404/ESI-escape/blob/main/controlflujo.png?raw=true)
##### Complejidad ciclomática: 
V(G)=NA–NN+2=10–8+2=2+2=4  
V(G)=NNP+1=3+1=4  
V(G)=número de regiones(R1+R2+R3+R4)=4 
##### Rutas básicas linealmente independientes: 
Ruta 1: 1–2–8  
Ruta 2: 1–2–3–7–2–8  
Ruta 3: 1–2–3–4–6–3–7–2–8  
Ruta 4: 1–2–3–4–5–6–3–7–2–8  

##### Ruta básica Mario:
Para el numero de rutas, necesitamos calcular la complejidad ciclimatica. Para ello, contamos los 
nodos predicados (if, else, etc) y le sumamos uno. En este caso nos sale un total de 11 rutas

    • Ruta 1: Falla la apertura de "Jugadores.txt" (f_jug == NULL es Verdadero) y no 
    hay ninguna partida en memoria (p_activa != NULL es Falso). El programa 
    imprime el error de escritura por consola, salta el bloque de guardado de 
    jugadores y luego imprime que no hay partida.
    
    • Ruta 2: Se abre correctamente "Jugadores.txt" (f_jug == NULL es Falso), pero 
    hay 0 jugadores (total_jugadores > 0 es Falso) y no hay partida (p_activa != 
    NULL es Falso). El programa no entra al bucle principal, cierra el archivo de 
    jugadores y avisa de que no hay partida.

    • Ruta 3: Hay 1 jugador (total_jugadores > 0 es Verdadero), pero este jugador tiene 
    0 objetos en el inventario (cant_obj > 0es Falso). No hay partida (p_activa != 
    NULL es Falso). El programa escribe los datos del jugador, se salta el bucle del 
    inventario, y termina indicando que no hay partida.

    • Ruta 4: Hay 1 jugador y este tiene 1 objeto (cant_obj > 0 es Verdadero). No hay 
    partida (p_activa != NULL es Falso). El programa entra a todos los bucles de la 
    primera mitad, guarda el objeto, y finaliza sin guardar partida.

    • Ruta 5: Hay una partida en curso (p_activa != NULL es Verdadero), pero falla la 
    apertura de "Partida.txt" (f_part == NULL es Verdadero). El programa imprime el 
    error de acceso al archivo de la partida y finaliza.

    • Ruta 6: Se abre "Partida.txt" correctamente (f_part == NULL es Falso), pero la 
    partida está completamente vacía de contenido: 0 objetos, 0 conexiones y 0 
    puzles. El programa no entra a ninguno de los tres bucles y finaliza el guardado.

    • Ruta 7 (Forzar Objetos): La partida tiene 1 objeto (num_objetospar > 0 es 
    Verdadero), pero 0 conexiones y 0 puzles. El programa entra al primer bucle, 
    escribe el objeto y se salta el resto.

    • Ruta 8 (Forzar Conexión - Activa): La partida tiene 0 objetos, 0 puzles, pero tiene 1 
    conexión y su estado es activa (activa == TRUE es Verdadero). El programa 
    evalúa el if interno de conexiones y asigna el texto "Activa".

    • Ruta 9 (Forzar Conexión - Bloqueada): Igual que la Ruta 8, pero la condición 
    cambia: el estado de la conexión no es activa (activa == TRUE es Falso). El 
    programa entra al else interno y asigna el texto "Bloqueada".

    • Ruta 10 (Forzar Puzle - Resuelto): La partida tiene 0 objetos, 0 conexiones, pero 
    tiene 1 puzle y está resuelto (resuelto == TRUE es Verdadero). El programa evalúa 
    el if interno de puzles y asigna el texto "Resuelto".

    • Ruta 11 (Forzar Puzle - Pendiente): Igual que la Ruta 10, pero la condición cambia: 
    el puzle no está resuelto (resuelto == TRUE es Falso). El programa entra al else 
    interno de puzles y asigna el texto “Pendiente".

##### Ruta básica Francisco:
Esta prueba garantiza que se exploran los posibles caminos de ejecución de la implementación.
Siguiendo los pasos definidos para la prueba de ruta básica:
Pasos 1 y 2: Grafo de Flujo (CFG) y Complejidad Ciclomática

La función menu_principal() está compuesta por un bucle principal do-while (1 decisión de salida),
una estructura condicional if-else para validar rangos (1 decisión) y una estructura switch con 3
opciones operativas (equivale a 2 decisiones lógicas subyacentes).

    • Fórmula aplicada: V(G) = Nodos Predicado + 1 = 4 + 1 = 5.
    • La complejidad ciclomática calculada es 5.

Paso 3: Conjunto básico de rutas linealmente independientes
Se han identificado las siguientes rutas principales:

    • Ruta 1 (Validación fallida): Entra al bucle -> Falla la condición del if -> Muestra error ->
    Repite el bucle.
    • Ruta 2 (Caso 1): Entra al bucle -> Pasa el if -> Ejecuta Nueva Partida -> Repite el bucle.
    • Ruta 3 (Caso 2): Entra al bucle -> Pasa el if -> Ejecuta Cargar Partida -> Repite el bucle.
    • Ruta 4 (Caso 3 / Salida): Entra al bucle -> Pasa el if -> Ejecuta Salir -> Termina la
    condición del while y finaliza.

Paso 4: Preparación de Casos de Prueba (Prueba de Bucles) Dado que la función se basa en un
bucle interactivo, se aplican criterios de prueba de bucles para forzar distintas iteraciones:

    • Prueba de Ruta 1:
        • Entradas de teclado: Primero se teclea 4 y, en la siguiente iteración, se teclea 3.
        • Descripción: Fuerza el fallo en el if por un valor no válido (OPCION
        INCORRECTA) y luego sale del programa de forma segura.
        • Cobertura de Bucle: Prueba de dos iteraciones.
    • Prueba de Ruta 2:
        • Entradas de teclado: Primero se teclea 1 y, al volver al menú, se teclea 3.
        • Descripción: Fuerza la entrada al caso de Nueva Partida y posteriormente evalúa la
        salida.
        • Cobertura de Bucle: Prueba de dos iteraciones.
        • Prueba de Ruta 3:
        • Entradas de teclado: Primero se teclea 2 y, al volver al menú, se teclea 3.
        • Descripción: Fuerza la entrada al caso de Cargar Partida y posteriormente evalúa la
        salida.
        • Cobertura de Bucle: Prueba de dos iteraciones.
    • Prueba de Ruta 4:
        • Entrada de teclado: Se teclea directamente 3.
        • Descripción: Ejecuta la opción de salida en el primer intento.
        • Cobertura de Bucle: Prueba de una única iteración.

##### Ruta básica Susana:
![Ruta basica Susana 1](https://github.com/Ceci1404/ESI-escape/blob/main/RutabasicaSusana1.png?raw=true)
![Ruta basica Susana 2](https://github.com/Ceci1404/ESI-escape/blob/main/RutabasicaSusana2.png?raw=true)

#### Prueba de caja negra
##### Prueba de caja negra Cecilia:
![Caja negra Cecilia](https://github.com/Ceci1404/ESI-escape/blob/main/cajanegraCecilia.png?raw=true)

##### Prueba de caja negra Mario:
Caso de Prueba 1: Límite de rango inferior (No válido). Se evaluará el comportamiento del 
sistema al recibir un valor sin sentido lógico para la cantidad de jugadores. Probamos el 
valor total_jugadores = -1.  

    • Resultado esperado: El programa no debe iterar sobre la lista de jugadores ni 
    escribir basura en el archivo de texto. No debe producirse ningún cierre 
    inesperado (cuelgue) del programa.

![Caja negra Mario](https://github.com/Ceci1404/ESI-escape/blob/main/cajanegranmario.jpeg?raw=true)

Caso de Prueba 2: Límite de rango válido (Mínimo). Se comprobará la respuesta del 
sistema al recibir total_jugadores = 0.  
    
    • Resultado esperado: El archivo "Jugadores.txt" debe generarse correctamente, 
    pero debe quedar completamente en blanco.  

Caso de Prueba 3: Se verificará el correcto procesamiento de los estados booleanos 
internos de la partida. Se enviará una estructura p_activa válida donde al menos una 
conexión tenga su estado activa = TRUE y un puzle tenga resuelto = TRUE.

    • Resultado esperado: Al abrir el archivo generado "Partida.txt", debe aparecer 
    explícitamente escrita la palabra "Activa" asociada a la conexión, y la palabra 
    "Resuelto" asociada al puzle.

Caso de Prueba 4: Fallo de entorno (Sistema de Archivos). Se probará la robustez del 
código frente a problemas externos no relacionados con la memoria del programa. Se 
ejecutará la función en un directorio de sistema donde se hayan retirado los permisos de 
escritura.  

    • Resultado esperado: Las funciones fopen devolverán NULL. El programa debe 
    capturar este error, mostrar los mensajes de error y finalizar la función de forma 
    limpia.

##### Prueba de caja negra Francisco:
Esta técnica se utiliza para determinar si la función realiza la tarea para la que ha sido creada,
analizando sus entradas y comprobando que las salidas son las esperadas.
Para la función menu_principal(), el dato de entrada esperado es un valor numérico entre 1 y 3. Se
han diseñado los casos de prueba evaluando los valores extremos y los valores justo por encima y
por debajo de dichos rangos:

    • Objetivo: Verificar que el menú principal reacciona y navega correctamente según la opción
    introducida por teclado.

    • CP_01 (Límite inferior válido): Dato de Entrada: 1. Resultado Esperado: El programa
    ejecuta el caso 1 y llama a la función crear_nueva_partida(). Resultado Obtenido:

![Caja negra Francisco](https://github.com/Ceci1404/ESI-escape/blob/main/cajanegrafrancisco.png?raw=true)

• CP_02 (Límite superior válido): Dato de Entrada: 3. Resultado Esperado: El programa
muestra el mensaje de despedida y finaliza la ejecución.

• CP_03 (Valor medio válido): Dato de Entrada: 2. Resultado Esperado: El programa ejecuta
el caso 2 y llama a la función cargar_partida_existente().

• CP_04 (Justo por debajo del límite - No válido): Dato de Entrada: 0. Resultado Esperado:
El programa detecta el error, muestra "OPCION INCORRECTA" y vuelve a solicitar
entrada.

• CP_05 (Justo por encima del límite - No válido): Dato de Entrada: 4. Resultado Esperado:
El programa detecta el error, muestra "OPCION INCORRECTA" y vuelve a solicitar
entrada.

##### Prueba de caja negra Susana:
Función Crearsala:
![Prueba caja negra Susana](https://github.com/Ceci1404/ESI-escape/blob/main/CajanegraSusana.jpeg?raw=true)

### Prueba de integración
Como ya se dijo en las pruebas anteriores y por las mismas razones pondremos unos cuantos ejemplos de todos los codigos que componen el trabajo.

#### Prueba de caja blanca
La integración de todos los modulos (aunque se han ido haciendo falta entre si para su uso entre funciones) se ha hecho finalmente en el main.c, donde se han llamado a las funciones y declarado localmente las variables que utilizaremos para la llamada de esta. Como no hacemos uso de bucles y anteriormente ya nos hemos asegurado de la rigurosidad y funcionamiento de los modulos por separado sabemos que el código usado en la integración efectivamente es usable.
#### Prueba de caja negra
![caja negra integracion](https://github.com/Ceci1404/ESI-escape/blob/main/pruebadeintegracion.jpeg?raw=true)


### Plan de pruebas de aceptación
Para la aceptación del plan de pruebas de aceptación y que el usuario final de la aprobación a este nuestro trabajo, el sistema deberia ser capaz de cumplir con el guión de trabajo propuesto (el cual cumple) y no presentar errores fatales, los cueles hemos solventado y demostrado en las anteriores pruebas, con lo cual es posible llegar a la aceptación de este sistema.


<div id='sistema' />

# Documentación del código fuente
Durante la creación de este trabajo hemos colacado varios comentarios en el codigo fuente con la intención del fácil entendimiento de todo el código. Ya que son muchas lineas de código las que comprenden este trabajo, colocaremos algunos ejemplos para asegurar la rigurosidad en la documentación.

```C
//Cabecera: void resolver(puzles *puz, partida p, int *numpuz, int *par)
//Precondición: La función recive la estructura de puzles y partida inicializada
//Postcondición: El jugador podra resolver puzles
void resolver(puzle *puz, partidas p, int *numpuz, int *par){
    char c[5];
    int x,y,resolver;
    for(x=0; x<=numpuz; x++){
        if(strcmp(p[*par].sala_actual, puz[x].id_sala)==0){           //Comprobamos que el puzle este en la sala actual
            printf("El puzle es de tipo %s\nDescripcion: %s\n", puz[x].tipo, puz[x].desc);
            for(y=0; y<p.num_puzles; y++){
                if(p.puzles_estado[y].resuelto==true){          //Nos dice si el puzle esta resuelto o no
                    printf("El puzle %s ya ha sido resuelto.\n", puz[x].nomb_puz);
                }
                else{
                    do{
                        printf("Puedes resolver el puzle %s, ¿quieres resolverlo? Si:1 No:0 \n", puz[x].nomb_puz);
                        scanf("%d", &resolver);
                    }while(resolver!=1 && resolver!=0);
                    if(resolver==1){
                        puz[x].sol;                             //Muestra la solución del puzle
                    }
                }
            }
        }
    }
    
}
```