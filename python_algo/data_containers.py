class Lst_elem:
    def __init__(self, value, order):
        self.value = value
        self.order = order
        self.keep = False


class Stack_A:
    global Lst_elem

    def __init__(self, num_array, num_array_sorted):
        self.arr = []
        for num_elem in num_array:
            self.arr.append(
                Lst_elem(num_elem, num_array_sorted.index(num_elem) + 1))  # replace .index method with binary search


class Stack_B:
    global lst_elem

    def __init__(self, len):
        self.arr = [] * len
