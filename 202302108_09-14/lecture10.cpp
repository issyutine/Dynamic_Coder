#include <stdio.h>

int main(void) {

	int dan = 2;
	int su = 1;
	while (dan <= 9) {

		if (dan == 5)
			
			continue;
		dan++;
		while(su <= 9) {

			printf("%d * %d = %d\n", dan, su, dan * su);
			su++;
		}
		dan++;
		su = 1;
   }
	return 0;
}