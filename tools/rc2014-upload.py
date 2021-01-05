#!/bin/python3

import sys
import time

with open(sys.argv[1] ) as f:
    for l in f:
        for c in l:
            if c != '\n' and c != '\r':
                sys.stdout.write(c)
                sys.stdout.flush()

                sys.stderr.write(c)
                sys.stderr.flush()
                time.sleep(0.001)

        sys.stdout.write("\n")
        sys.stdout.flush()

        sys.stderr.write("\n")
        sys.stderr.flush()
        time.sleep(0.01)
