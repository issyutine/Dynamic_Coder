#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {
	double pie;
	double x = 0;
	double y = 0;

	int count = 0, circle = 0;

	srand(time(NULL));
	int i = 0;
	int max = 1000000000;
	int min = 10000000;
	while (count < max) {
		
		x = (double)rand() / (double)RAND_MAX;
		y = (double)rand() / (double)RAND_MAX;
		pie = 4*(circle / count);
		if (count % max == 0) {

			printf("%d진행.. 원주율 : %lf",count/min , pie);

		}
		count++;

	}
	
}