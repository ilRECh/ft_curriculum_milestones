from additional import *

REVERSE_ROTATE = -1
ROTATE = 1
NO_DIR = 3
UP = 1
DOWN = -1


def index_check(index, place, stack_A):
    stack_A_rot_needed = 0
    rot_dir_A = NO_DIR
    if place == DOWN:
        if index + 1 <= len(stack_A.arr) / 2:
            stack_A_rot_needed = index + 1
            rot_dir_A = REVERSE_ROTATE if index + 1 != 0 else NO_DIR
        else:
            stack_A_rot_needed = len(stack_A.arr) - index - 1
            rot_dir_A = ROTATE
    else:
        if index <= len(stack_A.arr) / 2:
            stack_A_rot_needed = index
            rot_dir_A = REVERSE_ROTATE if index != 0 else NO_DIR
        else:
            stack_A_rot_needed = len(stack_A.arr) - index
            rot_dir_A = ROTATE
    return stack_A_rot_needed, rot_dir_A


def prepare_merge_(stack_A, stack_B):
    total_B = len(stack_B.arr)
    total_rot_dir_B = NO_DIR
    total_A = len(stack_A.arr)
    total_rot_dir_A = NO_DIR
    for elem in stack_B.arr:
        current_index = stack_B.arr.index(elem)
        max_stack_B_rot_needed = len(stack_B.arr)
        actual_rot_dir_B = NO_DIR
        stack_B_rot_needed = 0
        rot_dir_B = NO_DIR
        if current_index <= int(len(stack_B.arr) / 2):
            stack_B_rot_needed = current_index
            rot_dir_B = REVERSE_ROTATE if current_index != 0 else NO_DIR
        else:
            stack_B_rot_needed = len(stack_B.arr) - current_index
            rot_dir_B = ROTATE
        if stack_B_rot_needed < max_stack_B_rot_needed:
            max_stack_B_rot_needed = stack_B_rot_needed
            actual_rot_dir_B = rot_dir_B
        max_stack_A_rot_needed = len(stack_A.arr)
        actual_rot_dir_A = NO_DIR
        stack_A_rot_needed = 0
        rot_dir_A = NO_DIR
        smaller, bigger = find_smaller_and_bigger(elem.order, stack_A.arr)
        if smaller >= 0:
            stack_A_rot_needed, rot_dir_A = index_check(smaller, DOWN, stack_A)
            if stack_A_rot_needed < max_stack_A_rot_needed:
                max_stack_A_rot_needed = stack_A_rot_needed
                actual_rot_dir_A = rot_dir_A
        else:
            stack_A_rot_needed, rot_dir_A = index_check(bigger, UP, stack_A)
            if stack_A_rot_needed < max_stack_A_rot_needed:
                max_stack_A_rot_needed = stack_A_rot_needed
                actual_rot_dir_A = rot_dir_A
        # print(total_B + total_A > max_stack_B_rot_needed + max_stack_A_rot_needed,
        #       total_A, total_B, max_stack_A_rot_needed, max_stack_B_rot_needed,
        #       actual_rot_dir_A, actual_rot_dir_B)
        if actual_rot_dir_B == actual_rot_dir_A \
                and actual_rot_dir_B != NO_DIR \
                and total_A + total_B > (max_stack_B_rot_needed
                if (max_stack_B_rot_needed >= max_stack_A_rot_needed) else max_stack_A_rot_needed) \
            or total_B + total_A > max_stack_B_rot_needed + max_stack_A_rot_needed:
            total_B = max_stack_B_rot_needed
            total_rot_dir_B = actual_rot_dir_B
            total_A = max_stack_A_rot_needed
            total_rot_dir_A = actual_rot_dir_A
    return total_rot_dir_A, total_rot_dir_B, total_A, total_B


def merge__(total_rot_dir_A, total_rot_dir_B, total_A, total_B, stack_A, stack_B, to_push):
    while total_B > 0 and total_rot_dir_B != NO_DIR:
        if total_rot_dir_A == total_rot_dir_B and total_A > 0 and total_rot_dir_A != NO_DIR:
            if total_rot_dir_B == ROTATE:
                total_A -= 1
                total_B -= 1
                rotate_('&', stack_A, stack_B)
            elif total_rot_dir_B == REVERSE_ROTATE:
                total_A -= 1
                total_B -= 1
                reverse_rotate_('&', stack_A, stack_B)
        elif total_rot_dir_B == ROTATE:
            total_B -= 1
            rotate_('b', stack_A, stack_B)
        elif total_rot_dir_B == REVERSE_ROTATE:
            total_B -= 1
            reverse_rotate_('b', stack_A, stack_B)
    while total_A > 0 and total_rot_dir_A != NO_DIR:
        if total_rot_dir_A == ROTATE:
            total_A -= 1
            rotate_('a', stack_A, stack_B)
        elif total_rot_dir_A == REVERSE_ROTATE:
            total_A -= 1
            reverse_rotate_('a', stack_A, stack_B)
    push_(to_push, stack_A, stack_B)


def merge_(stack_A, stack_B):
    while len(stack_B.arr) != 0:
        total_rot_dir_A, total_rot_dir_B, total_A, total_B = prepare_merge_(stack_A, stack_B)
        merge__(total_rot_dir_A, total_rot_dir_B, total_A, total_B, stack_A, stack_B, 'a')
