#include <stdio.h>
#include "lab2.h"

void multiply_matrices (
		data_t n,
		data_t a[N],
		data_t b[N],
		data_t c[N]
		) {

	iter_t i, j, k;
	data_t acc;
	if (n >= 5 && n <= 10) {
		Line_Loop: for (i = 0; i < n; ++i) {
//#pragma HLS UNROLL factor=2
//#pragma HLS PIPELINE
			Column_Loop: for (j = 0; j < n; ++j) {
//#pragma HLS UNROLL factor=2
//#pragma HLS PIPELINE
				acc = 0;
				Sum_Loop: for (k = 0; k < n; ++k) {
//#pragma HLS UNROLL factor=1
//#pragma HLS PIPELINE
					acc += a[i*n + k] * b[k*n + j];
				}
				c[i*n + j] = acc;
			}
		}

	}
	else {
		printf("Matrix size should be in this bounds: [5;10]\n");
	}
}
