#!/usr/bin/env python
"""Generate a suitable set of data for the Assg 03 out of class assignment.
"""
import numpy as np
import sys
NUM_LINES = 100
CLASSES = ['UP', 'DOWN', 'STRANGE', 'CHARM']
CHOSEN_CLASS = 'STRANGE'

x_prev, y_prev, z_prev = np.random.normal(0.0, 5.0, (3,))
for trial in range(1, NUM_LINES+1):
    trial_class = np.random.choice(CLASSES)

    if trial_class == CHOSEN_CLASS:
        x_d, y_d, z_d = np.random.normal(0.0, 0.25, (3,))
        x = x_prev + x_d
        y = y_prev + y_d
        z = z_prev + z_d
    else:
        x, y, z = np.random.normal(0.0, 5.0, (3,))

    print "%03d\t%8.5f\t%8.5f\t%8.5f\t%-s" % (trial, x, y, z, trial_class)

    if trial_class == CHOSEN_CLASS:
        x_prev, y_prev, z_prev = x, y, z
