# https://adventofcode.com/2021/day/21
# Day 21: Dirac Dice

from numpy import array, int64
from functools import lru_cache
from itertools import cycle

def dirac_dice(p1, p2):
    dice = cycle(range(1, 101))
    pos, score, turns = [p1, p2], [0, 0], 0
    while score[1 - turns % 2] < 1000:
        for _ in range(3):
            pos = advance(turns % 2, *pos, next(dice))
        score[turns % 2] += pos[turns % 2]
        turns += 1
    print(f'input: {[p1, p2]}')
    print(f'part1: {3 * turns * score[turns % 2]}')
    print(f'part2: {max(dp(0, p1, p2, 0, 0))}')
    print()

def advance(player, p1, p2, die):
    def adv(p): return 1 + (p + die - 1) % 10
    return [p1, adv(p2)] if player else [adv(p1), p2]

@lru_cache(None)
def dp(player, p1, p2, s1, s2):
    res = array([s1 > 20, s2 > 20], int64)
    if not any(res):
        for die, freq in (3,1), (4,3), (5,6), (6,7), (7,6), (8,3), (9,1):
            pos = array(advance(player, p1, p2, die))
            score = pos * [1 - player, player] + [s1, s2]
            res += freq * dp(1 - player, *pos, *score)
    return res

dirac_dice(4, 8)
dirac_dice(4, 7)
