#include <sys/time.h>
#include <limits>
#include <string>
#include <iostream>
#include <iomanip>

//Containers
#include <map>
#include "map.hpp"

#define Time_start \
{ \
	std::cout << "Start at line: " << __LINE__ << ". Took: "; \
	timeval start;gettimeofday(&start, NULL);

#define Time_end \
	timeval stop;gettimeofday(&stop, NULL);\
	std::cout << std::setw(15) << stop.tv_sec - start.tv_sec << " s, ";\
	std::cout << std::setw(15) << (stop.tv_usec / 1000 + stop.tv_sec * 1000) - \
		(start.tv_usec / 1000 + start.tv_sec * 1000) << " ms, "; \
	std::cout << std::setw(15) << (stop.tv_usec + stop.tv_sec * 1000000) - \
		(start.tv_usec + start.tv_sec * 1000000) << " us, " << std::endl; \
}


//map
void test_map() { 
	Time_start;
	
	Time_end;
}

int main() {
	test_map();
	return 0;
}