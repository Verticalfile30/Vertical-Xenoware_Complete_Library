int foo(int add, int add2) {
    int result = add + add2;
    return result;
}

extern void ugh(void);

int main() {

    //int bar = foo(1, 2);

    ugh();

    return 0;
}