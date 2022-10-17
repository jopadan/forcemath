#include "types.hpp"

int main(int argc, char** argv)
{
	if(argc > 2)
	{
		float in = atof(argv[1]);
		fixed<int64_t, double, 32,32> a(in); 

		printf("%f %ld %ld\n", (double)a, (int64_t)a, a.from_float(in) );
	}

	exit(EXIT_SUCCESS);
}
