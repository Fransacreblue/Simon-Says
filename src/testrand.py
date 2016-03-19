#!/bin/env python

seed = 0
period = 0
while(True):
    seed = ((seed * 137) + 59) & 0xFF
    print(str(seed >> 6))
    period += 1
    if(seed == 0):
        break
print("Period is " + str(period))
