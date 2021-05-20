#include "Swiat.h"
#include <stdlib.h>
#include <ctime>

int main()
{
	srand(time(NULL));
	Swiat nowySwiat(20, 20);
	nowySwiat.rysujSwiat();
}