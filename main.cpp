#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
double * Random(int n) {
	srand(time(NULL));
	double *p;
	p =(double*) malloc(n * sizeof(double));
	while (n--) {
		*(p+n)= (double)rand()/RAND_MAX*1.0;
	}
	return p;
}

void printMatrix(double * matrix, int n){
    int i=0;
    while(i<n){
        printf("%0.2f ",matrix[i]);
        i++;
    }
    printf("\n");
}

double ** Matrix(double *A, int n, int r) {
	double **matrix = (double**)malloc(sizeof(double *)*r);
	int cols= n/r + (n % r != 0);
	int totalAdded=0;
	int rowCounter=0, colCounter=0;
	while (rowCounter < r) {
		matrix[rowCounter] = (double *)malloc(cols*(sizeof (double)));
		colCounter = 0;
		while (colCounter < cols) {
			if (totalAdded < n) {
			    matrix[rowCounter][colCounter] = A[(rowCounter*cols) + colCounter];
			}
			else {
				matrix[rowCounter][colCounter] = 0;
			}
			colCounter++;
			totalAdded++;
		}

		rowCounter++;
	}

	return matrix;
}

double * Max(double *A, int n){
    int i=0;
    double max=0, *p=NULL;
    while(i<n){
        if(A[i]>max){
            max=A[i];
            p=&A[i];
        }
        i++;
    }
    return p;
}

int main(){
	int n = 8, r=8;
	printf("Vnesi n: ");
    scanf("%d", &n);
    printf("Vnesi r: ");
    scanf("%0d", &r);


    clock_t start,stop;
    double time;
    start=clock();
    double * numbers= Random(n);
    stop=clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;

    printf("1D: \n");
    printMatrix(numbers,n);

    printf("2D: \n");
    double **p = Matrix(numbers,n,r);
    int i=0;
    while(i<r){
        printMatrix(p[i],n/r + (n % r != 0));
        i++;
    }

    double * max= Max(numbers,n);
    printf("Najvecja vrednost: %0.2f na naslovu %08X\n",*max,max);
    printf("Cas generiranja naključnih stevil: %0.2f s\n",time);
	return 0;
}