# Volume 2 HW 1.10
"""Volume 2: Question 1.64
Caleb Hill
Math 320 - Sec. 002
9/23/2019
"""

# Problem 1.64
def max_unimodal(sequence, left=0, right=None):
    """Finds the maximal element xm in a unimodal sequence with temporal complexity O(log n)
    Parameters:
        sequence (list): unimodal sequence

    Returns:
        xm (int): maximal element of a sequence
    """
    if right is None:                                   #Checks for first time run of function
        right = len(sequence) - 1                       #Sets the right index as last index
    mp = (left + right) // 2                            #Sets the middle point to search for max
    if sequence[mp] > sequence[mp - 1]:                 #Checks if middle point is greater than index before
        if sequence[mp] > sequence[mp + 1]:             #Checks if mp is greater than index after
            return sequence[mp]                         #Since greater than both, it must be max
        return max_unimodal(sequence, mp + 1, right)    #Since less than next, set to right set and recurse
    return max_unimodal(sequence, left, mp - 1)         #Since less than previous, set to left set and recurse
