# Volume 2 HW 1.1
"""Volume 2: Question 1.6i
Caleb Hill
Math 320 - Sec 002
9/5/2019
"""


# Problem 1.6i
def subtraction(a, b):
    """Subtract b from a (a-b) using the "elementary school algorithm" for
    subtraction. You may assume a>=b.

    Parameters:
        a (list): List of single-digit integers.
        b (list): List of single-digit integers.

    Returns:
        c (int): a-b, computed using "elementary school algorithm".
    """
    delta = len(a)-len(b) #We get the difference in the lengths
    b = delta * [0] + b #We add the difference in length to b (the small number)

    carry = 0 #This keeps track of any time a[i] is smaller than b[i]
    i = len(a) - 1 #This starts us in the ones column

    while i >= 0: #Loops through all numbers
        #Does the single digit subtraction and subtracts 1 if the last
        #digit was less than 0.
        a[i] = a[i] - b[i] + carry
        carry = a[i] // 10 #determines if last digit was <0
        a[i] = a[i] % 10 #Brings the digit back to positive mod 10
        i -= 1 #set for next digit

    return a
    pass
