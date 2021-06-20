##
## array with allowed and needed commands
##
commands_arr = []


def swap_(stack, stack_A, stack_B, pre_swap):
    if stack == '&' and len(stack_B.arr) > 1 and len(stack_A.arr) > 1:
        temp = stack_A.arr[1]
        stack_A.arr[1] = stack_A.arr[0]
        stack_A.arr[0] = temp
        temp = stack_B.arr[1]
        stack_B.arr[1] = stack_B.arr[0]
        stack_B.arr[0] = temp
        if pre_swap:
            commands_arr.append("ss")
        return
    if stack == 'a' and len(stack_A.arr) > 1:
        temp = stack_A.arr[1]
        stack_A.arr[1] = stack_A.arr[0]
        stack_A.arr[0] = temp
        if pre_swap:
            commands_arr.append("sa")
    elif stack == 'b' and len(stack_B.arr) > 1:
        temp = stack_B.arr[1]
        stack_B.arr[1] = stack_B.arr[0]
        stack_B.arr[0] = temp
        if pre_swap:
            commands_arr.append("sb")


def push_(stack, stack_A, stack_B):
    if stack == 'a' and len(stack_B.arr) != 0:
        stack_A.arr.insert(0, stack_B.arr.pop(0))
        commands_arr.append("pa")
    elif stack == 'b' and len(stack_A.arr) != 0:
        stack_B.arr.insert(0, stack_A.arr.pop(0))
        commands_arr.append("pb")


def reverse_rotate_(stack, stack_A, stack_B):
    if stack == 'a' and len(stack_A.arr) > 1:
        stack_A.arr.append(stack_A.arr.pop(0))
        commands_arr.append("rra")
    elif stack == 'b' and len(stack_B.arr) > 1:
        stack_B.arr.append(stack_B.arr.pop(0))
        commands_arr.append("rrb")
    elif stack == '&' and len(stack_A.arr) > 1 and len(stack_B.arr) > 1:
        stack_A.arr.append(stack_A.arr.pop(0))
        stack_B.arr.append(stack_B.arr.pop(0))
        commands_arr.append("rrr")


def rotate_(stack, stack_A, stack_B):
    if stack == 'a' and len(stack_A.arr) > 1:
        stack_A.arr.insert(0, stack_A.arr.pop(len(stack_A.arr) - 1))
        commands_arr.append("ra")
    elif stack == 'b' and len(stack_B.arr) > 1:
        stack_B.arr.insert(0, stack_B.arr.pop(len(stack_B.arr) - 1))
        commands_arr.append("rb")
    elif stack == '&' and len(stack_A.arr) > 1 and len(stack_B.arr) > 1:
        stack_A.arr.insert(0, stack_A.arr.pop(len(stack_A.arr) - 1))
        stack_B.arr.insert(0, stack_B.arr.pop(len(stack_B.arr) - 1))
        commands_arr.append("rr")


def align_(stack_A, stack_B):
    index_of_min = len(stack_A.arr) + 1
    if len(stack_A.arr) > 0:
        min_order = stack_A.arr[0].order
        for elem in stack_A.arr:
            if elem.order < min_order:
                index_of_min = stack_A.arr.index(elem)
                min_order = elem.order

    index_of_max = len(stack_B.arr) + 1
    if len(stack_B.arr) > 0:
        max_order = stack_B.arr[0].order
        for elem in stack_B.arr:
            if elem.order > max_order:
                index_of_max = stack_B.arr.index(elem)
                max_order = elem.order

    if index_of_min <= len(stack_A.arr) / 2:
        if len(stack_B.arr) > 0 \
                and index_of_max <= len(stack_B.arr) / 2:
            while stack_A.arr[0].order != min_order \
                    and stack_B.arr[0].order != max_order:
                reverse_rotate_('&', stack_A, stack_B)
        while stack_A.arr[0].order != min_order:
            reverse_rotate_('a', stack_A, stack_B)
    else:
        if len(stack_B.arr) > 0 \
                and index_of_max > len(stack_B.arr) / 2:
            while stack_A.arr[0].order != min_order \
                    and stack_B.arr[0].order != max_order:
                rotate_('&', stack_A, stack_B)
        while stack_A.arr[0].order != min_order:
            rotate_('a', stack_A, stack_B)
