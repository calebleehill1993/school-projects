# Volume 2 HW 1.5
"""Volume 2: Question 1.26 & 27
Caleb Hill
Math 320 - Sec. 002
9/14/2019
"""

from time import time
import numpy as np

"""The basic code for timing a function:

    start = time()
    <execute function/algorithm>
    end = time()
    computation_time = end - start

"""


# Problem 1.26
# Write code here to answer the questions at the end of the problem.
# Answer those questions on the paper you are turning in.
print("Problem 1.26")
for k in range(1, 12):
    A = np.random.rand(k**2, k**2)
    B = np.random.rand(k**2, k**2)
    x = np.random.rand(k**2, 1)

    #Made to make sure everything looked okay
    # print("A")
    # print(A)
    # print("B")
    # print(B)
    # print("x")
    # print(x)
    start = time()
    C = (A @ B) @ x
    end = time()
    computation_time1 = end - start

    start = time()
    D = A @ (B @ x)
    end = time()
    computation_time2 = end - start

    #Made to make sure C = D
    # print("C")
    # print(C)
    # print("D")
    # print(D)

    print("k = " + str(k) + "   (AB)x is: " + str(computation_time1) + "   A(Bx) is: " +
    str(computation_time2) + "   (AB)x / A(Bx): " + str(computation_time1/computation_time2))




# Problem 1.27
# Write code here.
# Answer the questions in part (iii) on the paper you are turning in.
print("\nProblem 1.27")
for n in range(1, 12):
    I = np.identity(2**n)
    u = np.random.rand(2**n, 1)
    v = np.random.rand(2**n, 1)
    x = np.random.rand(2**n, 1)
    vt = v.T

    start = time()
    C = (I + (u @ vt)) @ x
    end = time()
    computation_time1 = end - start

    start = time()
    D = x + (u @ (vt @ x))
    end = time()
    computation_time2 = end - start

    #Made to make sure C = D
    # print("C")
    # print(C)
    # print("D")
    # print(D)

    print("n = " + str(n) + "   (I + uv^T)x is: " + str(computation_time1) + "   x + u(v^Tx) is: " +
    str(computation_time2) + "   (I + uv^T)x / x + u(v^Tx): " + str(computation_time1/computation_time2))
