#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;
}eVacuna;

float aplicarAumento(float precio);
int reemplazarCaracteres(char cadena[], char primerC, char segundoC);
int ordenarEstructura(eVacuna vacuna[]);





int main()
{
  float precio = 10;
  float precioFinal;

  char nombre[20] = "Roberto";
  int contadorFunc;

  eVacuna vacuna[4] ={
      {20000,"PFizer", 'a', 100},
      {20001,"Astrazeneca", 'b', 50},
      {20002,"Sputnik", 'c', 20.5},
      {20003,"Moderna", 'c', 40},

  };

  precioFinal = aplicarAumento(precio);

  printf("Primer Punto: \n\n");

  printf("%.2f\n\n", precioFinal);

  printf("----------------------------------------\n");
  printf("Segundo punto:\n\n");

  contadorFunc = reemplazarCaracteres(nombre, 'o', 'x');

  printf("%s  %d", nombre, contadorFunc);

  printf("----------------------------------------\n");
  printf("Tercer punto:\n\n");
  ordenarEstructura(vacuna);

  for(int i = 0; i < 4; i++)
  {
      printf("%d     %s    %c    %f",vacuna->id,
                                     vacuna->nombre,
                                     vacuna->tipo,
                                     vacuna->efectividad);
  }


}


float aplicarAumento(float precio)
{
    int aumento = 5;
    float resultado = 0;

    if(precio > 0)
    {
        resultado = (float) precio + ((precio*aumento)/100);
    }


    return resultado;
}


int reemplazarCaracteres(char cadena[], char primerC, char segundoC)
{

    int contador = 0;

    for(int i=0; i < sizeof(cadena); i++)
    {
        if(cadena[i] == primerC)
        {
            contador++;
            cadena[i] = segundoC;

        }
    }

    return contador;


}

int ordenarEstructura(eVacuna vacuna[])
{

    eVacuna auxVacuna;

    if(vacuna != NULL)
    {
        for(int i =0; i < sizeof(vacuna); i++)
        {
            for(int j = 0; j < i+1; j++)
            {
                if(vacuna[i].tipo < vacuna[j].tipo ||
                   vacuna[i].tipo == vacuna[j].tipo &&
                   vacuna[i].efectividad < vacuna[j].efectividad)
                {
                    auxVacuna = vacuna[i];
                    vacuna[i] = vacuna[j];
                    vacuna[j] = auxVacuna;
                }
            }
        }
    }
}


