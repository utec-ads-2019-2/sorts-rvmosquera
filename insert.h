#ifndef INSERT_H
#define INSERT_H

#include "sort.h"

class InsertSort : public Sort {       
    public:
        InsertSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            int key=0;
            for(int j=1; j <= size-1; j++) {
                key = elements[j];

                int i= j-1;

                while(i >= 0 && elements[i] > key ) {
                    elements[i+1] = elements[i];
                    i = i-1;
                }
                elements[i+1] = key;
            }
        }

        inline string name() { return "InsertSort"; }
};

#endif