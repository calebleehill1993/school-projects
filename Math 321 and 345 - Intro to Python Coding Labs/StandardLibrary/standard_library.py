# standard_library.py
"""Python Essentials: The Standard Library.
Caleb Hill
Math 344 - Sec 002
09/10/2019
"""
import calculator
import itertools
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
    i = 1
    s = "string"
    l = ['l', 'i', 's', 't']
    t = ('t', 'u', 'p', 'l', 'e')
    se = {'s', 'e', 't'}

    i2 = i
    s2 = s
    l2 = l
    t2 = t
    se2 = se

    i2 += 1
    s2 += '2'
    l2 += '2'
    t2 += ('t', 'u', 'p', 'l', 'e') + (2,)
    se2.add('2')

    print("int is mutable: " + str(i == i2))
    print("str is mutable: " + str(s == s2))
    print("list is mutable: " + str(l == l2))
    print("tuple is mutable: " + str(t == t2))
    print("set is mutable: " + str(se == se2))

    return

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

    return calculator.sqrt(calculator.sum(calculator.product(a, a), calculator.product(b, b)))

    raise NotImplementedError("Problem 3 Incomplete")


# Problem 4
def power_set(A):
    """Use itertools to compute the power set of A.

    Parameters:
        A (iterable): a str, list, set, tuple, or other iterable collection.

    Returns:
        (list(sets)): The power set of A as a list of sets.
    """

    L = list()
    for i in range(len(A) + 1):
        L.extend([set(j) for j in itertools.combinations(A, i)])
    return L

    raise NotImplementedError("Problem 4 Incomplete")


# Problem 5: Implement shut the box.
def shut_the_box(player, timelimit):
    """Play a single game of shut the box."""
    TheBox = list(range(1, 10))
    start = time.time()
    while len(TheBox) > 0 and (float(timelimit) - time.time() + start) > 0:
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
            print("Seconds left: " + str(float(timelimit)))
            start = time.time()
        else:
            print("Seconds left: " + str(round((float(timelimit) - time.time() + start), 2)))
        PlayerInput = input("Numbers to eliminate: ")
        removeable = box.parse_input(PlayerInput, TheBox)
        while removeable == [] or sum(removeable) != dice:
            print("Invalid input\n")
            if (float(timelimit) - time.time() + start) <= 0:
                break
            print("Seconds left: " + str(round((float(timelimit) - time.time() + start), 2)))
            PlayerInput = input("Numbers to eliminate: ")
            removeable = box.parse_input(PlayerInput, TheBox)
        if (float(timelimit) - time.time() + start) <= 0:
            break
        removeable = box.parse_input(PlayerInput, TheBox)
        for i in removeable:
            TheBox.remove(i)
        print("")
    if len(TheBox) > 0:
        print('Game Over!\n')
        print('Score for player ' + player + ': ' + str(sum(TheBox)) + ' points')
        print('Time played: ' + str(round((time.time() - start), 2)) + ' seconds')
        print('Better luck next time >:)')
    else:
        print('Score for player ' + player + ': ' + str(sum(TheBox)) + ' points')
        print('Time played: ' + str(round((time.time() - start), 2)) + ' seconds')
        print('Congratulations!! You shut the box!')

#To Start "Shut the Box"
if __name__ == "__main__":
    if len(sys.argv) == 3:
        shut_the_box(sys.argv[1], sys.argv[2])
