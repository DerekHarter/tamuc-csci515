#!/usr/bin/env python
"""Generate a suitable set of data for the Lab 03 assignment.
"""
import numpy as np
NUM_LINES = 10

x, y, z = np.random.normal(0.0, 2.0, (3,))
for idx in range(1, NUM_LINES+1):
    print "%d\t%f\t%f\t%f" % (idx, x, y, z)
    xd, yd, zd = np.random.normal(0.0, 0.25, (3,))
    print xd, yd, zd
    x += xd
    y += yd
    z += zd
