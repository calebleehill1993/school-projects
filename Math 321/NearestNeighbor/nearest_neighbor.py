# nearest_neighbor.py
"""Volume 2: Nearest Neighbor Search.
<Caleb Hill>
<Math 321>
<2018/10/24>
"""

import numpy as np
from scipy import linalg as la


# Problem 1
def exhaustive_search(X, z):
    """Solve the nearest neighbor search problem with an exhaustive search.

    Parameters:
        X ((m,k) ndarray): a training set of m k-dimensional points.
        z ((k, ) ndarray): a k-dimensional target point.

    Returns:
        ((k,) ndarray) the element (row) of X that is nearest to z.
        (float) The Euclidean distance from the nearest neighbor to z.
    """
    Y = la.norm(X - z, axis=1)
    distance = min(Y)
    index = np.where(Y==distance)
    return A[index], distance
    raise NotImplementedError("Problem 1 Incomplete")

# Problem 2: Write a KDTNode class.
class KDTNode:
    """

    """
    def __init__(self, x):
        if type(x) is not np.ndarray:
            raise TypeError(str(x) + " is not of type np.ndarray.")
        self.value = x
        self.left = None
        self.right = None
        self.pivot = None

# Problems 3 and 4
class KDT:
    """A k-dimensional binary tree for solving the nearest neighbor problem.

    Attributes:
        root (KDTNode): the root node of the tree. Like all other nodes in
            the tree, the root has a NumPy array of shape (k,) as its value.
        k (int): the dimension of the data in the tree.
    """
    def __init__(self):
        """Initialize the root and k attributes."""
        self.root = None
        self.k = None

    def find(self, data):
        """Return the node containing the data. If there is no such node in
        the tree, or if the tree is empty, raise a ValueError.
        """
        def _step(current):
            """Recursively step through the tree until finding the node
            containing the data. If there is no such node, raise a ValueError.
            """
            if current is None:                     # Base case 1: dead end.
                raise ValueError(str(data) + " is not in the tree")
            elif np.allclose(data, current.value):
                return current                      # Base case 2: data found!
            elif data[current.pivot] < current.value[current.pivot]:
                return _step(current.left)          # Recursively search left.
            else:
                return _step(current.right)         # Recursively search right.

        # Start the recursive search at the root of the tree.
        return _step(self.root)

    # Problem 3
    def insert(self, data):
        """Insert a new node containing the specified data.

        Parameters:
            data ((k,) ndarray): a k-dimensional point to insert into the tree.

        Raises:
            ValueError: if data does not have the same dimensions as other
                values in the tree.
        """
        def _step(current):
            """Recursively step through the tree until finding the node
            containing the data. If there is no such node, raise a ValueError.
            """
            if np.allclose(data, current.value):
                raise ValueError("This is a duplicate.")
            elif data[current.pivot] < current.value[current.pivot]:
                if current.left == None:
                    current.left = KDTNode(data)
                    current.left.pivot = (current.pivot + 1) % self.k # Sets new pivot
                    return
                return _step(current.left)          # Recursively search left.
            else:
                if current.right == None:
                    current.right = KDTNode(data)
                    current.right.pivot = (current.pivot + 1) % self.k # Sets new pivot
                    return
                return _step(current.right)         # Recursively search right.
            return
        if type(data) is not np.ndarray:
            raise TypeError(str(data) + " is not of type np.ndarray.")
        if self.root == None:
            self.root = KDTNode(data)
            self.root.pivot = 0
            self.k = len(data)
        elif len(data) != self.k:
            raise ValueError("Size of data(" + str(len(data)) + ") doesn't equal k(" + str(self.k) + ")")
        else:
            _step(self.root)
        return
        raise NotImplementedError("Problem 3 Incomplete")


    # Problem 4
    def query(self, z):
        """Find the value in the tree that is nearest to z.

        Parameters:
            z ((k,) ndarray): a k-dimensional target point.

        Returns:
            ((k,) ndarray) the value in the tree that is nearest to z.
            (float) The Euclidean distance from the nearest neighbor to z.
        """
        raise NotImplementedError("Problem 4 Incomplete")

    def __str__(self):
        """String representation: a hierarchical list of nodes and their axes.

        Example:                           'KDT(k=2)
                    [5,5]                   [5 5]   pivot = 0
                    /   \                   [3 2]   pivot = 1
                [3,2]   [8,4]               [8 4]   pivot = 1
                    \       \               [2 6]   pivot = 0
                    [2,6]   [7,5]           [7 5]   pivot = 0'
        """
        if self.root is None:
            return "Empty KDT"
        nodes, strs = [self.root], []
        while nodes:
            current = nodes.pop(0)
            strs.append("{}\tpivot = {}".format(current.value, current.pivot))
            for child in [current.left, current.right]:
                if child:
                    nodes.append(child)
        return "KDT(k={})\n".format(self.k) + "\n".join(strs)


# Problem 5: Write a KNeighborsClassifier class.


# Problem 6
def prob6(n_neighbors, filename="mnist_subset.npz"):
    """Extract the data from the given file. Load a KNeighborsClassifier with
    the training data and the corresponding labels. Use the classifier to
    predict labels for the test data. Return the classification accuracy, the
    percentage of predictions that match the test labels.

    Parameters:
        n_neighbors (int): the number of neighbors to use for classification.
        filename (str): the name of the data file. Should be an npz file with
            keys 'X_train', 'y_train', 'X_test', and 'y_test'.

    Returns:
        (float): the classification accuracy.
    """
    raise NotImplementedError("Problem 6 Incomplete")

# x = np.array([3, 4, 7])
# y = np.array([7, 6, 2])
# z = np.array([1, 3, 5])
# bad = np.array([4, 5])
# bad2 = "hlo"
