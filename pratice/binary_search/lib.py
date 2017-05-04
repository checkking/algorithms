#!/bin/env python
# -*- coding: utf-8 -*-

def bin_search(arr, key):
    left = 0
    right = len(arr) - 1
    while left <= right:
        mid = left + (right - left) >> 1
        if arr[mid] < key:
            left = mid + 1
        elif arr[mid] > key:
            right = mid - 1
        else:
            return mid
    return -1

def bin_search_first(arr, key):
    """
    1) arr[mid] < key, x ~ [mid + 1, right]
    2) arr[mid] >= key, x ~ [left, mid]
    break: left < right
    """
    left = 0
    right = len(arr) - 1
    while left < right:
        mid = left + (right - left) >> 1
        if arr[mid] < key:
            left = mid + 1
        else:
            right = mid
    if arr[left] == key:
        return left
    return -1

def bin_search_last(arr, key):
    """
    1) arr[mid] > key, x ~ [left, mid - 1]
    2) arr[mid] <= key, x ~ [mid, right]
    """
    left = 0
    right = len(arr) - 1
    while left < right:
        mid = left + (right - left) >> 1
        if arr[mid] > key:
            right = mid - 1
        else:
            left = mid
    if arr[left] == key:
        return left
    return -1

def bin_search_lower_bound(arr, key):
    """
    1) arr[mid] < key, x ~ [mid + 1, right]
    2)_arr[mid] >= key, x ~ [left, mid]
    """
    left = 0
    right = len(arr) - 1
    while left < right:
        mid = left + (right - left) >> 1
        if arr[mid] < key:
            left = mid + 1
        else:
            right = mid
    if arr[left] >= key:
        return left
    return -1

def bin_search_upper_bound(arr, key):
    """
    1) 如果array[mid]>key，那么x在区间[left, mid]
    2) 如果array[mid]≤key，那么x在区间[mid + 1, right]
    """
    left = 0
    right = len(arr) - 1
    while left < right:
        mid = left + (right - left) >> 1
        if arr[mid] > key:
            right = mid
        else:
            left = mid + 1
    if arr[left] > key:
        return left
    return -1
