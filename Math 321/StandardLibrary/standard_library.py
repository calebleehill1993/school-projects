# standard_library.py
"""Python Essentials: The Standard Library.
<Caleb Hill>
<Math 321>
<2018/09/12>
"""
import calculator
from itertools import combinations, chain
import sys
import box
import random
import time


# Problem 1
def prob1(L):
    """Return the minimum, maximum, and average of the entries of L
    (in that order).
    """
    return min(L), max(L), sum(L)/len(L)
    raise NotImplementedError("Problem 1 Incomplete")


# Problem 2
def prob2():
    """Determine which Python objects are mutable and which are immutable.
    Test numbers, strings, lists, tuples, and sets. Print your results.
    """
    def prob2a(B):
        """If true, returns 'mutable', else, returns 'immutable'."""
        if B:
            return "mutable"
        return "immutable"
    int1 = 1
    int2 = int1
    int2 += 1
    int = int1 == int2
    str1 = "HI"
    str2 = str1
    str2 = "HI!"
    str = str1 == str2
    list1 = [1, 2]
    list2 = list1
    list2[0] = 2
    list = list1 == list2
    tuple1 = (1, 2)
    tuple2 = tuple1
    tuple2 = (2, 2)
    tuple = tuple1 == tuple2
    set1 = {1, 2}
    set2 = set1
    set2.add(3)
    set = set1 == set2
    final = 'int is ' + prob2a(int) \
        + '; str is ' + prob2a(str) \
        + '; list is ' + prob2a(list) \
        + '; tuple is ' + prob2a(tuple) \
        + '; set is ' + prob2a(set)
    print(final)
    return final
    raise NotImplementedError("Problem 2 Incomplete")


# Problem 3
def hypot(a, b):
    """Calculate and return the length of the hypotenuse of a right triangle.
    Do not use any functions other than those that are imported from your
    'calculator' module.

    Parameters:
        a: the length one of the sides of the triangle.
        b: the length the other non-hypotenuse side of the triangle.
    Returns:
        The length of the triangle's hypotenuse.
    """
    a = calculator.product(a, a)
    b = calculator.product(b, b)
    a = calculator.sum(a, b)
    return calculator.sqrt(a)
    raise NotImplementedError("Problem 3 Incomplete")


# Problem 4
def power_set(A):
    """Use itertools to compute the power set of A.

    Parameters:
        A (iterable): a str, list, set, tuple, or other iterable collection.

    Returns:
        (list(sets)): The power set of A as a list of sets.
    """
    PowerSet = []
    for i in range(len(A) + 1):
        PowerSet.extend([set(j) for j in combinations(A, i)])
    return PowerSet
    raise NotImplementedError("Problem 4 Incomplete")


# Problem 5: Implement shut the box.
def ShutTheBox():
    "An Old Pub British Game"
    TheBox = list(range(1, 10))
    start = time.time()
    while len(TheBox) > 0 and (float(sys.argv[2]) - time.time() + start) > 0:
        a = random.randint(1, 6)
        b = random.randint(1, 6)
        if sum(TheBox) < 7:
            dice = a
        else:
            dice = a + b
        if box.isvalid(dice, TheBox) == False:
            break
        print("Numbers left: " + str(TheBox))
        print("Roll: " + str(dice))
        if len(TheBox) == 9:
            print("Seconds left: " + str(float(sys.argv[2])))
            start = time.time()
        else:
            print("Seconds left: " + str(round((float(sys.argv[2]) - time.time() + start), 2)))
        PlayerInput = input("Numbers to eliminate: ")
        removeable = box.parse_input(PlayerInput, TheBox)
        while removeable == [] or sum(removeable) != dice:
            print("Invalid input\n")
            if (float(sys.argv[2]) - time.time() + start) <= 0:
                break
            print("Seconds left: " + str(round((float(sys.argv[2]) - time.time() + start), 2)))
            PlayerInput = input("Numbers to eliminate: ")
            removeable = box.parse_input(PlayerInput, TheBox)
        if (float(sys.argv[2]) - time.time() + start) <= 0:
            break
        removeable = box.parse_input(PlayerInput, TheBox)
        for i in removeable:
            TheBox.remove(i)
        print("")
    if len(TheBox) > 0:
        print('Game Over!\n')
        print('Score for player ' + sys.argv[1] + ': ' + str(sum(TheBox)) + ' points')
        print('Time played: ' + str(round((time.time() - start), 2)) + ' seconds')
        print('Better luck next time >:)')
    else:
        print('Score for player ' + sys.argv[1] + ': ' + str(sum(TheBox)) + ' points')
        print('Time played: ' + str(round((time.time() - start), 2)) + ' seconds')
        print('Congratulations!! You shut the box!')

#To Start "Shut the Box"
if __name__ == "__main__":
    if len(sys.argv) == 3:
        print("Welcome to Shut the Box, " + sys.argv[1] + '!')
        ShutTheBox()
