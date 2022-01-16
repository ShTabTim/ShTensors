#include <iostream>

#include "FundLibs/ShTensors/Tensors.h"

int main() {

    ket<ket<float, -3>, -3> g;
    //set g as euklidian
    sum(i, 3, sum(j, 3, g[-i][-j] = d_kron(i, j)));
    //set a {1,1,1}
    bra<float, 3> a(1);
    bra<float, 3> b;

    //set b rand
    sum(i, 3, b[i] = rand());

    //add b a
    sum(i, 3, b[i] += a[i]);

    //length of a
    float aLen = 0;
    sum(i, 3, sum(j, 3, aLen += g[-i][-j] * a[i] * a[j]));
    aLen = sqrt(aLen);

    //dot product a and b
    float aDoTb = 0;
    sum(i, 3, sum(j, 3, aDoTb += g[-i][-j] * a[i] * b[j]));
}