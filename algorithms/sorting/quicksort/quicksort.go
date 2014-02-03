package main;

import (
    "fmt"
)


func partition(ary []int, left, right int) int {
    pivot := ary[left]
    store := left

    ary[left], ary[right] = ary[right], ary[left]
    for i := left; i < right; i += 1 {
        if ary[i] < pivot {
            ary[i], ary[store] = ary[store], ary[i]
            store += 1
        }
    }

    ary[store], ary[right] = ary[right], ary[store]
    return store
}

func quicksort(ary []int, left, right int) {
    if left < right {
        pivot := partition(ary, left, right)
        quicksort(ary, left, pivot - 1)
        quicksort(ary, pivot + 1, right)
    }
}


func main() {
    ary := []int{ 4, 65, 2, -31, 0, 99, 2, 83, 782, 1 }
    fmt.Printf("%v\n", ary)
    quicksort(ary, 0, len(ary) - 1)
    fmt.Printf("%v\n", ary)
}
