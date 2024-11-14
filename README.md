# Disk_Scheduling
### Algoritmos C-SCAN y SCAN de la planificación del disco.
Integrantes: Juan Pablo Ovalles, Juan Pablo Ospina y Sebastian Enriquez.

A continuación se muestra las diversas consideraciones que se tienen que tomar en cuenta para ejecutar el código, consideraciones como el manejo de la entrada y el entendimiento de la salida.
CONSIDERACIONES:
Tanto el algoritmo SCAN como el C-SCAN fueron pensados solo iniciando de subida como se ha acordado para la mayoría de ejercicios en clase. Además, la primera petición enviada se asume como la posición inicial del brazo.

ENTRADA:
Se espera que en la primera línea de entrada se ingresen separados por espacios y en el siguiente orden: el algoritmo en mayúsculas (SCAN O CSCAN), la cantidad de solicitudes, la cantidad de pistas y el tiempo por seek. Ejemplo: SCAN 9 250 3.
Luego de esto se pedirán tantas líneas como cantidad de solicitudes y se deben ingresar una por una de la siguiente forma:
120
45
133
86
200
42
176
95
140
Por lo tanto la entrada completa se vería así:
SCAN 9 250 3
120
45
133
86
200
42
176
95
140

SALIDA: 
Se imprime los datos de relevancia para el algoritmo, como el recorrido que siguió el brazo, la distancia total recorrida y el tiempo en el que se hizo el recorrido. Por ejemplo,
para la entrada la siguiente entrada:
CSCAN 8 90 3
53
12
34
52
14
25
68
39
Se tiene como salida:
Para las solicitudes 53 12 34 52 14 25 68 39
El recorrido CSCAN es
53 -> 68 -> 90 -> 0 -> 12 -> 14 -> 25 -> 34 -> 39 -> 52
Con distancia total de 179
En un tiempo de 537 ms

Luego, otro ejemplo para el algoritmo SCAN se tiene como entrada:
SCAN 9 250 3
120
45
133
86
200
42
176
95
140
Se tendría como salida:
Para las solicitudes 120 45 133 86 200 42 176 95 140
El recorrido SCAN es
120 -> 133 -> 140 -> 176 -> 200 -> 250 -> 95 -> 86 -> 45 -> 42 -> 0
Con distancia total de 380
En un tiempo de 1140 ms


