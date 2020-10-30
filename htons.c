#include <unistd.h>

int	main(int argc, char** argv)
{

	int start, res, port;
	port = atoi(argv[1]);
	res = (port / 256) + (256 * (port % 256));
	printf ("Port %i ==> %i\n", port, res);
	printf ("Bueno %i => %i\n", port, htons(port));
}
