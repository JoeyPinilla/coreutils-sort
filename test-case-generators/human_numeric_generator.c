#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

int main (int argc, char** argv) {
	intmax_t i, random, whole, fraction, num_rand;
	int magnitude;
	char buf[1024];
	char mag[10] = { ' ', 'k', 'K', 'M', 'G', 'T', 'P', 'E', 'Z', 'Y' };
	if (argc != 2) {
		printf("Please input the number of lines to be generated.\n");
		return -1;
	}
	num_rand = atoi(argv[1]);
	srand(time(NULL));
	for (i = 0; i < num_rand; i++) {
		random = rand();
		random = random*random*random;
		whole = random % (INTMAX_MAX>>5);
		random = rand();
		random = random*random*random;
		fraction = abs(random) % 100;
		magnitude = rand() % 10;
		random = rand() % 6;
		if (random == 0) {
			sprintf(buf,"%ju",whole);
			printf("%.*s.%.1ju%c\n",rand()%20+1,buf,fraction,mag[magnitude]);
		}
		else if (random == 1) {
			sprintf(buf,"&ju",whole);
			printf("-%.*s.%.1ju%c\n",rand()%20+1,buf,fraction,mag[magnitude]);
		}
		else if (random == 2) {
			printf("-0.%.1ju%c\n",fraction,mag[magnitude]);
		}
		else if (random == 3) {
			printf("0.%.1ju%c\n",fraction,mag[magnitude]);
		}
		else if (random == 4) {
			sprintf(buf,"%ju",whole);
			printf("-%.*s%c",rand()%20+1,buf,mag[magnitude]);
		}
		else {
			sprintf(buf,"%ju",whole);
			printf("%.*s%c\n",rand()%20+1,buf,mag[magnitude]);
		}
	}
	return 0;
}