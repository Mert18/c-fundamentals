#include <stdio.h>


int main(void) {
	int height, length, width, volume, weight;

	printf("Height: ");
	scanf("%d", &height);

	printf("Length: ");
	scanf("%d", &length);

	printf("Width: ");
	scanf("%d", &width);


	volume = height * length * width;
	weight = (volume + 165) / 166;

	printf("Volume (cubic inches): %d\n", volume);
	printf("Dimensional weight (pounds): %d\n", weight);

	return 0;
}
