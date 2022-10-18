# https://adventofcode.com/2021/day/20
# Day 20: Trench Map

def trench_map(data):
    from itertools import chain, product
    alg, img = data.split('\n\n')
    alg = [a == '#' for a in alg]
    img = img.split('\n')
    img = {(r, c) for r, row in enumerate(img)
                  for c, val in enumerate(row)
                  if val == '#'}
    for i in range(50):
        nei1D = lambda x: [x - 1, x, x + 1]
        nei2D = lambda pt: product(*map(nei1D, pt))
        alter = lambda step: not alg[0] or step % 2;
        check = lambda res, step: int(res == alter(step))
        img_bit = lambda pt: str(check(pt in img, i - 1))
        bits_of = lambda pt: map(img_bit, nei2D(pt))
        get_pos = lambda pt: int(''.join(bits_of(pt)), 2)
        resolve = lambda pt: check(alg[get_pos(pt)], i)
        ext = set(chain(*map(nei2D, img)))
        img = set(filter(resolve, ext))
        print(f'after step {i + 1}: {len(img)}')
    print()

_ = [trench_map(s) for s in
[   
"""..#.#..#####.#.#.#.###.##.....###.##.#..###.####..#####..#....#..#..##..###..######.###...####..#..#####..##..#.#####...##.#.#..#.##..#.#......#.###.######.###.####...#.##.##..#..#..#####.....#.#....###..#.##......#.....#..#..#..##..#...##.######.####.####.#.#...#.......#..#.#.#...####.##.#......#..#...##.#.##..#...##.#.##..###.#......#.#.......#.#.#.####.###.##...#.....####.#..#..#.##.#....##..#.####....##...##..#...#......#.#.......#.......##..####..#...#.#.#...##..#.#..###..#####........#..####......#..#

#..#.
#....
##..#
..#..
..###""",

"""###..#...#..##.######.###.##.#####.#.....###..##..####.##...##..##.#......##.###....#.##.##.##..#..#..#.#..#.#.#.###..##.##....###..#..#...#.#....##...#...###.###..#..#.####...#..##.#...#..####.#.#####.......#..###.#...#..###.#.######....#...#..#..##.....#.#...#.####.#####....####..#.##..#.#.#.#.#...#.#.##..##...#.#.#.##.##.#.####.#....#..#.##.#.##.###.#.###.###..#....#####.#..#.###.#####.#..#.#..#.#.##.#..#.###.##..##.#....##..#...#.#.####....#.##.#.#.......###..#...#..##.#####.#...####..#.##.###.###......

.######..##.#..#.#..#####..#.##..#.....####.#...#.##.#...#..##...#..###..#..#.######...##....#####.#
.#.#....#.###..#.#.#.##..#.#......###...###....##.##.##...##.#.....#...#..#.#....###.#.##..##....###
###..####.#...###...#.##.########.#..#####.#.#.#....#..######.#.##...#....#..######..######.#.#.##.#
#.###.#.##..#.#...###..##..#.#..#....#..###..#.##...##...##..#.......##..##.##..##.#.#...##...##..##
#.#....#.#.###..#....##.#.#...#..#.#.....####.#.##..#.#.##.....######.#...##...#..#.#.##..#...####..
....#..##.##..##.######...##..#..###.#.#..#..####.#...###..##.#...##...####.#...##...#.#.###.#...#..
..#.####.###...#..#..#####.##.#..##..##.#.#...#...#.#####..###...#.##.#..#..####....#....#.#.###..#.
.##.#.#####.###..##.###.###.#..####...####.###...##.##.########.##.####.....###..#..##....##...#.###
###.#.#.#.....#.#..##....#...####.#.#..#.###.######.##.###.##.#.##.#.##.#.#.#.#.##...###.####.#..#..
#.#....###..#....#..####.......#.##..#.#..###......###.##..#....#.##....#.######.#.......##.#.#.#..#
###.#######...#.#.....##...###...#...##.#..##.##..##..##.##......####.#.###.##..####..##....#..##.##
..#.#...##..####..#.#..#.##....##......##.##..##.#.#.##...##....#..###.#####.#.#..##.##...##..####.#
#.##..#.###.#.#.##.###..#..#..#.#..#...#.....#....##.....#..###.##.#.#...#....##..#..#..#..##..###.#
#..#...##.#........#.....##.#..#.###########...#...###..#...#...#.#........#.#.#..#.....#.##.#...###
...#.#.###...##..####..####.###...#.#..#.######.####....###.#.#...#..#.#....##...#....##.#.##.#..###
.##....#.##.#.#.#...####.####......#.#.###..#..###..#.###.#...#...##...##...###.############..#..##.
#..#.##...##.###########..####.#.###.....###.#....##.#.####..#..####.#.#...........#.#...###.###..##
......##..#...######...######..#...##.#......#..##...#.....##.#####....#.#.#..####.#.##..#...#..##.#
##.#..#########.....#.###.##.###..##.#.##.#..##.#..#...####..###.####...##......##.......###.###...#
#.##.....#.##.#..#.#..#.##.##...#...######.##.#.###..##.#.#.#.###..##.##...###.#......###.#.#.....##
...##.###..#.##......##.###.#.##.#....#####.#...###...###.##.#.##.#.#.#..#####..###..#.#........##.#
....#.####.###...##.....#.#.#.....#.#..#.......#..##.#....#.##.####...#..##########...#.##...#.#####
#.####..#...##.....#....##..###..###..###.#.#..#..##.#.#.#..#..#.#..#...#.#..#.#.....###....##.#.#..
##.###.###...##..############..#..##.###..#..##..##..####.#########.####.##.###.#....#...##..#.##...
###..#.##.#.#.###.##...##.##.#...#.#..###.###.########..#...###.##...#..#..##.....#.##..#..##..###..
#.###..#...#.#####.##...#.##....########..#....#....##.##....#..##.#..#.#.##..##.#...#.##....##....#
##.#..####....####.##...##....##..##.#......#..####..#...#..##.....#.#..##...##.#.##.#.###.##.####..
#...#....#.###..###...##.#..#####..#.#..##.##.#..######..#.#.....##.#.########.##.##.##...#####.##..
#.#.##...##...##.######.#####.#.#.#.###..####.#.#..##.....#.##.#..#.#.##..####.#...####.###.#.##.###
###..##..####.#......#####.########.#.#.#.#..####.....#.##.#.###..###.###.##.##.##..##.##..#####..#.
.#.#..##..#..#..##.##.####.#.##.##..####.##...#.###.#.#.###..#.....###..#..#.#.#.######...##.#.##.##
#....##...####.#.#.####..##.##...#.####.#..#.#..#...####....#..#..#..####.....##..#..##.....##..####
####.#.#...##.....##....#..###.###....####.#########...####..##########..#.###.#...#...#....#..#####
#.##..###..#####...##.#.#..##.......#..####..#...##.#.#.#..###..##....#.##..##.#....#.##.#.###...#..
####..#..####.##.....#####.##.#...#..#..#...#.....#.....##.#...#..#.###.........#..#....#####.##....
..###.#.#...#.#..##..##.#.##.#..##.#..###.##....#.##.###....#..#.......####.#####..#...###.#..##...#
.##.#.#...#..#.##....#...##......#.##.##.#..#####.#.#.#....#......#..#..#..####.#.#.##.##.###.##..#.
##.###.##.####.#..##..####..#...#.##.###..#.######.#.##.###..##...##...#.#...##..###.##.#####..#...#
.######..........#######.####..#.##.#..#.##...######..#...##...#.#####.#..#...#....####.#.######.###
#....##.##.#.#....##..#.#.#...#.#..##.#...####....#.##...####...####....###......##.###...#........#
#.#...##..##...#....##.....###.##...##.##.##.#####.######..#..##.###..#....##....#.####..#.###..##.#
..####.###.####.###........#.#####.#.#...####..###.###.#####.####.##...###.#.#.####.#..#.##.###.#.##
####.###.##.###...#######..##..#.##.##.#.#..#..#.#.###......#.#...#.##..#.##.#..###....#.#...##.#...
.#.#.####.....#....####....###.#.##.#......#..#######.#..##.###..#.###..#....#......##.##....#.....#
.#..###.....#.....##.#.##.##..###.....##.#.#.....#..#.#..#.##....##.#.###.#..###....#...#.##.###....
.#.#.##.##...##...#.#.#.##..##..###...........######......##.###.#..####....#.##..###.#####......###
#.##..#.##..#......##.#..######.#..###.##.#..##.####..#.###...#.#.#.##..###.#..#..###..#..###.##...#
.###.#....#..#.#....######...#.##.#####.#.#....####...#..##...#.###....##.####..#....#.##...#.######
#######.###..#..##.##...#.#....##.##...#.#..##.#.###.##..##...#..###..####.#......###......##.#.#...
#...###.#.#..#.#....###..#.#####.#######.####......##.##.#.##....######..#######.##.#..#.###.#..####
.#.#......##.#####.##.#...#..#.####.#.#...##..#####.#...#.###.#...#..##....##..#..##.#.##..#.#.###..
..####..#.#..#..########.###......#.##....#..##.....#.##...#.##.....#........#...#.######...#######.
#.##.#.######..#..####....##..##.##..#.##..#.##.###..#......###....###.#.###.........#.##.#...#.##.#
...##.......###.#..#.#.#.##..#...#####.##...##.##...#.#....#..#....#....##.##....###...###.#######..
#.....#######..#.#####....#...#..##.#.##...##.##.###..##..#.##..#..#...##..###...##.#....#...###..#.
.#.####.#.#.....###..######..##.....#.##..#..####.######..##..##..#.#.###.#.#####...####..#.####.##.
..#.##.#.#..#...#..####....#..##.##.##...#.##.#....#..#.#....#..##....#.#.#...###.#...#.##.##.##.#.#
...###..##.#....#.#.........#...#..#.#....#.#.###.###..####.####.####..#####.##..#..#####.##..###.##
#..#..#.#.#....#######.##..#.##..###..#####.#.#.........#.###..#..##..##.#...#.##.###..#.#..##.....#
.#..#.#.#..###..###.###.##.#.#...##.#.#.#.#####.#.....##.#.#...###...##..####....#..####..#..#.#...#
.#.#####...####.####...######...#.....##...#.####.##...#......#....######..##.###.....##....#.#.###.
..#.###...##.###..#.##...####..###..#..##.......###.##.......##....#.#.###########..#..##.#.#...##..
##..##.##..#....#.######.####..#....##.########..#...##.#...#.##.####..##..#####.#.#..#..#.##..#.#.#
.#......#....#.###.##.##....##.....#.###..####.###.#.#...#.###....###..#.#.##.###..#####..#..#####..
#..#.##.##.#...#..###.##..##.#..#.#.#########.#..#######.###..##.##...#..##.######.##.#..##.##...###
##...#####..######.##..#..####......####.#.#....#..##...###.##....###...##.###.....#.....#...##...#.
#.##.##..#.#.####.#.##.#.##.####........###.##.#.....##.###..#...#.##.##.#.##.##..#..######.#...##..
##.##..#.##.#..#.#.#.###.#.#.######.#.#....#.#.##..##.#.###.#...#..#..#.#.#.##...#..####...##.#.#.##
...#..##..###.#####.#.####.##.......#.#####...#.#....###..##..#.##.#.#.####.#####...##.#..##...#####
.#.#.#.#.#.###.#.##..##.##......#####..###..#.#.#..##.#.##......##.####...#.#....##....###...###.###
##...####...###.######.#.#.######..##...##.####.##..##.#.#.#.####...#.#.##.##...###.#.#.##.##.#.##..
.#.#.###..##.##.#...##..#.##..#..###.##...#.#.#.#...##...###..###.#...###.#.#...######....#.##.##..#
.##.#.##..#.#.######..#....#....#.#..###.##.#...###.##..##....###..#####.#.##.#...##...###..##..#.##
..#....##...#...#.##.##...###.##..#...#..##....#....#.###.##.##.##.#.###....####.###.....#.##.#.##.#
#..##.#####.....#.###..####.#..##..#.#.##..#####.#.##..#...#.##.######...##..#..####...####...#...#.
##......##.#.###.##.#.###...##..##.#.#...##..##.##..#...##..###..#..#.###....##......###...#.#####..
##...##....#..#..########.#..#.##.#.###.##....####.#.#.##..#.######.#...####..#....#####.##..#.#.#.#
...#..#.#.##.#.#.#.....##.###.#.#.#######.####...####.#.#.#..##.#......#.....#.#.##..##...##.#.###..
...#.##...#.#..#...#.##.#####.##.##.#.#####..##..####.#.####..##....#..####...###.###.###.#..##...#.
#.####..#....##...#.#..###..#..#....#.#.###.#.#.##.##.#.########.#....##...####....#.##..###.##..##.
####.#.###..##..#.#..#...###...#####.#.#..##..#.#....#.#........#..#....##.#....##.##.#..#..###..#..
.##...##...#...####..###.######.#....#.##.####..#...###.....#..#.#.#..#.####.#.#...#..#..##..##..###
###...#.###.....#....##..#..#.#####.#...#...###..#...#.#.#####..#.###...##.#.#.##.#.....##..#.##..#.
####...##..#.#...###.#...##..#.#.######..##..####.###########..###.....#...######.......###.########
##.##...##.#...####.#..###..####..##.....#...#..##.#.##..###........#.....###.##.####.#..##.#......#
...#####.####.##...##.####..#####.#..#..#.#.#.#...#..#####.##.#.##.####..###.#.#...##....##.#.....#.
##.#.##.....####.###.###..#..###...#.##..####.###..#.#..#.#..#.#..#...#.#.#####..#..#.#.#..#.#..#...
#######..####..#.#######..#####.####....###..#####..#######.#.#.#.####.#..#.#....###.#..##.####.#...
..##.#...#.#..#....###.#..###......#.#.#.#..##.#....##...#.....##......##.#...#.####...#.#.#.###.##.
##..#.###..###.###..#.##.#.#.#..###..##.####.#.#.#.#.######.#..#.##..#...###.#.##.#####.###....###.#
....###.###..##.#.####.#.###.......##.##.###.###.###...#...#.#.####.#.##..#.#...#..#.#.#.###.#.#.##.
.#..#..####..#.###.##.#.##..#....#.#.###...###.#..###..#####.#.##.##..#.#...#..##....##.#...#..#.#.#
###..#.####.#....#.#..###.#...#....#..#.#..#.#######.#.#.####..#..#.#.##.#....###.#..#.#.#####.#..##
#.#.####.##.##..#....#.#.#.#..#.#####.###..##...##.#.#.##.###..#..#.#...##.#.#..##..#.###.#..###..#.
#..#.##....##.#..#.##.##..####..#####..#.##.##...#..###.###.#.##.#..#..#.##.#...#...#.##...#..##..##
..####..#.#...#..###..##.##...###..#.###......###..#..####.#####..#.#....##.#..##.###.#.....####..##
#.##...#.#...####.####..##..#...#.#####.#...#..#.#.#.###.#..#..#..#####..#.#...#.####.#...#.####.##.
.#.#.#.....##...###...##..###.##....##.#.#.##...####....##......##....#.##..#.#..###.##.###.#.......
#....#.#.#..##.#####...##.#......#.####.#..##.####...##.###.###....#.......#.##..######..#.#.#####.#
..#..###....##.#####..#.####.#.#####.#.##.....#..#.#..##..####.#.#.###..###.#.###.#...#.#..#...#.###"""

]]