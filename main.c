#include <stdio.h>
#include <immintrin.h>

int main() {

    union {float array[4]; __m128 vector1;} array;

    union {float sumArray[4]; __m128 vector2;} sumArray;
    union {float sum[4]; __m128 addResults;} sum;

    union {float productArray[4]; __m128 vector3;} productArray;
    union {float product[4]; __m128 mulResults;} product;

    array.array[0] = 4;
    array.array[1] = 6;
    array.array[2] = 2;
    array.array[3] = 9;

    sumArray.sumArray[0] = 3;
    sumArray.sumArray[1] = 61;
    sumArray.sumArray[2] = 7;
    sumArray.sumArray[3] = 8;

    productArray.productArray[0] = 3;
    productArray.productArray[1] = 61;
    productArray.productArray[2] = 7;
    productArray.productArray[3] = 8;



    sum.addResults =_mm_add_ps(array.vector1, sumArray.vector2);

    product.mulResults =_mm_mul_ps(array.vector1, productArray.vector3);



    for (int i = 0; i < 4; ++i){
        printf("%.0f + %.0f = %.0f\n", array.array[i], sumArray.sumArray[i], sum.sum[i]);
    }

    printf("\n");

    for (int i = 0; i < 4; ++i){
        printf("%.0f * %.0f = %.0f\n", array.array[i], productArray.productArray[i], product.product[i]);
    }
}