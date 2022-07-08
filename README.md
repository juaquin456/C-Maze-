<p align="center">
<img src="https://user-images.githubusercontent.com/102132128/170156239-a93ec1ab-f4a3-4958-8814-7b9c295605f6.png" alt="drawing" width="500"/>
</p>

## Resumen del juego:
CMAZE++ es un juego en el que tendrás que demostrar tu habilidad para resolver laberintos y encontrar caminos cortos para llegar a tus objetivos. El jugador empieza en una posición del laberinto y se distribuirán aleatoriamente ítems de su mismo color en el laberinto. El jugador deberá recoger todos sus ítems en el menor tiempo posible, ya que también habrá otro jugador intentándolo. El principal modo del juego consiste en que el jugador oponente estará controlado por la computadora y mediante un algoritmo encontrará el camino más corto para recoger todos sus ítems más rápido que el oponente. El primer jugador en conseguir todos sus ítems ganará el juego y será añadido a la tabla de ranking general.

## Resumen del Programa:
> El programa esta disenando con algunos patrones de diseno:

1. Singleton:
   1. Mouse
   2. Display
   3. Keyboard
2. Factory:
   1. Implementación del patron factory en Interface con componentes por el motivo de que la clase Interface necesita construir los componentes, aunque no sepa cuales son, basta con la versión abstracta de esta.
3. Command:
   1. Implementación del patron de comportamiento command en algunos componentes como el boton, en relación con la interface, porque estos tienes funciones objetivos como renderizar una nueva vista o cambiar el valor a algunas variables.
> Utilizacion de archivos:

La implementación del programa tiene como parte fundamental la utilización de archivos en aspectos como el manejo de Ranking y mapas.

**Mapas:** Se implementaron 3 distintos mapas que se podrá elegir en la opción personalizar. Estos serán leídos de archivos .txt que se encuentran en la carpeta “mapas”.

**Ranking:** Los puntajes y nicknames se guardaran en un archivo que será leído y sobrescrito cada vez que se termine el juego. Además este guardará los puntajes ordenados

## Diagrama de clases

![diagrama de clases](https://user-images.githubusercontent.com/83974317/178023276-0b8491c7-06e4-49e8-a373-cc73d4e9a5e9.png)

## Partes del Programa:
### Menú:
Al iniciar eljuego se te pedirá un nickname para posteriormente ser guardado en una tabla de ranking. Luego aparecera un menu con las siguientes opciones:

   **1. Jugar PvP :** Este es el modo de juego en el que te enfrentaras contra otro jugador que será manipulado con el teclado.
   
   **2. Jugar PvC :** Este es el modo de juego más interesante, tu oponente estará controlado por la computadora mediante un algoritmo que le permite saber el                             camino más corto entre los ítems y de esta forma terminar de recoger todos los ítems en un menor tiempo..

   **3. Ranking:** Esta opción te mostrará una pantalla donde podrás visualizar todos los jugadores que se registraron en eljuego con sus respectivos puntajes                          ordenados de mayor a menor.

   **4. Personalizar:** En esta opción se te permitirá elegir uno de los 3 mapas en el que quieras jugar, además te mostrará una previsualización del mapa.
   
   |    Mapa 1    |    Mapa 2   |   Mapa 3  |
| ----------- | ----------- | ----------- |
| ![image](https://user-images.githubusercontent.com/102132128/177919549-37fbe1d2-5d33-4f64-adc7-95429bb49dea.png) | ![image](https://user-images.githubusercontent.com/102132128/177919528-fc9d6f8f-7b81-4467-b8f6-c4a2bb558e5d.png) | ![image](https://user-images.githubusercontent.com/102132128/177919446-c444394d-0396-4865-bda4-f3f2da5c9787.png) |



### Score:
Al seleccionar **Jugar** se iniciará el juego y con ello un contador que se utilizará el puntaje que obtuviste luego de recoger todos tus items. Este iniciara en 0 e ira aumentando cada segundo. Una vez que ganes el contador se detendrá y se guardará en un archivo junto con tu nickname.

## Video de explicación
<a>https://youtu.be/haBNslGqT0A

## Bibliografía:

> [1]  SiegeLord.(s.f.). Allegro Vivace. Github-Allegro Wiki. Recuperado el 2 de junio del 2022 de https://github.com/liballeg/allegro_wiki/wiki/Allegro-Vivace.

> [2]  Allegro webmasters.(s.f.) Allegro - A game programming library. Allegro. Recuperado el 9 de junio del 2022 de https://liballeg.org/

> [3]  Brucato C. (2013). The traveling salesman problem.
https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&ved=2ahUKEwi31qbEvOj4AhV9pZUCHarPD5oQFnoECAUQAQ&url=https%3A%2F%2Fwww.mathematics.pitt.edu%2Fsites%2Fdefault%2Ffiles%2FTSP.pdf&usg=AOvVaw3zXFgEnK8O6f157y53eOmz

> [4]  Sánchez. G. (2005). Tutorial interactivo para la enseñanza y el aprendizaje de los algoritmos de búsqueda en anchura y en profundidad
http://bioinfo.uib.es/~joemiro/aenui/procJenui/Jen2006/prDef0107_72b32a1f75.pdf

> [5]  Gutierrez. J. (2018). Traveling Salesman solution in c++ - dynamic programming solution with O(n^2 * 2^n). Repositorio de GitHub. https://gist.github.com/jgcoded/d7ecba7aa3e210419471


## Equipo:

|    Juaquin Remon    |    Leandro Machaca    |    Virginia Puente    |    Dimael Rivas    |
| ----------- | ----------- | ----------- | ----------- |
| ![](https://avatars.githubusercontent.com/u/83974317?v=4) | ![](https://avatars.githubusercontent.com/u/102132128?s=400&v=4) | ![](https://avatars.githubusercontent.com/u/78549698?v=4) | ![](https://avatars.githubusercontent.com/u/88595171?v=4) |
| [github.com/juaquin456](https://github.com/juaquin456) | [github.com/JLeandroJM](https://github.com/JLeandroJM) | [github.com/Mycodeiskuina](https://github.com/Mycodeiskuina) | [github.com/artrivas](https://github.com/artrivas)|








