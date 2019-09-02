#ifndef MERGE_H
#define MERGE_H

#include "sort.h"

class MergeSort : public Sort {       
    public:
        MergeSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            // TODO
            divide(0, size - 1);
        }

        void divide(int start, int end) {
            if (start < end) {
                int mid = (start + end) / 2;        // defines the current array in 2 parts .
                divide(start, mid);                 // sort the 1st part of array .
                divide(mid + 1, end);              // sort the 2nd part of array.

                merge(start, mid, end);
            }
        }

        void merge(int start, int mid, int end) {
            int p=start, q=mid+1;

            int result[end-start+1], k=0;

            for(int i = start ;i <= end ;i++) {
                if(p > mid)      //checks if first part comes to an end or not .
                    result[ k++ ] = elements[ q++] ;

                else if ( q > end)   //checks if second part comes to an end or not
                    result[ k++ ] = elements[ p++ ];

                else if( elements[ p ] < elements[ q ])     //checks which part has smaller element.
                    result[ k++ ] = elements[ p++ ];

                else
                    result[ k++ ] = elements[ q++];
            }

            for (int p=0 ; p < k ;p ++) {
                /* Now the real array has elements in sorted manner including both
                     parts.*/
                elements[ start++ ] = result[ p ] ;
            }
        }

        inline string name() { return "MergeSort"; }
};

#endif