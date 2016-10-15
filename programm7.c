#include <stdio.h>>

int main (void)
{
	char inputType;
	double inputValue;
	double celsiumValue;
	double farengateValue;
	double kelvinValue;

	printf("Write type of temmperature\n");
	printf("C - celsium\n");
	printf("F - farengate\n");
	printf("K - kelvin\n");

	scanf("%s", &inputType);

	switch( inputType )
	{
		case 'C':
			printf("Write celsium value\n");

			scanf("%.2lf", celsiumValue);
			farengateValue = 1.8 * celsiumValue + 32;
			kelvinValue = celsiumValue + 273;

			printf("Farengate value - %.2lf\n", farengateValue);
			printf("Kelvin value - %.2lf\n", kelvinValue);
			break;

		case 'F':
			printf("Write farengate value\n");

			scanf("%.2lf", farengateValue);
			celsiumValue = (farengateValue - 32)/1.8;
			kelvinValue = celsiumValue + 273;

			printf("Celsium value - %.2lf\n", celsiumValue);
			printf("Kelvin value - %.2lf\n", kelvinValue);
			break;

		case 'K':
			printf("Write kelvin value\n");

			scanf("%.2lf", kelvinValue);
			celsiumValue = kelvinValue - 273;
			farengateValue = 1.8 * celsiumValue + 32;

			printf("Celsium value - %.2lf\n", celsiumValue);
			printf("Farengate value - %.2lf\n", farengateValue);
			break;

		default:
			printf("Write correct type!\n");
			break;
	}


	return 0;
}
