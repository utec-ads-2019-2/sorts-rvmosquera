#ifndef COUNTING_H
#define COUNTING_H

#include "sort.h"
#include <algorithm>
#include <map>

class CountingSort : public Sort {
public:
    CountingSort(int *elements, size_t size) : Sort(elements, size) {}

    void execute() {
        //map<int, int> vectorCount;
        int **vectorCount;
        int menor, mayor=0;

        menor = elements[0];
        for(int k=0 ; k < size ; k++) {
            int element = elements[k];

            if ( element < menor)
                menor = element;

            if ( element > mayor)
                mayor = element;

        }

        int countLen = mayor - menor + 1;
        vectorCount = new int*[countLen];

        for(int i = 0 ; i < countLen ; i++)
            vectorCount[i] = new int[2];

        int k=menor;
        for( int i=0 ; i < countLen ; i++ ) {
            vectorCount[i][0] = k; // first
            vectorCount[i][1] = 0;
            k++;
        }

        for( int j=0 ; j < size ; j++) {
            int element = elements[j];

            int index = element - menor;

            vectorCount[index][1]++;
        }

        k=0;
        for( int i=0 ; i < countLen ; i++) {
            for( int j=0 ; j < vectorCount[i][1] ; j++) {
                elements[k] = vectorCount[i][0];
                k++;
            }
        }

    }

    static void sort(int list[], int n, int exp) {
        int output[n];
        int count[10] = {0};

        for (int i = 0; i < n; i++)
            count[(list[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            output[count[(list[i] / exp) % 10] - 1] = list[i];
            count[(list[i] / exp) % 10]--;
        }

        for (int i = 0; i < n; i++)
            list[i] = output[i];
    }

    inline string name() { return "CountingSort"; }
};

#endif