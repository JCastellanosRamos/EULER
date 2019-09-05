/*Jonathan Pérez Nava |||| José Castellanos Ramos
5 de Septiembre 2019
El programa es capaz de resolver una ecuacion diferencial de primer grado
utilizando el metodo de euler, los resultados se guardan en un archivo .dat
para posteriormente ser ploteados.
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>    //Poder utilizar variables booleanas

double F(double T, double Y);
void capturaDatos(float *A, float *B, float *ALPHA,int *N);     //Nos permite regresar dos variables mediante el uso de apuntadores
void setValues(float A, float B, float ALPHA,int N, float *H, float *W, float *T);
void resolucion(float A,int N, float H, float W, float T);

int main (){
    float A,B,ALPHA,H,T,W;
	int I,N;

    capturaDatos(&A,&B,&ALPHA,&N);

    setValues(A,B,ALPHA,N,&H,&W,&T);

    resolucion(A,N,H,W,T);

    return 0;
}
void capturaDatos(float *A, float *B, float *ALPHA, int *N){
    int OK = false;
    while (!(OK))
    {
        printf("Dame el valor del Extremo A\n");
	    scanf("%f",A);
	    getchar();
	    printf("Dame el Valor del extremo B\n");
	    scanf("%f",B);
	    getchar();
        if(*A >= *B)
			printf("El valor de B debe ser mayor que A\n");
		else 
            OK = true;
    }
    printf("Dar la condicion inicial\n");
	scanf("%f",ALPHA);
	OK=false;
	while(!(OK)){
		printf("dar el numero de subintervalos\n");
		scanf("%d",N);
		if(*N <= 0.0)
			printf("Debe ser un numero natural\n");
		else OK =true;
	}
}

void setValues(float A, float B, float ALPHA,int N, float *H, float *W, float *T){
    *H = (B - A) / N;
	*T = A;
	*W =ALPHA;
}

void resolucion(float A,int N, float H, float W, float T){
    FILE * OUP;
	OUP = fopen ("eulerResults.dat", "w+");
    for(int I=1;I<=N;I++){
	    W= W+H * F(T,W);
	    T= A + I * H;
        printf("%f  %f\n",T,W);
        fprintf(OUP, "%f %f\n",T,W);
    }
	fclose(OUP);
}

double F(double T,double Y){
	double f;
	f = Y - T * T + 1.0;
	return f;
}