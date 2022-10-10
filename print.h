#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#define TRUE 1
#define FALSE 0

typedef int bool;

int print(char *, ...);

char *replaceString(char *, int, int, char *);
const char *convert(int );
int print(char *texto, ...){
    // entero
    // flotante
    // caracter
    // booleano | logico
	unsigned cant = 0;
	int pos;
	int var_int;
	char var_char;
	double var_float;
	bool var_bool;
	bool onetime = 0;
	char *var_ptrChar;

	char var_string[1000];//sirve para hacer el intercambio de variable a char *
	char *buffTexto = (char *) malloc(sizeof(texto));

	for (int i = 0; i < strlen(texto); i++){
		if(texto[i] == '%'){
			cant++;
		}
	}

	buffTexto = texto;

	if(cant){
		va_list ap;

		va_start(ap, cant);

		for (int i = 0; i <= cant; i++){
			onetime = 0;
			for (int j = 0; j < strlen(buffTexto); j++){
				if(buffTexto[j] == '%' && !onetime){
					pos = j + 1;
					onetime = 1;
				}
			}

			if(buffTexto[pos] == 'e'){
				var_int = va_arg(ap, int);

				snprintf(var_string, sizeof(var_string), "%i", var_int);

				buffTexto = replaceString(buffTexto, pos - 1, pos + 1, var_string);
			}else{
				if(buffTexto[pos] == 'f'){
					var_float = va_arg(ap, double);

					snprintf(var_string, sizeof(var_string), "%f", var_float);
					
					buffTexto = replaceString(buffTexto, pos - 1, pos + 1, var_string);
				}else{
					if(buffTexto[pos] == 'c'){
						var_char = va_arg(ap, int);

						snprintf(var_string, sizeof(var_string), "%c", var_char);
						
						buffTexto = replaceString(buffTexto, pos - 1, pos + 1, var_string);
					}else{
						if(buffTexto[pos] == 'b'){
							var_bool = va_arg(ap, int);
							

							snprintf(var_string, sizeof(var_string), "%s",convert(var_bool));

							buffTexto = replaceString(buffTexto, pos - 1, pos + 1, var_string );
						}else{
							if(buffTexto[pos] == 's'){
								var_ptrChar = va_arg(ap, char *);

								buffTexto = replaceString(buffTexto, pos - 1, pos + 1, var_ptrChar);
							}
						}
					}
				}
			}
		}

		va_end(ap);
		print(buffTexto);
		free(buffTexto);
	}else{
		for (int i = 0; i < strlen(buffTexto); i++)
		{
			putc(buffTexto[i], stdout);
		}
	}	
    return 0;
}

char *replaceString(char *texto, int pntA, int pntB, char *cambiar){
	char *elTexto;

	elTexto = (char *) malloc(strlen(texto) + strlen(cambiar));

	for(int i = 0; i < pntA; i++){
		elTexto[i] = texto[i];
	}

	for (int i = pntA; i < pntA + strlen(cambiar); i++){
		elTexto[i] = cambiar[i - pntA];
	}

	for(int i = pntA + strlen(cambiar); i < strlen(elTexto) + strlen(cambiar); i++){
		elTexto[i] = texto[pntB++];
	}

	return elTexto;
}

const char *convert(int valor){
	return (valor)? "true" : "false";
}
