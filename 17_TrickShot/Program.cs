TrickShot(20, 30, -10, -5);
TrickShot(94, 151, -156, -103);

void TrickShot(int x0, int x1, int y0, int y1)
{
    Console.WriteLine();
    Console.WriteLine($"x={x0}..{x1}, y={y0}..{y1}");
    Console.WriteLine($"Part 1: {y0 * (y0 + 1) / 2}");
}