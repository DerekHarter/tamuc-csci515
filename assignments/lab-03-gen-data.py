#!/usr/bin/env python
"""Generate a suitable set of data for the Lab 03 assignment.
"""
import numpy as np
NUM_LINES = 10

x, y, z = np.random.randn(3)
for idx in range(1, NUM_LINES+1):
    print "%d\t%f\t%f\t%f" % (idx, x, y, z)
    x += np.random.randn(1, 0.0, 0.25)
    y += np.random.randn(1, 0.0, 0.25)
    z += np.random.randn(1, 0.0, 0.25)
