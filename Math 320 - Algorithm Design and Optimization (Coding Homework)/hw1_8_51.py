# Volume 2 HW 1.8
"""Volume 2: Question 1.51
Caleb Hill
Math 320 - Sec. 002
9/18/2019
"""
# No imports!


# Problem 1.51
def euclid(a, b):
    """Euclidean method for finding the greatest common divisor
    of two numbers. Accept a, b and return gcd(a,b) as well as
    x,y where ax+by=gcd(a,b).
    Important- you will not receive any points if you import ANY
    libraries, code or functions!

    Parameters:
        a (int): Integer used in Euclid's algorithm.
        b (int): Integer used in Euclid's algorithm.

    Returns:
        gcd (int): Greatest common divisor of a and b.
        x (int): Integer x such that ax+by=gcd(a,b).
        y (int): Integer y such that ax+by=gcd(a,b).
    """
    def egcd(a, b):
        if a == 0:
            return (b, 0, 1)
        else:
            gcd, x, y = egcd(b % a, a)
            return (gcd, y - (b // a) * x, x)

    #Make sure a is the larger of the two numbers
    if b > a:
    	temp = b
    	b = a
    	a = temp
    return egcd(a, b)



    pass
