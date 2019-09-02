#ifndef QUICK_H
#define QUICK_H

#include "sort.h"

class QuickSort : public Sort {
public:
    QuickSort(int *elements, size_t size) : Sort(elements, size) {}

    void execute() {
        quick(0, size-1);
    }

    void quick(int low, int high) {
        if ( low < high ) {
            int p = partition(low, high);
            quick(low, p);
            quick(p + 1, high);
        }
    }

    int partition(int low, int high) {
        int pivot = elements[low + (high - low) / 2];

        for (;;) {
            while (elements[low] < pivot)
                low++;

            while (elements[high] > pivot)
                high--;

            if (low >= high)
                return high;

            swap(&elements[low], &elements[high]);

            low++;
            high--;
        }
    }

    void swap(int *x1, int *x2) {
        int tmp = *x1;

        *x1 = *x2;
        *x2 = tmp;
    }

    inline string name() { return "QuickSort"; }
};

#endif