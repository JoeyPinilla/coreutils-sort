#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

int main (int argc, char** argv) {
	intmax_t i, random, whole, fraction, num_rand;
    char buf[1024];
	if (argc != 2) {
		printf("Please input the number of lines to be generated.\n");
		return -1;
	}
	num_rand = atoi(argv[1]);
	srand(time(NULL));
	for (i = 0; i < num_rand; i++) {
		random = rand();
		random = random*random;
		whole = random % (INTMAX_MAX>>1);
		random = rand() % 2;
		if (random == 0) {
            sprintf(buf,"%ju",whole);
            printf("-%.*s\n",rand()%20+1,buf);
        }
		else {
            sprintf(buf,"%ju",whole);
			printf("%.*s\n",rand()%20+1,buf);
		}
	}
	return 0;
}