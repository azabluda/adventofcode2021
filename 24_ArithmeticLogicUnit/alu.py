# https://adventofcode.com/2021/day/24
# Day 24: Arithmetic Logic Unit

from itertools import *

A = [ 1,  1,  1,  26,  1, 26,  1,  1, 26,  1, 26,  26, 26,  26]
B = [12, 10, 13, -11, 13, -1, 10, 11,  0, 10, -5, -16, -7, -11]
C = [ 6,  6,  3,  11,  9,  3, 13,  6, 14, 10, 12,  10, 11,  15]

CAP = 26 ** max(accumulate(a // 13 - 1 for a in A[::-1]))

for W in range(1, 10), range(9, 0, -1):
    Z = {0: []}
    for a, b, c in zip(A, B, C):
        def nextz(w, z):
            n = z // a
            if z % 26 + b == w: return n
            return n * 26 + c + w
        X = ([*wz, nextz(*wz)] for wz in product(W, Z))
        Z = {n: Z[z] + [w] for w, z, n in X if n < CAP}
    print(Z[0])
