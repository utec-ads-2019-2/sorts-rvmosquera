#ifndef SHELL_H
#define SHELL_H

#include "sort.h"

class ShellSort : public Sort {       
    public:
        ShellSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {

           /* for(int j=0; j < size ; j++) {
                for (int i = gap; i < n; i++) {
                    auto temp = a[i];
                    for (j = i; j >= gap and a[j - gap] > temp; j -= gap)
                        a[j] = a[j - gap]
                    a[j] = temp
                }
            }*/
        }

        inline string name() { return "ShellSort"; }
};

#endif