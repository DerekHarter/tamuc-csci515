#!/usr/bin/env python
"""Generate a suitable set of data for the lecture 07 example
"""
import numpy as np
import sys
NUM_LINES = 50
NUM_FEATURES = 3

#print "%d" % NUM_FEATURES
x,y,z = np.random.normal(0.0, 1.0, (NUM_FEATURES,))
for idx in range(1, NUM_LINES+1):
    xd,yd,zd = np.random.normal(0.0, 0.05, (NUM_FEATURES,))
    x += xd
    y += yd
    z += zd
    print "%12.8f %12.8f %12.8f" % (x, y, z)

