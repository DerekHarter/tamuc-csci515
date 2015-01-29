#!/usr/bin/env python
"""Generate a suitable set of data for the Lab 03 assignment.
"""
import numpy as np
NUM_LINES = 10

x, y, z = np.random.randn(3)
for idx in range(1, NUM_LINES+1):
    print idx, x, y, z
