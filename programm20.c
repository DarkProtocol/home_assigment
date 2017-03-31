#include <stdio.h>
#include <math.h>

int getMaxNumber(unsigned long int number) {

	int residue = 0;
	int maxResidue = 0;

	while (number > 0) {

		residue = number % 10;
		number -= residue;
		number /= 10;
		maxResidue = residue > maxResidue ? residue : maxResidue;
		
	}

	return maxResidue;
}

int main (void)
{
	unsigned long int number = 123476812;
	int maxNumber = getMaxNumber(number);
	printf("%d\n", maxNumber);
	return 0;
}
