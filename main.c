#include "print.h"

int main(int argc, char const *argv[])
{    

    char *cambiar = "Hola %e adios";

    //print("Hola grupo de waifus informatica\n");
    print("Hola %e %e %e %e %c %c ",1,2,3,4,'b','a');
    print("%c%c%c%c%c%c%c%c\nAdios..",'3','.','1','4','1','5','1','6');
    print("Hola");
    print("Si la perra esta amarrada\naunque ladre todo el dia no la deben de soltar");

    for (int i = 0; i <= 10; i++){
        print("%e es par: %b",i,(i%2 == 0));
    }

    putchar(10);
    system("read -p ''");

    return 0;
}