#!/usr/bin/env python
"""Generate a suitable set of data for the lecture 07 example
"""
import numpy as np
import sys
NUM_LINES = 50
NUM_FEATURES = 3

#print "%d" % NUM_FEATURES
for idx in range(1, NUM_LINES+1):
    features = np.random.normal(0.0, 0.1, (NUM_FEATURES,))
    for f in features:
        print "%0.8f" % f,
    print ""
