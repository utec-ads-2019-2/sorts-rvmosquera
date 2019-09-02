#ifndef SELECT_H
#define SELECT_H

#include "sort.h"

class SelectSort : public Sort {
public:
    SelectSort(int *elements, size_t size) : Sort(elements, size) {}

    void execute() {
        int i, j, minor=0, index_minor=0;
        for (i = 0; i < size - 1; i++) {
            minor = elements[i];
            for (j = i; j < size; j++)
                if (elements[j] < minor) {
                    minor = elements[j];
                    index_minor = j;
                }

            if ( elements[i] > minor)
                swap(&elements[i], &elements[index_minor]);
        }
    }

    void swap(int *x1, int *x2) {
        int tmp = *x1;

        *x1 = *x2;
        *x2 = tmp;
    }

    inline string name() { return "SelectSort"; }
};

#endif