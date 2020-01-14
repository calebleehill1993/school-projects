# matplotlib_intro.py
"""Python Essentials: Intro to Matplotlib.
Caleb Hill
Math 321 - Sec. 002
9/19/2019
"""
import numpy as np
from matplotlib import pyplot as plt

# Problem 1
def var_of_means(n):
    """Construct a random matrix A with values drawn from the standard normal
    distribution. Calculate the mean value of each row, then calculate the
    variance of these means. Return the variance.

    Parameters:
        n (int): The number of rows and columns in the matrix A.

    Returns:
        (float) The variance of the means of each row.
    """
    my_array = np.random.normal(size=(n, n))
    array_mean = np.mean(my_array, axis=1)
    return np.var(array_mean)
    raise NotImplementedError("Problem 1 Incomplete")

def prob1():
    """Create an array of the results of var_of_means() with inputs
    n = 100, 200, ..., 1000. Plot and show the resulting array.
    """
    my_array = []
    n_array = []
    for n in range(100, 1001, 100):
        n_array.append(n)
        my_array.append(var_of_means(n))
    plt.plot(n_array, my_array)
    plt.show()
    return
    raise NotImplementedError("Problem 1 Incomplete")


# Problem 2
def prob2():
    """Plot the functions sin(x), cos(x), and arctan(x) on the domain
    [-2pi, 2pi]. Make sure the domain is refined enough to produce a figure
    with good resolution.
    """
    x = np.linspace(-np.pi, np.pi, 100)
    plt.plot(x, np.sin(x))
    plt.plot(x, np.cos(x))
    plt.plot(x, np.arctan(x))
    plt.show()
    return
    raise NotImplementedError("Problem 2 Incomplete")


# Problem 3
def prob3():
    """Plot the curve f(x) = 1/(x-1) on the domain [-2,6].
        1. Split the domain so that the curve looks discontinuous.
        2. Plot both curves with a thick, dashed magenta line.
        3. Set the range of the x-axis to [-2,6] and the range of the
           y-axis to [-6,6].
    """
    x = np.linspace(-2, .999999, 100)
    plt.plot(x, 1/(x-1), 'm--', linewidth=4)
    x = np.linspace(1.000001, 6, 100)
    plt.plot(x, 1/(x-1), 'm--', linewidth=4)
    plt.xlim(-2, 6)
    plt.ylim(-6, 6)
    plt.show()
    return
    raise NotImplementedError("Problem 3 Incomplete")


# Problem 4
def prob4():
    """Plot the functions sin(x), sin(2x), 2sin(x), and 2sin(2x) on the
    domain [0, 2pi].
        1. Arrange the plots in a square grid of four subplots.
        2. Set the limits of each subplot to [0, 2pi]x[-2, 2].
        3. Give each subplot an appropriate title.
        4. Give the overall figure a title.
        5. Use the following line colors and styles.
              sin(x): green solid line.
             sin(2x): red dashed line.
             2sin(x): blue dashed line.
            2sin(2x): magenta dotted line.
    """
    x = np.linspace(0, 2 * np.pi, 100)
    ax1 = plt.subplot(2, 2, 1)
    ax1.plot(x, np.sin(x), 'g-')
    ax1.set_title("sin(x)")
    ax1.axis([0, 2 * np.pi, -2, 2])
    ax2 = plt.subplot(2, 2, 2)
    ax2.plot(x, np.sin(2 * x), 'r--')
    ax2.set_title("sin(2x)")
    ax2.axis([0, 2 * np.pi, -2, 2])
    ax3 = plt.subplot(2, 2, 3)
    ax3.plot(x, 2 * np.sin(x), 'b--')
    ax3.set_title("2sin(x)")
    ax3.axis([0, 2 * np.pi, -2, 2])
    ax4 = plt.subplot(2, 2, 4)
    ax4.plot(x, 2 * np.sin(2 * x), 'm:')
    ax4.set_title("2sin(2x)")
    ax4.axis([0, 2 * np.pi, -2, 2])
    plt.suptitle("Variations of sin(x)")
    plt.show()
    return
    raise NotImplementedError("Problem 4 Incomplete")


# Problem 5
def prob5():
    """Visualize the data in FARS.npy. Use np.load() to load the data, then
    create a single figure with two subplots:
        1. A scatter plot of longitudes against latitudes. Because of the
            large number of data points, use black pixel markers (use "k,"
            as the third argument to plt.plot()). Label both axes.
        2. A histogram of the hours of the day, with one bin per hour.
            Label and set the limits of the x-axis.
    """
    FARS = np.load("FARS.npy")
    ax1 = plt.subplot(1, 2, 1)
    ax1.plot(FARS[:, 1], FARS[:, 2], 'k*')
    plt.xlabel("Longitude")
    plt.ylabel("Latitude")
    plt.axis("equal")
    ax2 = plt.subplot(1, 2, 2)
    ax2.hist(FARS[:, 0], bins=np.arange(0, 25))
    plt.xlabel("Hour")
    plt.ylabel("Number of Accidents")
    plt.xlim(0, 24)
    plt.show()
    return
    raise NotImplementedError("Problem 5 Incomplete")


# Problem 6
def prob6():
    """Plot the function f(x,y) = sin(x)sin(y)/xy on the domain
    [-2pi, 2pi]x[-2pi, 2pi].
        1. Create 2 subplots: one with a heat map of f, and one with a contour
            map of f. Choose an appropriate number of level curves, or specify
            the curves yourself.
        2. Set the limits of each subplot to [-2pi, 2pi]x[-2pi, 2pi].
        3. Choose a non-default color scheme.
        4. Add a colorbar to each subplot.
    """
    x1 = np.linspace(-2 * np.pi, -0.000001, 100)
    y1 = x1.copy()
    x2 = np.linspace(0.000001,2 * np.pi, 100)
    y2 = x2.copy()
    X1, Y1 = np.meshgrid(x1, y1)
    X2, Y2 = np.meshgrid(x2, y2)
    Z1 = (np.sin(X1) * np.sin(Y1)) / (X1 * Y1)
    Z2 = (np.sin(X2) * np.sin(Y2)) / (X2 * Y2)
    plt.subplot(1, 2, 1)
    plt.pcolormesh(X1, Y1, Z1, cmap="viridis")
    plt.pcolormesh(X2, Y2, Z2, cmap="viridis")
    plt.colorbar()
    plt.xlim(-2 * np.pi, 2 * np.pi)
    plt.ylim(-2 * np.pi, 2 * np.pi)

    plt.subplot(1, 2, 2)
    plt.contour(X1, Y1, Z1, 10, cmap="coolwarm")
    plt.contour(X2, Y2, Z2, 10, cmap="coolwarm")
    plt.colorbar()
    plt.xlim(-2 * np.pi, 2 * np.pi)
    plt.ylim(-2 * np.pi, 2 * np.pi)

    plt.show()
    return
    raise NotImplementedError("Problem 6 Incomplete")
