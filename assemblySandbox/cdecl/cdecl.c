
extern float fpuTest(float num, float num2);

int main() {
    //this will call the external float function fpuTest
    //and pass in the values of num and num2
    //the return value of fpuTest is stored in the variable result
    float result = fpuTest(1.0f, 2.0f);
    return 0;
}