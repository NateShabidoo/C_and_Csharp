
#include <stdio.h>
#include<stdlib.h>

int main() {
	char	s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	// declare pointer and allocate heap memory space
	char *p;
	p = malloc(sizeof(int) * 13);

	if (p == NULL) {
		printf("malloc() failed!\n");
		return 1;
	}

		// assign p[] with odd letters from s[]
		int i = 0;
		int r = 1;
		while (s[i] != '\0')
		{
			p[i] = s[r];
			i++;
			r+=2;
		}

	//print p[] array with odd letters
  	int l = 0;
	while (p[l] != '\0')
	{
		printf("%c ", p[l]);
		l++;
	}
		printf("\n");

		printf("\n");

	free(p);

	return 0;
}
