# object_oriented.py
"""Python Essentials: Object Oriented Programming.
<Caleb Hill>
<Math 321>
<2018/09/18>
"""

from math import sqrt

class Backpack:
    """A Backpack object class. Has a name and a list of contents and a color.
    Takes items in to backpack if not full. Also, able to dump the bag to empty
    all the contents.

    Attributes:
        name (str): the name of the backpack's owner.
        contents (list): the contents of the backpack.
        color (str): color of the backpackself.
        max_size (int): The max number of items in the backpack. (Default: 5)
    """

    # Problem 1: Modify __init__() and put(), and write dump().
    def __init__(self, name, color, max_size=5):
        """Set the name and initialize an empty list of contents.

        Parameters:
            name (str): the name of the backpack's owner.
            color (str): the color of the backpack.
        """
        self.name = name
        self.contents = []
        self.color = color
        self.max_size = max_size

    def put(self, item):
        """Add an item to the backpack's list of contents. If the number of
        items in the backpack are equal to the max size (5), the item will not
        be added."""
        if len(self.contents) < self.max_size:
            self.contents.append(item)
        else:
            print("No Room!")

    def take(self, item):
        """Remove an item from the backpack's list of contents."""
        self.contents.remove(item)

    def dump(self):
        """Empties all the items contained in the backpack's list."""
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

    def  __eq__(self, other):
        """Compare two backpacks. If 'self' has the same name, color, and
        number of contents, return true, else, return false."""
        return self.name == other.name and self.color == other.color and\
        len(self.contents) == len(other.contents)

    def __str__(self):
        """returns a str for a backpack as follows:

            Owner:      <name>
            Color:      <color>
            Size:       <number of items in contents>
            Max Size:   <max_size>
            Contents:   [<item1>, <item2>, ...]"""
        return "Owner:\t\t" + self.name + "\nColor:\t\t" + self.color +\
        "\nSize:\t\t" + str(len(self.contents)) + "\nMax Size:\t" + str(self.max_size)\
        + "\nContents:\t" + str(self.contents)

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
    def __init__(self, name, color, max_size=3):
        """Use the Backpack constructor to initialize the name, color,
        and max_size attributes. A knapsack only holds 3 item by default.

        Parameters:
            name (str): the name of the knapsack's owner.
            color (str): the color of the knapsack.
            max_size (int): the maximum number of items that can fit inside.
        """
        Backpack.__init__(self, name, color, max_size)
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
    """The Jetpack is a Backpack that has a size of 2 and uses fuel to fly.
    This class inherits from the Backpack class. Fuel is required for flight.

    Attributes:
        name (str): the name of the jetpack's owner.
        color (str): the color of the jetpack.
        max_size (int): the maximum number of items that can fit inside.
        contents (list): the contents of the backpack.
        fuel (int): used (and needed) when the fly function is used.
    """
    def __init__(self, name, color, max_size=2, fuel=10):
        """Use the Jetpack constructor to initialize the name, color,
        max_size and fuel attributes. A jetpack only holds 2 item by default. A
        jetpack holds 10 fuel by default.

        Parameters:
            name (str): the name of the jetpack's owner.
            color (str): the color of the jetpack.
            max_size (int): the maximum number of items that can fit inside.
            fuel (int): the maxium fuel. Fuel is required to fly.
        """
        Backpack.__init__(self, name, color, max_size)
        self.fuel = fuel

    def fly(self, ammount):
        """Uses fuel to fly with the jetpack

        Parameters:
            fuel (float): The ammount of fuel to use to fly. This must be less or
            equal to the ammount of fuel the jetpack has left."""
        if ammount <= self.fuel:
            self.fuel -= ammount
        else:
            print("Not enough fuel!")

    def dump(self):
        """Empties all the items and fuel from the jetpack."""
        Backpack.dump(self)
        self.fuel = 0

# Problem 4: Write a 'ComplexNumber' class.
class ComplexNumber:
    """A class that holds both the real part and imaginary parts of a complex number.
    It can print, find the magnitude, find the compliment, compare to other ComplexNumber
    objects, add, subtract, multiply, and divide. It is comparable to the complex() class."""
    def __init__(self, real, imag):
        """initializes a ComplexNumber object with two parameters.

        Parameters:
            real (float): holds the real part
            imag (float): holds the imaginary part.
        """
        self.real = real
        self.imag = imag

    def conjugate(self):
        """The complex conjugate of a+bi is defined as a + bi (with a bar above) = a−bi.
        Returns another ComplexNumber object."""
        return ComplexNumber(self.real, -self.imag)

#Magic Methods
    def __str__(self):
        """a + bi is printed out as (a+bj) for b ≥ 0 and (a-bj)
        for b < 0."""
        if self.imag >= 0:
            return "(" + str(self.real) + "+" + str(self.imag) + "j)"
        return "(" + str(self.real) + str(self.imag) + "j)"

    def __abs__(self):
        """The magnitude of a + bi is |a + bi| = sqrt(a**2 + b**2) . Used with the
        abs() function."""
        return sqrt(self.real**2 + self.imag**2)

    def __eq__(self, other):
        """Compares to ComplexNumber objects with ==. Returns true if both the real and
        imaginary parts are the same. Else, false."""
        if self.real == other.real and self.imag == other.imag:
            return True
        return False

    def __add__(self, other):
        """Returns a ComplexNumber object of two complex numbers added."""
        return ComplexNumber(self.real + other.real, self.imag + other.imag)

    def __sub__(self, other):
        """Returns a ComplexNumber object where the second is subtracted from the first."""
        return ComplexNumber(self.real - other.real, self.imag - other.imag)

    def __mul__(self, other):
        """Returns a ComplexNumber object of two complex numbers multiplied."""
        return ComplexNumber(self.real * other.real - self.imag * other.imag, \
        self.real * other.imag + self.imag * other.real)

    def __truediv__(self, other):
        """Returns a ComplexNumber object where the first is divided by the second."""
        a = other.real**2 + other.imag**2
        return ComplexNumber((self.real * other.real + self.imag * other.imag) / a,\
        (self.imag * other.real - self.real * other.imag) / a)



def test_backpack():
    testpack = Backpack("Barry", "black")
    if testpack.name != "Barry":
        print("Backpack.name assigned incorrectly")
    for item in ["pencil", "pen", "paper", "computer"]:
        testpack.put(item)
    print("Contents:", testpack.contents)

def test_ComplexNumber(a, b):
    py_cnum, my_cnum = complex(a, b), ComplexNumber(a, b)
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
    if abs(py_cnum) != abs(my_cnum):
        print("__abs__() failed for", py_cnum)
    #Validate __eq__().
    if my_cnum != my_cnum or my_cnum == ComplexNumber(py_cnum.real + 1, py_cnum.imag):
        print("__eq__() failed for", py_cnum)
    #Validate __add__().
    myTest1 = py_cnum + py_cnum
    myTest2 = my_cnum + my_cnum
    if myTest1.real != myTest2.real or myTest1.imag != myTest2.imag:
        print("__add__() failed for", py_cnum)
    #Validate __sub__().
    myTest1 = py_cnum - py_cnum
    myTest2 = my_cnum - my_cnum
    if myTest1.real != myTest2.real or myTest1.imag != myTest2.imag:
        print("__sub__() failed for", py_cnum)
    #Validate __mul__().
    myTest1 = py_cnum * py_cnum
    myTest2 = my_cnum * my_cnum
    if myTest1.real != myTest2.real or myTest1.imag != myTest2.imag:
        print("__mul__() failed for", py_cnum)
    #Validate __truediv__().
    myTest1 = py_cnum / py_cnum
    myTest2 = my_cnum / my_cnum
    if myTest1.real != myTest2.real or myTest1.imag != myTest2.imag:
        print("__truediv__() failed for", py_cnum)
