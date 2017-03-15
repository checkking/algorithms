#!/bin/env python
# -*- coding: utf-8 -*

"""
file: line_sample.py
"""
import os
import sys
import random

def usage():
    print "Usage: %s file ratio\nnote: ratio is (0, 1)" % (sys.argv[0])
    os._exit(0)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        usage()
    ratio = float(sys.argv[2])
    if not (ratio > 0 and ratio < 1):
        usage()

    fh = open(sys.argv[1], 'r')
    for line in fh:
        rand_val = random.random()
        if rand_val < ratio:
            print line.strip('\n')
