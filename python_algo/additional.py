import itertools
from actions import *


def print_stacks(stack_A, stack_B):
    print("\t\tStack A:\t|\t\tStack_B:")
    print("\tORD:\t\tFL:\t|\tORD:\t\tFL:")
    for elem_A, elem_B in itertools.zip_longest(stack_A.arr, stack_B.arr):
        print("\t",
              elem_A.order if elem_A is not None else "  ", "\t\t",
              elem_A.keep if elem_A is not None else "  ", "\t|\t",
              elem_B.order if elem_B is not None else "  ", "\t",
              elem_B.keep if elem_B is not None else "  ")


def is_sort(stack_):
    for i in range(1, len(stack_.arr)):
        if stack_.arr[i - 1].value > stack_.arr[i].value:
            print("NO", end=' ')
            return False
    print("YES", end=' ')
    return True


# searches for elem with the nearest smaller order and the nearest bigger order
def find_smaller_and_bigger(order, stack_arr):
    smaller = order - 1
    bigger = order + 1
    index_bigger = -1
    index_smaller = -1
    if len(stack_arr) > 1:
        while index_smaller < 0 and index_bigger < 0:
            for elem in stack_arr:
                if elem.order == smaller:
                    index_smaller = stack_arr.index(elem)
                elif elem.order == bigger:
                    index_bigger = stack_arr.index(elem)
            if index_bigger < 0:
                bigger += 1
            if index_smaller < 0:
                smaller -= 1
    return index_smaller, index_bigger


# sets all obj.keep to False
def clear_keep(stack_arr):
    for elem in stack_arr:
        elem.keep = False


# counts all obj.keep that equal to True
def keep_elem_count(stack_arr):
    keep_elem_amount = 0
    for elem in stack_arr:
        if elem.keep:
            keep_elem_amount += 1
    return keep_elem_amount


# counts all obj.keep that equal to False
def no_keep_elem_count(stack_arr):
    nk_elem_amount = 0
    for elem in stack_arr:
        if not elem.keep:
            nk_elem_amount += 1
    return nk_elem_amount
