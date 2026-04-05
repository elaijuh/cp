"""
Complexity:
    Average: O(n) — each partition roughly halves the work
    Worst case: O(n²) — mitigated by random pivot selection
Space: O(log n) stack space
"""

import random


def partition(arr, left, right):
    # Pick a random pivot and move it to the end
    pivot_idx = random.randint(left, right)
    arr[pivot_idx], arr[right] = arr[right], arr[pivot_idx]

    pivot = arr[right]
    i = left  # i tracks the boundary of elements < pivot

    for j in range(left, right):
        if arr[j] <= pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1

    # Place pivot in its final sorted position
    arr[i], arr[right] = arr[right], arr[i]
    return i


def quickselect(arr, k, left, right):
    while left < right:
        p = partition(arr, left, right)
        if p == k:
            break
        elif k < p:
            right = p - 1
        else:
            left = p + 1
    return arr[k]


data = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]

for k in range(len(data)):
    result = quickselect(
        data[:], k, 0, len(data) - 1
    )  # pass a copy since arr is mutated
    print(f"k={k} → {result}")
