# P3-SO

1.1 Versión paralela con hilos Posix
Utilizando la librería Posix desarrolla una versión multihilos que haga el mismo cálculo de la serie armónica de manera que ahora se utilicen todos los núcleos del
procesador y se obtenga el mismo resultado en menos tiempo.
Realiza pruebas con tu programa y toma tiempos que se lleva la ejecución, compara con el tiempo obtenido en la versión serial.

1.2 Versión paralela con hilos implementados clonando procesos
Utilizando la llamada al sistema clone() que te permite clonar procesos, desarrolla una versión paralela que haga el mismo cálculo de la serie armónica de manera que ahora se utilicen todos los núcleos del procesador y se obtenga el
mismo resultado en menos tiempo.
La llamada al sistema clone() te permite clonar procesos indicando que recursosse comparten y que recursos no se comparten. Esta llamada se utiliza paraimplementar hilos a partir de la clonación de procesos, y esto se puede lograr conprocesos donde se comparte casi todo el espacio de direcciones.
Realiza pruebas con tu programa y toma tiempos que se lleva la ejecución,compara con el tiempo obtenido en la versión serial.

1.3 Versión paralela con procesos
Utilizando la llamada al sistema fork() que te permite duplicar la imagen de un proceso, desarrolla una versión paralela que haga el mismo cálculo la serie armónica de manera que ahora se utilicen todos los núcleos del procesador y se obtenga el mismo resultado en menos tiempo.
Para esta versión donde utilizas fork(), recuerda que no se comparten recursos como la memoria, por lo que será necesario que utilices un mecanismo de comunicación entre procesos. Es recomendable usar segmentos de memoria compartida, la cual la puedes solicitar al sistema con la llamada al sistema shmget() y conectar con la llamada al sistema shmat().
Realiza pruebas con tu programa y toma tiempos que se lleva la ejecución, compara con el tiempo obtenido en la versión serial.
