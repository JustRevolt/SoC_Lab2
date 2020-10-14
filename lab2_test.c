#include <stdio.h>
#include <stdlib.h>
#include "lab2.h"

void get_matrix(FILE * input, data_t n, data_t * a) {
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			fscanf(input, "%hi ", &a[i*n + j]);
		}
		fscanf(input, "\n");
	}
}

void print_matrix(FILE * output, data_t n, data_t * a) {
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			fprintf(output, "%hi ", a[i*n + j]);
		}
		fprintf(output, "\n");
	}
	fprintf(output, "\n");
}


int main () {
	FILE *fs, *fp;
	
	int test_count, k;
	data_t n, a[N], b[N], c[N];
	
	test_count = 0; //количество тестов
	
	fs = fopen("in.dat", "r");
	fp = fopen("out.dat","w");
	
	fscanf(fs, "%d", &test_count);

	for (k = 0; k < test_count; k++){
		fscanf(fs, "\n%hi\n", &n);
		get_matrix(fs, n, a);
		fscanf(fs, "\n");
		get_matrix(fs, n, b);

		multiply_matrices(n, a, b, &c);

		fprintf(fp, "\n%hi\n", n);
		print_matrix(fp, n, a);
		print_matrix(fp, n, b);
		print_matrix(fp, n, c);
	}
	
	fclose(fs);  
  	fclose(fp);
  
  printf ("Comparing against output data \n");
  if (system("diff -w out.dat out.gold.dat")) {
	fprintf(stdout, "*******************************************\n");
	fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
	fprintf(stdout, "*******************************************\n");
     return 1;
  } else {
	fprintf(stdout, "*******************************************\n");
	fprintf(stdout, "PASS: The output matches the golden output!\n");
	fprintf(stdout, "*******************************************\n");
     return 0;
  }
}
