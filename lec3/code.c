#include <stdio.h>
#include <string.h>

void f1() {
    short s = 45;
    double d = *(double*) &s;
    printf("%f\n", d);
}

typedef struct {
    int num;
    int denom;
} fraction;

void f2() {
    fraction pi;
    pi.num = 22;
    pi.denom = 7;

    ((fraction*) &pi.denom)->num = 12;

   printf("denom: %d\n", pi.denom);
}

void f3() {
    // array = &array[0]
    int array[5];

    array[3] = 128;
    ((short*) array)[6] = 2;

    printf("array[3]: %d\n", array[3]);
}

typedef struct {
    char *name;
    char suid[8];
    int numUnits;
} student;

void f4() {
    student pupils[4];

    pupils[0].numUnits = 21;
    pupils[2].name = strdup("Adam");
    pupils[3].name = pupils[0].suid + 6;
    strcpy(pupils[1].suid, "40415xx");

    printf("char -> %c\n", pupils[1].suid[4]);

    //strcpy(pupils[3].name, "123456")
}

int main() {
    f1();
    f2();
    f3();
    f4();
}
