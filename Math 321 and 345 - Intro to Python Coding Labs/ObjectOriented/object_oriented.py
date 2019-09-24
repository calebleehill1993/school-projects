# object_oriented.py
"""Python Essentials: Object Oriented Programming.
Caleb Hill
Math 321 - Sec. 002
9/16/2019
"""
import random
from math import sqrt

class Backpack:
    """A Backpack object class. Has a name and a list of contents.

    Attributes:
        name (str): the name of the backpack's owner.
        contents (list): the contents of the backpack.
    """

    # Problem 1: Modify __init__() and put(), and write dump().
    def __init__(self, name, color, max_size=5):
        """Set the name and initialize an empty list of contents.

        Parameters:
            name (str): the name of the backpack's owner.
            color (str): the color of the backpack.
            max_size (int): The max number of items in backpack. Default: 5
        """
        self.name = name
        self.contents = []
        self.color = color
        self.max_size = max_size

    def put(self, item):
        """Add an item to the backpack's list of contents if less than max_size."""
        if len(self.contents) < self.max_size:
            self.contents.append(item)
        else:
            print("No Room!")

    def take(self, item):
        """Remove an item from the backpack's list of contents."""
        self.contents.remove(item)

    def dump(self):
        """Removes all items from the backpack"""
        self.contents = []

    # Magic Methods -----------------------------------------------------------

    # Problem 3: Write __eq__() and __str__().
    def __add__(self, other):
        """Add the number of contents of each Backpack."""
        return len(self.contents) + len(other.contents)

    def __lt__(self, other):
        """Compare two backpacks. If 'self' has fewer contents
        than 'other', return True. Otherwise, return False.
        """
        return len(self.contents) < len(other.contents)

    def __eq__(self, other):
        """Two Backpacks are equal if they have the same name, color, and number
        of contents.
        """
        if (self.name == other.name) and (self.color == other.color) and \
            (len(self.contents) == len(other.contents)):
            return True
        return False

    def __str__(self):
        """Returns a string with the information about the Backpack as such:

        Owner:      <name>
        Color:      <color>
        Size:       <number of items in contents>
        max Size:   <max_size>
        Contents:   [<item1>, <item2>, ...]
        """

        return "Owner:\t\t" + self.name + \
            "\nColor:\t\t" + self.color + \
            "\nSize:\t\t" + str(len(self.contents)) + \
            "\nMax Size:\t" + str(self.max_size) + \
            "\nContents:\t" + str(self.contents)

#A Test function for backpack
def test_backpack():
    testpack = Backpack("Barry", "black")           # Instantiate the object.
    if testpack.name != "Barry":                    # Test an attribute.
        print("Backpack.name assigned incorrectly")
    for item in ["pencil", "pen", "paper", "computer"]:
        testpack.put(item)                          # Test a method.
    print("Contents:", testpack.contents)
    for item in ["dog", "journal"]:
        testpack.put(item)
    print("Contents:", testpack.contents)
    testpack.dump()
    print("Contents:", testpack.contents)

# An example of inheritance. You are not required to modify this class.
class Knapsack(Backpack):
    """A Knapsack object class. Inherits from the Backpack class.
    A knapsack is smaller than a backpack and can be tied closed.

    Attributes:
        name (str): the name of the knapsack's owner.
        color (str): the color of the knapsack.
        max_size (int): the maximum number of items that can fit inside.
        contents (list): the contents of the backpack.
        closed (bool): whether or not the knapsack is tied shut.
    """
    def __init__(self, name, color):
        """Use the Backpack constructor to initialize the name, color,
        and max_size attributes. A knapsack only holds 3 item by default.

        Parameters:
            name (str): the name of the knapsack's owner.
            color (str): the color of the knapsack.
            max_size (int): the maximum number of items that can fit inside.
        """
        Backpack.__init__(self, name, color, max_size=3)
        self.closed = True

    def put(self, item):
        """If the knapsack is untied, use the Backpack.put() method."""
        if self.closed:
            print("I'm closed!")
        else:
            Backpack.put(self, item)

    def take(self, item):
        """If the knapsack is untied, use the Backpack.take() method."""
        if self.closed:
            print("I'm closed!")
        else:
            Backpack.take(self, item)

    def weight(self):
        """Calculate the weight of the knapsack by counting the length of the
        string representations of each item in the contents list.
        """
        return sum(len(str(item)) for item in self.contents)


# Problem 2: Write a 'Jetpack' class that inherits from the 'Backpack' class.
class Jetpack(Backpack):
    """A Jetpack is a subclass of Backpack.

    Attributes:
        name (str): the name of the jetpack's owner.
        color (str): the color of the jetpack.
        max_size (int): the maximum number of items that can fit inside.
        contents (list): the contents of the jetpack.
        fuel (int): The ammount of fuel in the jetpack to fly.
    """
    def __init__(self, name, color, max_size=2, fuel=10):
        """initialize the jetpack class.

        Parameters:
            name (str): the name of the jetpack's owner.
            color (str): the color of the jetpack.
            max_size (int): the maximum number of items that can fit inside. Default = 2
            fuel (int): The ammount of fuel in the jetpack to fly. Default = 10
        """
        Backpack.__init__(self, name, color, max_size=3)
        self.fuel = fuel

    def fly(self, fuel):
        """Flies the jetpack using fuel. If not enough, it won't fly.

        Parameters:
            fuel (int): The ammount of fuel to use flying the jetpack.
        """
        if fuel > self.fuel:
            print("Not enough fuel!")
        else:
            self.fuel -= fuel

    def dump(self):
        """Dumps all contents and fuel from jetpack."""
        Backpack.dump(self)
        self.fuel = 0

# Problem 4: Write a 'ComplexNumber' class.
class ComplexNumber:
    """A Complex Number has both a real and imaginary part written as a + bi.

    Attributes:
        real (float): the real part.
        imag (float): the imaginary part.
    """

    def __init__(self, real, imag):
        """This initializes the ComplexNumber with real and imaginary parts.

        Parameters:
        real (float): the real part.
        imag (float): the imaginary part.
        """
        self.real = real
        self.imag = imag

    def conjugate(self):
        """Returns the complex conjugate such that a + bi gives a - bi."""
        return ComplexNumber(self.real, - self.imag)

    def __str__(self):
        """a + bi is printed out as (a+bj) for b ≥ 0 and (a-bj) for b < 0"""
        if self.imag < 0:
            return "(" + str(self.real) + str(self.imag) + "j)"
        return "(" + str(self.real) + "+" + str(self.imag) + "j)"

    def __abs__(self):
        """Takes the squareroot of a^2 + b^2."""
        return sqrt(self.real**2 + self.imag**2)


    def __eq__(self, other):
        """If two Complex Numbers have both the same real and imaginary parts, they are the same."""
        if (self.real == other.real) and (self.imag == other.imag):
            return True
        return False

    def __add__(self, other):
        """For a + bi + c + di, we return (a+c) + (b+d)i"""
        return ComplexNumber(self.real + other.real, self.imag + other.imag)

    def __sub__(self, other):
        """For a + bi - c + di, we return (a-c) + (b-d)i"""
        return ComplexNumber(self.real - other.real, self.imag - other.imag)
    def __mul__(self, other):
        """For a + bi * c + di, we return (ac - bd) + (ad + bc)i"""
        return ComplexNumber(self.real * other.real - self.imag * other.imag,
            self.real * other.imag + self.imag * other.real)

    def __truediv__(self, other):
        """Divids to ComplexNumbers and returns and ComplexNumber."""
        conj = other.conjugate()
        a = self * conj
        b = other * conj
        return ComplexNumber(a.real / b.real, a.imag / b.real)

def test_ComplexNumber(a, b):
    """Tests all the functions of ComplexNumber and compares them to python complex numbers.
    If all the tests work, nothing happens. Else, you see the error.
    """
    py_cnum, my_cnum = complex(a, b), ComplexNumber(a, b)
    c = random.randint(-100, 101)
    d = random.randint(-100, 101)
    py_cnum2, my_cnum2 = complex(c, d), ComplexNumber(c, d)

    # Creating new complex objects to test operations
    my_add = my_cnum + my_cnum2
    py_add = py_cnum + py_cnum2
    my_sub = my_cnum - my_cnum2
    py_sub = py_cnum - py_cnum2
    my_mul = my_cnum * my_cnum2
    py_mul = py_cnum * py_cnum2
    my_div = my_cnum / my_cnum2
    py_div = py_cnum / py_cnum2

    # Validate the constructor.
    if my_cnum.real != a or my_cnum.imag != b:
        print("__init__() set self.real and self.imag incorrectly")
    # Validate conjugate() by checking the new number's imag attribute.
    if py_cnum.conjugate().imag != my_cnum.conjugate().imag:
        print("conjugate() failed for", py_cnum)
    # Validate __str__().
    if str(py_cnum) != str(my_cnum):
        print("__str__() failed for", py_cnum)
    # Validate __abs__().
    if abs(my_cnum) != abs(py_cnum):
        print("__abs__() failed for", py_cnum)
    # Validate __eq__().
    if my_cnum != my_cnum:
        print("conjugate() failed for", py_cnum)
    # Validate __add__().
    if my_add.real != py_add.real or my_add.imag != py_add.imag:
        print("__add__() failed for", py_cnum)
    # Validate __sub__().
    if my_sub.real != py_sub.real or my_sub.imag != py_sub.imag:
        print("__sub__() failed for", py_cnum)
    # Validate __mul__().
    if my_mul.real != py_mul.real or my_mul.imag != py_mul.imag:
        print("__mul__() failed for", py_cnum)
    # Validate __truediv__().
    if my_div.real != py_div.real or my_div.imag != py_div.imag:
        print("__div__() failed for", py_cnum)
    return
