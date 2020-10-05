import sys
import math

boost_usado = False


while True:
    x, y, next_checkpoint_x, next_checkpoint_y, \
            next_checkpoint_dist, next_checkpoint_angle = \
            [int(i) for i in input().split()]
    opponent_x, opponent_y = [int(i) for i in input().split()]

    if next_checkpoint_angle > 90 or next_checkpoint_angle < -90:
        empuje = 0
    elif next_checkpoint_dist < 100:
        empuje = 50
    elif not boost_usado and next_checkpoint_dist >= 300:
        empuje = "BOOST"
        boost_usado = True
    else:
        empuje = 100

    print(str(next_checkpoint_x) + " " + str(next_checkpoint_y) + " " + str(empuje))
