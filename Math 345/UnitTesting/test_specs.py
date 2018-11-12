# test_specs.py
"""Python Essentials: Unit Testing.
<Caleb Hill>
<Math 345>
<2018/10/09>
"""

import specs
import pytest


def test_add():
    assert specs.add(1, 3) == 4, "failed on positive integers"
    assert specs.add(-5, -7) == -12, "failed on negative integers"
    assert specs.add(-6, 14) == 8
    assert specs.add(2, 2) == 4

def test_divide():
    assert specs.divide(4,2) == 2, "integer division"
    assert specs.divide(5,4) == 1.25, "float division"
    with pytest.raises(ZeroDivisionError) as excinfo:
        specs.divide(4, 0)
    assert excinfo.value.args[0] == "second input cannot be zero"


# Problem 1: write a unit test for specs.smallest_factor(), then correct it.
def test_smallest_factor():
    assert specs.smallest_factor(25) == 5, "failed when only prime factor is the square root"
    assert specs.smallest_factor(24) == 2
    assert specs.smallest_factor(9) == 3
    assert specs.smallest_factor(3) == 3

# Problem 2: write a unit test for specs.month_length().
def test_month_length():
    assert specs.month_length("September") == 30
    assert specs.month_length("January") == 31
    assert specs.month_length("February") == 28
    assert specs.month_length("February", True) == 29
    assert specs.month_length("Hello") == None

# Problem 3: write a unit test for specs.operate().
def test_operate():
    with pytest.raises(TypeError) as excinfo:
        specs.operate(1, 2, 3)
    assert excinfo.value.args[0] == "oper must be a string"
    assert specs.operate(1, 2, '+') == 3
    assert specs.operate(1, 2, '-') == -1
    assert specs.operate(1, 2, '*') == 2
    assert specs.operate(1, 2, '/') == .5
    with pytest.raises(ZeroDivisionError) as excinfo:
        specs.operate(1, 0, '/')
    assert excinfo.value.args[0] == "division by zero is undefined"
    with pytest.raises(ValueError) as excinfo:
        specs.operate(1, 2, '&')
    assert excinfo.value.args[0] == "oper must be one of '+', '/', '-', or '*'"

# Problem 4: write unit tests for specs.Fraction, then correct it.
@pytest.fixture
def set_up_fractions():
    frac_1_3 = specs.Fraction(1, 3)
    frac_1_2 = specs.Fraction(1, 2)
    frac_n2_3 = specs.Fraction(-2, 3)
    return frac_1_3, frac_1_2, frac_n2_3

def test_fraction_init(set_up_fractions):
    frac_1_3, frac_1_2, frac_n2_3 = set_up_fractions
    assert frac_1_3.numer == 1
    assert frac_1_2.denom == 2
    assert frac_n2_3.numer == -2
    frac = specs.Fraction(30, 42)
    assert frac.numer == 5
    assert frac.denom == 7
    with pytest.raises(ZeroDivisionError) as excinfo:
        specs.Fraction(1, 0)
    assert excinfo.value.args[0] == "denominator cannot be zero"
    with pytest.raises(TypeError) as excinfo:
        specs.Fraction(1, "HELLO")
    assert excinfo.value.args[0] == "numerator and denominator must be integers"


def test_fraction_str(set_up_fractions):
    frac_1_3, frac_1_2, frac_n2_3 = set_up_fractions
    assert str(frac_1_3) == "1/3"
    assert str(frac_1_2) == "1/2"
    assert str(frac_n2_3) == "-2/3"
    frac = specs.Fraction(15, 3)
    assert str(frac) == "5"
    frac0 = specs.Fraction(0, 500)
    assert str(frac0) == "0"

def test_fraction_float(set_up_fractions):
    frac_1_3, frac_1_2, frac_n2_3 = set_up_fractions
    assert float(frac_1_3) == 1 / 3.
    assert float(frac_1_2) == .5
    assert float(frac_n2_3) == -2 / 3.

def test_fraction_eq(set_up_fractions):
    frac_1_3, frac_1_2, frac_n2_3 = set_up_fractions
    assert frac_1_2 == specs.Fraction(1, 2)
    assert frac_1_3 == specs.Fraction(2, 6)
    assert frac_n2_3 == specs.Fraction(8, -12)
    assert frac_1_2 == .5

def test_fraction_add(set_up_fractions):
    frac_1_3, frac_1_2, frac_n2_3 = set_up_fractions
    assert frac_1_2 + frac_1_3 == 5 / 6

def test_fraction_sub(set_up_fractions):
    frac_1_3, frac_1_2, frac_n2_3 = set_up_fractions
    assert frac_1_2 - frac_1_3 == 1 / 6

def test_fraction_mul(set_up_fractions):
    frac_1_3, frac_1_2, frac_n2_3 = set_up_fractions
    assert frac_1_2 * frac_1_3 == 1 / 6

def test_fraction_truediv(set_up_fractions):
    frac_1_3, frac_1_2, frac_n2_3 = set_up_fractions
    assert frac_1_2 / frac_1_3 == 3 / 2
    with pytest.raises(ZeroDivisionError) as excinfo:
        frac_1_2 / specs.Fraction(0, 1)
    assert excinfo.value.args[0] == "cannot divide by zero"



# Problem 5: Write test cases for Set.
