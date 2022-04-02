#include <stdio.h>

extern float *stackTest(float arg1, float arg2, float arg3, float arg4);

int main() {
	float num = 3.5;
	float num2 = 4.5;
	float num3 = 5.5;
	float num4 = 6.5;

	float *result = stackTest(num, num2, num3, num4);
	
	
	
	return 0;
}