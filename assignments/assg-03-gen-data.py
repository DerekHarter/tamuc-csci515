#!/usr/bin/env python
"""Generate a suitable set of data for the Assg 03 out of class assignment.
"""
import numpy as np
import sys
NUM_LINES = 50
CLASSES = ['UP', 'DOWN', 'STRANGE', 'CHARM']
CHOSEN_CLASS = 'STRANGE'

x_prev, y_prev, z_prev = np.random.normal(0.0, 5.0, (3,))
for trial in range(1, NUM_LINES+1):
    trial_class = np.random.choice(CLASSES)

    print "%03d\t%5s" % (trial, trial_class)

# for idx in range(1, NUM_LINES+1):
#     features = np.random.normal(0.0, 5.0, (NUM_FEATURES,))
#     for f in features:
#         prec = np.random.randint(3, 10, size=(1,))
#         width = prec + np.random.randint(2, 5, size=(1,))
#         fmt = "%%%d.%df\t" % (width, prec)
#         sys.stdout.write(fmt % f)
#     sys.stdout.write("\n")
