#include "print.h"

#define fun(x,y) x##y

int main(int argc, char const *argv[])
{    

    char *cambiar = "Hola %e adios\n";

    print("%s",fun(a, b));
    /*
    //print("Hola grupo de waifus informatica\n");
    print("Hola %e %e %e %e %c %c %c %s\n",1,2,3,4,'b','a','e',"mi cadena");
    print("valor de pi: %s\nAdios..\n","3.141516");
    print("Hola\n");
    print(cambiar,30);
    print("Si la perra esta amarrada\n");

    for (int i = 0; i <= 10; i++){
        print("%e es par: %b\n",i,(i%2 == 0));
    }

    print("Demostracion de cuanta memoria puede almacenar mi funcion print \nDato cadena: %s\nDato booleano: %b\nDato numero: %e\n","dato", TRUE,20);
    */
    return 0;
}