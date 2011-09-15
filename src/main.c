#include <stdio.h>
#include <stdlib.h>

int whole_test_result = 0;

void vector_tests();
void matrix_tests();
void mv_tests();
void cam_test();

int main(int argc, char **argv)
{	
	vector_tests();
	matrix_tests();
	mv_tests();
	cam_test();
	return whole_test_result;
}


