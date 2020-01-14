# Volume 2 HW 1.2
"""Volume 2: Question 1.13i & 14.ii
Caleb Hill
Math 320 - Sec 002
9/7/2019
"""


# Problem 1.13i
def smallest_element_index(L):
    """Find the index of the smallest element in a list L of length n using only primitive 	operations.

    Parameters:
        L (list)

	Returns:
        index (int)
    """
    i = 1 #This will be the iterator
    smallest_index = 0 #Sets the index of the smallest to 0 to start
    length = len(L) #sets how long the while loop should go

    while i < length: #itorates though all elements comparing them to smallest
        if L[smallest_index] > L[i]:
            smallest_index = i
        i += 1
    return smallest_index
    pass


# Problem 1.14ii
def selection_sort(L):
    """Given a list L of length n, first find the smallest element and swap it
        with the element L[0]. Then find the second smallest element of L and swap it
        with the element L[1], and so forth for the first n-1 elements of the list.

    Parameters:
        L (list)

    Returns:
        sorted_list (list)
    """
    i = 0
    length = len(L) - 1 #length without counting the last element

    while i < length: #itorates through all but the last element
        temp = L[i] #to hold a value to swap
        smallest_index = smallest_element_index(L[i:]) + i #obtains smallest element excluding previous
                                                           #smallest values
        L[i] = L[smallest_index] #swapping
        L[smallest_index] = temp
        i += 1
    return L
    pass
