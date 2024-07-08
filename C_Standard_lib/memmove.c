#include <stdio.h>
#include <string.h>

int main()
{
	char dest[] = "old";
	const char src[] = "new";

	printf("Before memmove dest = %s, src = %s\n", dest, src);
	memmove(dest, src, 3);
	printf("After memmove dest = %s, src = %s\n", dest, src);

	return 0;
}
