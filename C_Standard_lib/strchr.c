#include <stdio.h>
#include <string.h>

int main()
{
	const char str[] = "https://www.runoob.com";
	const char ch = 'o';

	char *ptr;

	ptr = strchr(str, ch);

	if(ptr != NULL)
	{
		printf("%p %p\n", ptr, str);
		printf("o appear in String : %ld\n", ptr-str+1);
		printf("after |%c| is: %s\n", ch, ptr);
	}else{
		printf("|%c| isn't in String!\n", ch);
	}
}
