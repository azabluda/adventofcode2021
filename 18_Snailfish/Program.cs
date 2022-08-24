// https://adventofcode.com/2021/day/18
// Day 18: Snailfish

Test.Cases.ForEach(Snailfish);

void Snailfish(string strs)
{
    Console.WriteLine(strs);
    var split = strs.Split(Environment.NewLine);
    var sum = split.Select(Parse).Aggregate(Sum);
    Console.WriteLine($"Sum: {sum}");
    Console.WriteLine($"Part 1: {sum.Magnitude}");
    var max2 = (from s1 in split from s2 in split where !ReferenceEquals(s1, s2)
                select Sum(Parse(s1), Parse(s2)).Magnitude).Max();
    Console.WriteLine($"Part 2: {max2}");
    Console.WriteLine();
}

Node Parse(string str)
{
    int pos = 0;
    return Parse(null);
    Node Parse(Pair parent)
    {
        var ch = str[pos++]; // digit or '['
        if (char.IsDigit(ch))
            return new Regular { Parent = parent, Value = ch - '0' };
        Pair node = new() { Parent = parent };
        node.Left = Parse(node);
        ++pos; // consume ','
        node.Right = Parse(node);
        ++pos; // consume ']'
        return node;
    }
}

Node Sum(Node a, Node b)
{
    Pair sum = new() { Left = a, Right = b };
    a.Parent = b.Parent = sum;
    while (Explode(sum, 0) || Split(sum));
    return sum;
}

bool Split(Node node)
{
    if (node is not Regular reg || reg.Value < 10)
        return node is Pair pair && (Split(pair.Left) || Split(pair.Right));
    Regular a = new() { Value = reg.Value / 2 };
    Regular b = new() { Value = reg.Value - reg.Value / 2 };
    Pair split = new() { Left = a, Right = b };
    a.Parent = b.Parent = split;
    return Replace(node, split);
}

bool Explode(Node node, int depth)
{
    if (node is not Pair pair) return false;
    if (depth < 4 || pair.Left is not Regular left || pair.Right is not Regular right)
        return Explode(pair.Left, depth + 1) || Explode(pair.Right, depth + 1);
    if (GetRegularSibling(node, n => n.Left, n => n.Right) is Regular regLeft)
        regLeft.Value += left.Value;
    if (GetRegularSibling(node, n => n.Right, n => n.Left) is Regular regRight)
        regRight.Value += right.Value;
    return Replace(node, new Regular() { Value = 0 });
}

Regular GetRegularSibling(Node n, Func<Pair, Node> f1, Func<Pair, Node> f2)
{
    Pair p = n.Parent;
    for (; ; (n, p) = (p, p.Parent))
        if (p is null) return null;
        else if (n == f2(p)) break;
    for (n = f1(p); ; n = f2((Pair)n))
        if (n is Regular r) return r;
}

bool Replace(Node node, Node replace)
{
    Pair parent = replace.Parent = node.Parent;
    if (node == parent.Left) parent.Left = replace;
    else parent.Right = replace;
    return true;
}

abstract class Node
{
    public Pair Parent;
    public abstract int Magnitude { get; }
}

class Pair : Node
{
    public Node Left;
    public Node Right;
    public override int Magnitude => 3 * Left.Magnitude + 2 * Right.Magnitude;
    public override string ToString() => $"[{Left},{Right}]";
}

class Regular : Node
{
    public int Value;
    public override int Magnitude => Value;
    public override string ToString() => $"{Value}";
}

static class Test
{
    public static List<string> Cases { get; } = new()
    {
@"[[[0,[4,5]],[0,0]],[[[4,5],[2,6]],[9,5]]]
[7,[[[3,7],[4,3]],[[6,3],[8,8]]]]
[[2,[[0,8],[3,4]]],[[[6,7],1],[7,[1,6]]]]
[[[[2,4],7],[6,[0,5]]],[[[6,8],[2,8]],[[2,1],[4,5]]]]
[7,[5,[[3,8],[1,4]]]]
[[2,[2,2]],[8,[8,1]]]
[2,9]
[1,[[[9,3],9],[[9,0],[0,7]]]]
[[[5,[7,4]],7],1]
[[[[4,2],2],6],[8,7]]",

@"[[[[4,3],4],4],[7,[[8,4],9]]]
[1,1]",

@"[1,2]
[3,4]",

@"[1,1]
[2,2]
[3,3]
[4,4]",

@"[1,1]
[2,2]
[3,3]
[4,4]
[5,5]",

@"[1,1]
[2,2]
[3,3]
[4,4]
[5,5]
[6,6]",

@"[[[0,[5,8]],[[1,7],[9,6]]],[[4,[1,2]],[[1,4],2]]]
[[[5,[2,8]],4],[5,[[9,9],0]]]
[6,[[[6,2],[5,6]],[[7,6],[4,7]]]]
[[[6,[0,7]],[0,9]],[4,[9,[9,0]]]]
[[[7,[6,4]],[3,[1,3]]],[[[5,5],1],9]]
[[6,[[7,3],[3,2]]],[[[3,8],[5,7]],4]]
[[[[5,4],[7,7]],8],[[8,3],8]]
[[9,3],[[9,9],[6,[4,9]]]]
[[2,[[7,7],7]],[[5,8],[[9,3],[0,2]]]]
[[[[5,2],5],[8,[3,7]]],[[5,[7,5]],[4,4]]]",

@"[[3,[8,[2,1]]],[[[0,6],[0,2]],3]]
[[[1,[8,5]],[[3,9],0]],2]
[5,[[5,[3,8]],[7,4]]]
[1,[[[0,4],[8,5]],6]]
[[[1,[0,3]],2],[2,[0,[7,9]]]]
[[[4,[4,4]],[[7,2],[7,1]]],9]
[5,[4,4]]
[[0,[[2,6],[8,9]]],[[4,5],2]]
[[[8,2],0],3]
[[9,0],[3,3]]
[[[[5,2],2],5],5]
[[[1,6],[[0,4],[7,7]]],[[1,4],[[6,5],5]]]
[[[[4,1],[4,1]],[2,[5,5]]],[1,[0,[0,6]]]]
[[[[1,5],1],[8,4]],[9,[3,4]]]
[[1,[3,3]],[[[7,4],[8,1]],2]]
[3,[[[2,1],4],[5,4]]]
[6,[[0,[1,9]],[[4,0],8]]]
[5,[7,[7,[8,8]]]]
[[[[6,2],[5,8]],[5,[3,1]]],[[7,9],[[2,0],6]]]
[[[7,[7,9]],[5,7]],[[[9,3],[6,9]],[[1,2],[2,3]]]]
[[[[4,1],2],[1,[6,6]]],[[[2,2],[8,8]],4]]
[[[[3,7],4],8],[6,[[0,2],3]]]
[[[[1,8],2],3],[[9,[1,7]],[[0,0],[6,8]]]]
[[[9,[5,2]],7],[[8,6],[8,[1,2]]]]
[[[7,[1,0]],[[6,0],[8,4]]],[[[7,8],5],[3,[1,2]]]]
[[[[2,5],9],[[8,2],0]],0]
[0,[[[7,5],[4,1]],[5,[6,6]]]]
[[[[3,6],2],[[1,1],[6,6]]],0]
[[[[0,9],[2,5]],[2,[3,2]]],[6,3]]
[3,[[9,[1,4]],[[0,8],[4,6]]]]
[1,[[5,[5,9]],[9,0]]]
[[[6,8],4],[[[6,6],2],[[3,9],2]]]
[5,[[[7,5],[4,8]],0]]
[[9,[6,6]],[9,[[6,8],[6,4]]]]
[[[4,8],[0,[2,8]]],[7,[[4,5],[1,6]]]]
[[[6,[8,6]],2],[[[2,9],[2,4]],[0,2]]]
[[[0,[5,6]],[[3,8],3]],[[3,1],7]]
[[1,[8,1]],[1,[6,[7,1]]]]
[[[5,[9,6]],[3,5]],2]
[[3,7],[[[2,5],[4,1]],[3,[5,6]]]]
[[8,7],[[9,6],3]]
[[[[4,2],[4,8]],[7,[4,5]]],2]
[[[[6,7],6],3],[[[6,7],4],0]]
[[[0,1],[[9,1],[2,9]]],9]
[[[[8,5],[5,8]],[0,7]],[0,[8,[3,2]]]]
[[4,[[6,5],[1,9]]],[[[0,0],1],6]]
[[[[9,5],9],[2,[6,3]]],[[2,9],[6,9]]]
[[[7,[5,0]],1],[7,[[8,7],3]]]
[[[2,4],2],[[[3,0],6],[[0,2],[9,2]]]]
[[1,[[7,3],[4,3]]],[[[3,9],[1,1]],[3,6]]]
[[[[4,7],7],[[7,1],[2,3]]],[1,[[7,6],[5,6]]]]
[[0,[5,2]],0]
[[[[6,6],[4,8]],8],[[0,[7,4]],8]]
[[4,[7,2]],[[[0,8],1],[9,5]]]
[0,0]
[[[[3,7],6],3],[3,[[3,3],1]]]
[[[6,5],7],[[3,5],[[6,4],[4,9]]]]
[[4,[[7,9],9]],9]
[5,[8,[[7,4],1]]]
[[[[2,4],[5,7]],8],[[[7,6],[6,9]],[[3,9],[6,4]]]]
[[[4,8],3],[[[3,9],7],0]]
[0,[8,[[4,2],3]]]
[[[[0,1],[5,8]],[7,2]],[2,4]]
[[6,[8,[1,9]]],[[[6,5],[8,1]],[7,[6,4]]]]
[[9,3],[5,[0,6]]]
[[2,[7,[2,0]]],[[2,1],[5,5]]]
[[[0,[7,0]],[[0,4],[4,9]]],[8,[[6,1],[6,3]]]]
[[[[5,7],[3,2]],[0,[5,0]]],[[0,[1,6]],3]]
[[[[6,3],[9,5]],[9,9]],[[5,[8,3]],[[0,0],[0,3]]]]
[[6,[4,9]],[[[9,9],[8,4]],4]]
[0,[2,5]]
[[[[7,9],[1,2]],[3,3]],[[[7,2],7],[[1,6],0]]]
[[[[8,0],2],8],[[[1,5],9],9]]
[[[0,[6,9]],4],[[[4,8],5],4]]
[[6,[[0,3],4]],[0,[[8,3],1]]]
[[[1,2],[2,[3,3]]],[6,7]]
[[0,[[7,4],5]],[3,[[8,2],0]]]
[[[[0,1],[1,7]],[[2,7],[5,9]]],[[[7,0],0],[8,1]]]
[[6,4],[3,0]]
[[[[6,6],4],[5,1]],[7,3]]
[[[[9,2],3],[8,[4,8]]],7]
[[5,[[2,2],[9,2]]],[[[1,8],0],[8,[6,3]]]]
[2,[[0,0],[0,[9,9]]]]
[[4,4],[[6,5],[6,5]]]
[[[[9,1],2],4],5]
[[[[2,1],[3,1]],[[2,6],9]],5]
[[[9,[0,6]],7],[[8,3],[[8,1],2]]]
[[[6,[0,0]],[2,[0,0]]],[[[0,4],8],3]]
[[[[4,1],[2,9]],[6,5]],3]
[[9,[[9,4],8]],[[[5,5],3],[[3,4],4]]]
[8,[9,[[0,3],1]]]
[9,[[[6,0],4],9]]
[[6,[2,9]],[[[2,7],[5,3]],0]]
[[[4,1],5],[8,[[0,7],4]]]
[[[[2,5],5],[[8,2],[8,9]]],[[9,6],[[0,3],[2,3]]]]
[6,1]
[[1,7],4]
[[8,7],0]
[[[[5,4],7],5],[[[6,1],5],[5,[5,5]]]]
[[[6,[1,5]],[0,[7,0]]],[[[1,5],3],[5,[1,0]]]]",
    };
}