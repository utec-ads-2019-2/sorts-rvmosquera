#ifndef RADIX_H
#define RADIX_H

#include "sort.h"
#include "counting.h"

class RadixSort : public Sort {
public:
    RadixSort(int *elements, size_t size) : Sort(elements, size) {}

    void execute() {
        int m = getMax();

        int exp;
        for (exp = 1; m / exp > 0; exp *= 10)
            CountingSort::sort(elements, size, exp);
    }

    int getMax() {
        int max = elements[0];
        for (int i = 1; i < size; i++)
            if (elements[i] > max)
                max = elements[i];

        return max;
    }

    inline string name() { return "RadixSort"; }
};

#endif