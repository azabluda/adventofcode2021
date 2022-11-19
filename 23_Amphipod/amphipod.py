# https://adventofcode.com/2021/day/23
# Day 23: Amphipod

from bisect import *
from heapq import *

def amphipod(cfg: list[str]):

    print(cfg)
    rpos = [p for p, a in enumerate(cfg) if a] # room positions
    hpos = [p for p, a in enumerate(cfg) if not a] # hallway positions
    rlen = len(cfg[rpos[0]]) # size of room
    a2i = lambda a: ord(a) - ord('A') # amphipod letter -> 0..3
    
    def good_room(p):
        y = 'ABCD'[p // 2 - 1]
        return all(x == y for x in cfg[p])

    def perfect_room(p):
        return len(cfg[p]) == rlen and good_room(p)

    # Dijkstra
    seen = set()
    pq = [(0, cfg)]
    while True:
        cost, cfg = heappop(pq)
        if all(map(perfect_room, rpos)): break
        if tuple(cfg) in seen: continue
        seen.add(tuple(cfg))

        busy = [-1] + [p for p in hpos if cfg[p]] + [len(cfg)]
        def free_range(p):
            i = bisect_right(busy, p)
            return busy[i - 1] + 1, busy[i]
        
        def move(p, q):
            new = cfg[:]
            new[q] += new[p][-1]
            new[p] = new[p][:-1]
            steps = abs(p - q) + rlen - len([cfg[q], new[p]][p in rpos])
            heappush(pq, (cost + steps * 10 ** a2i(new[q][0]), new))
        
        for p, a in enumerate(cfg):
            if p in rpos: # from room to hallway
                if good_room(p): continue
                for q in range(*free_range(p)):
                    if q in rpos: continue
                    move(p, q)
            elif a: # from hallway to room
                q = rpos[a2i(a)] # dest room position
                p1, p2 = free_range(q)
                if p1 - 1 <= p <= p2 and good_room(q):
                    move(p, q)
    print(cost)
    print()

[
    *map(
        amphipod,
        [
            ['', '', 'AB',   '', 'DC',   '', 'CB',   '', 'AD',   '', ''],
            ['', '', 'CD',   '', 'CA',   '', 'BA',   '', 'BD',   '', ''],
            ['', '', 'ADDB', '', 'DBCC', '', 'CABB', '', 'ACAD', '', ''],
            ['', '', 'CDDD', '', 'CBCA', '', 'BABA', '', 'BCAD', '', ''],
        ]
    )
]
