# python_intro.py
"""Python Essentials: Introduction to Python.
Caleb Hill
Math 321 - Sec 002
9/5/2019
"""
if __name__ == "__main__":
    print("Hello, world!")

def sphere_volume(r):
    """Returns the volume of a sphere with radius r as input."""
    return (4/3) * 3.14159 * r**3

def isolate(a, b, c, d, e):
    """Prints first three arguments separated by 5 spaces and the rest
    with a single space between."""
    print(a, b, c, sep="     ", end=" ")
    print(d, e)

def first_half(a):
    """returns the first half of a string"""
    return a[:len(a)//2]

def backward(a):
    """returns string backwards"""
    return a[-1::-1]

def list_ops():
    """This creates a list containing bear, ant, cat, dog. Then alters
    the list by appending eagle, changing index 2 to fox, popping index
    1, sorting backwards, changing eagle to hawk, then appending hunterself.
    The final list should be ["fox", "hawk", "dog", "bearhunter"]."""
    L = ["bear", "ant", "cat", "dog"]
    L.append("eagle")
    L[2] = "fox"
    L.pop(1)
    L.sort()
    L = L[::-1]
    L[L.index("eagle")] = "hawk"
    L[-1] = L[-1] + "hunter"
    return L

def pig_latin(a):
    if a[0] in {'a', 'e', 'i', 'o', 'u'}:
        a = a + "hay"
    else:
        a = a[1:] + a[0] + "ay"
    return a

def palindrome():
    """Finds and returns the largest palindromic number made from the product of two 3-digit numbers."""
    c = 0
    d = ''
    e = 0
    f = 0
    g = 0
    for a in range(100, 1000):
        for b in range(100, 1000):
            c = a * b
            d = str(c)
            if d == d[::-1] and c > e:
                e = c
                f = a
                g = b
    return e

def alt_harmonic(i):
    """Returns the alternating harmonic series to the nth term"""
    return sum([((-1)**(n + 1)) / n for n in range(1, i + 1)])
