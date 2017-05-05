#!/bin/env python
# -*- coding: utf-8 -*-

def quick_sort(arr, low, high):
    first = low
    last = high
    key = arr[low]
    while first < last:
        while first < last and arr[last] >= key:
            --last
        arr[first] = arr[last]
        while first < last and arr[first] <= key:
            ++first
        arr[last] = arr[first]
    arr[first] = key
    quick_sort(arr, low, first -1)
    quick_sort(arr, first + 1, high)
