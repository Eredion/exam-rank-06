#include <unistd.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
// My version of htons funtion.

int my_htons (int port)
{
	return ((port / 256) + (256 * (port % 256));
}

int	main(int argc, char** argv)
{

	int start, res, port;
	port = atoi(argv[1]);
	res = (port / 256) + (256 * (port % 256));
	printf ("Port %i ==> %i\n", port, my_htons(port));
	printf ("Bueno %i => %i\n", port, htons(port));
}
