#include <syslog.h>
#include <stdio.h>
int main()
{
  syslog(LOG_WARNING, "Warning detected in %s %u\n",
	 __FILE__, __LINE__);                                    

	char t[10];

	int a = 902;

	sprintf(t, ("%s %i", "hola", a);
	
	printf("%s", t);
}








