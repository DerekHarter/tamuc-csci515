#!/usr/bin/env python
"""Generate a suitable set of data for the Lab 03 assignment.
"""
import numpy as np
NUM_LINES = 10
NUM_FEATURES = 5

print "%d" % NUM_FEATURES
for idx in range(1, NUM_LINES+1):
    features = np.random.normal(0.0, 5.0, (NUM_FEATURES,))
    for f in features:
        print "%f\t" % f,
    print ""
