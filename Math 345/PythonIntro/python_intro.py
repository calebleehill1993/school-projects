# python_intro.py
"""Python Essentials: Introduction to Python.
<Caleb Hill>
<ACME????>
<2017/08/06>
"""

#Problem 1
if __name__ == "__main__":
	print("Hello, world!")

#Problem 2
sphere_volume = lambda r: 4/3 * 3.14159 * r**3
"""Calculates the volume of a sphere when given a specific r"""

if __name__ == "__main__":
    print(sphere_volume(10))

#Problem 3
def isolate(a, b, c, d, e):
    "Prints first three separated by 5 spaces, then prints the rest with a single space between each output"
    print(a, b, c, sep='     ', end=' ')
    print(d, e, sep=' ')

isolate(1, 2, 3, 4, 5)

#Problem 4
def first_half(a):
    """Returns the first half, excluding the middle character if odd number of characters"""
    return a[:len(a)//2]

def backward(a):
    """Returns a reversed string"""
    return a[::-1]

print(first_half('0123456789'))
print(backward("abcd"))

#Problem 5
def list_ops():
    """Adds eagle to the end, Replaces index 2 with 'fox', Removes entry at index 1, Sorts list in reverse alphabetical order, Replaces 'eagle' with 'hawk', Add 'hunter' to the last entry in the list"""
    a = ['bear', 'ant', 'cat', 'dog']
    a.append('eagle')
    if len(a) > 2:
        a[2] = 'fox'
    if len(a) > 1:
        a.pop(1)
    a.sort()
    a = a[::-1]
    if 'eagle' in a:
        a[a.index('eagle')] = 'hawk'
    a[len(a) - 1] = a[len(a) - 1] + 'hunter'
    return a
list_ops()

#Problem 6
def pig_latin(a):
    """Converts a word into pig latin. If first letter is a vowel (a, e, i, o, u), then it just adds 'hay' to the end. Otherwise, the first letter is moved to the end and 'ay' is added to the end."""
    if a[0] in 'aeiou':
        return a + 'hay'
    if a[0].isupper():
        b = a[0].lower()
        c = a[1].upper()
        return c + a[2:] + b + 'ay'
    return a[1:] + a[0] + 'ay'

print(pig_latin('home'))

#Problem 7
def palindrome():
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

print(palindrome())

#Problem 8
def alt_harmonic(n):
    """ """
    return sum([(-1)**(i+1) / i for i in range(1, n + 1)])

print(alt_harmonic(500000))
