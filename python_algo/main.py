from push_swap import *
import random

##
# Data containers. Classes should be replaced with double linked enclosed list
##
from data_containers import *

total = []

amount = 0
# for i in range(10):
while amount < 700:
    commands_arr.clear()

    ##
    ## argv
    ##
    numbers_array = random.sample(range(-1000, 1000), 100)
    # numbers_array = [-289, 609, 564, -665, -795, 597, -81, -616, 910, 21]
    numbers_array_sorted = numbers_array.copy()
    numbers_array_sorted.sort()  # replace .sort method with merging sort

    ##
    ## Lists creation
    ##
    stack_A = Stack_A(numbers_array, numbers_array_sorted)
    stack_B = Stack_B(len(stack_A.arr))


    sort_(stack_A, stack_B)


    amount = len(commands_arr)
    # print(numbers_array)
    is_sort(stack_A)
    print(len(commands_arr))
