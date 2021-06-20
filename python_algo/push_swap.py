from divide import *
from merge import *


def sort_(stack_A, stack_B):
    divide_(stack_A.arr, stack_A, stack_B)
    merge_(stack_A, stack_B)
    align_(stack_A, stack_B)
