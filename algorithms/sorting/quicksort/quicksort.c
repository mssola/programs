
#include <stdio.h>


void swap(int *first, int *last)
{
    int temp = *last;
    *last = *first;
    *first = temp;
}

int * partition(int *first, int *last, int *pivot)
{
    int *store, *ptr;
    int value = *pivot;

    swap(pivot, last);
    store = first;
    for (ptr = first; ptr < last; ptr++) {
        if (*ptr < value) {
            swap(ptr, store);
            store++;
        }
    }
    swap(store, last);
    return store;
}

void quicksort(int *first, int *last)
{
    int *pivot, *mid;

    if (first < last) {
        // The pivot index is the median of the first, last and the middle
        // elements. This way the worst-case behavior is avoided.
        mid = first + ((last - first + 1) / 2);
        pivot = last;
        if (*first < *mid) {
            if (*first >= *last)
                pivot = first;
            else if (*mid < *last)
                pivot = mid;
        } else if (*first < *last)
            pivot = first;

        // Do the partition operation and sort the sub-lists.
        pivot = partition(first, last, pivot);
        quicksort(first, pivot - 1);
        quicksort(pivot + 1, last);
    }
}

int main(int argc, char *argv[])
{
    int i;
    int v[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int size = sizeof(v) / sizeof(v[0]);

    for (i = 0; i < size; i++)
        printf("%i ", v[i]);
    printf("\n");

    quicksort(v, v + size - 1);

    for (i = 0; i < size; i++)
        printf("%i ", v[i]);
    printf("\n");
    return 0;
}
