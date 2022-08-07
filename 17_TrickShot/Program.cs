TrickShot(20, 30, -10, -5);
TrickShot(94, 151, -156, -103);

void TrickShot(int left, int right, int bottom, int top)
{
    // Part 1 :)
    Console.WriteLine($"Part 1: {bottom * (bottom + 1) / 2}");

    // Part 2
    int miss = 0, hit = 1, hits = 0;
    int Hit(int x, int y, int vx, int vy)
        => x > right || y < bottom ? miss
         : x >= left && y <= top ? hit
         : Hit(x + vx, y + vy, vx - Math.Sign(vx), vy - 1);
    for (int vx = 0; vx <= right; ++vx)
        for (int vy = bottom; vy <= -bottom; ++vy)
            hits += Hit(0, 0, vx, vy);
    Console.WriteLine($"Part 2: {hits}");
}