from additional import *

REVERSE_ROTATE = -1
ROTATE = 1
NO_DIR = 3


def mark_greater_than(current_index, stack_arr):
    elem = stack_arr[current_index]
    stack_arr[current_index].keep = True
    ind = current_index + 1
    if ind > len(stack_arr) - 1:
        ind = 0
    while stack_arr[ind] != elem:
        if stack_arr[ind].order > stack_arr[current_index].order:
            stack_arr[ind].keep = True
            current_index = ind
        else:
            stack_arr[ind].keep = False
        ind += 1
        if ind > len(stack_arr) - 1:
            ind = 0


def find_nearest_false(to_look):
    nearest = len(to_look)
    rot_dir = NO_DIR
    for i in range(int(len(to_look) / 2)):
        if to_look[i].keep == False and i < nearest:
            nearest = i
            rot_dir = REVERSE_ROTATE
    for i in range(int(len(to_look) / 2), len(to_look)):
        if to_look[i].keep == False and len(to_look) - i < nearest:
            nearest = len(to_look) - i
            rot_dir = ROTATE
    return nearest, rot_dir


def mark_(arr_to_mark):
    last = len(arr_to_mark)
    for elem in arr_to_mark:
        if elem.order == last \
                or elem.order + 1 == last \
                or elem.order + 2 == last:
            elem.keep = True

def divide_(to_div_arr, stack_A, stack_B):
    mark_(stack_A.arr)
    while True:
        if not to_div_arr[0].keep:
            push_('b', stack_A, stack_B)
        else:
            nearest, rot_dir = find_nearest_false(to_div_arr)
            if rot_dir == ROTATE:
                while nearest > 0:
                    rotate_('a', stack_A, stack_B)
                    nearest -= 1
            elif rot_dir == REVERSE_ROTATE:
                while nearest > 0:
                    reverse_rotate_('a', stack_A, stack_B)
                    nearest -= 1

        if len(to_div_arr) <= 3:
            while True:
                # clear_keep(to_div_arr)
                for i in range(len(to_div_arr)):
                    mark_greater_than(i, to_div_arr)
                    if not no_keep_elem_count(to_div_arr):
                        break
                if not no_keep_elem_count(to_div_arr):
                    break
                else:
                    swap_('a', stack_A, stack_B, True)
            break
        elif not no_keep_elem_count(stack_A.arr):
            break
