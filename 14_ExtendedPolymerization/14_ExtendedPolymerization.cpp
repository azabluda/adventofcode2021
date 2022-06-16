#include <algorithm>
#include <iostream>
#include <ranges>
#include <sstream>
#include <unordered_map>
#include <list>
using namespace std;

string input();

int main() {
    string str;
    stringstream file(input());
    getline(file, str);
    list<char> poly(begin(str), end(str));
    unordered_map<char, unordered_map<char, char>> pairs;
    for (getline(file, str); getline(file, str);)
        pairs[str[0]][str[1]] = str[6];
    for (int i = 0; i < 10; ++i)
        for (auto p = begin(poly); next(p) != end(poly);)
            poly.insert(p, pairs[*p][*++p]);
    unordered_map<char, int> cnt;
    for (char c : poly) ++cnt[c];
    auto [m, M] = ranges::minmax(cnt | views::values);
    cout << "Part 1:" << M - m << endl;
}

string input1() {
    return R"(NNCB

CH -> B
HH -> N
CB -> H
NH -> C
HB -> C
HC -> B
HN -> C
NN -> C
BH -> H
NC -> B
NB -> B
BN -> B
BB -> N
BC -> B
CC -> N
CN -> C)";
}

string input() {
    return R"(SNPVPFCPPKSBNSPSPSOF

CF -> N
NK -> B
SF -> B
HV -> P
FN -> S
VV -> F
FO -> F
VN -> V
PV -> P
FF -> P
ON -> S
PB -> S
PK -> P
OO -> P
SP -> F
VF -> H
OV -> C
BN -> P
OH -> H
NC -> F
BH -> N
CS -> C
BC -> N
OF -> N
SN -> B
FP -> F
FV -> K
HP -> H
VB -> P
FH -> F
HF -> P
BB -> O
HH -> S
PC -> O
PP -> B
VS -> B
HC -> H
NS -> N
KF -> S
BO -> V
NP -> S
NF -> K
BS -> O
KK -> O
VC -> V
KP -> K
CK -> P
HN -> F
KN -> H
KH -> N
SB -> S
NO -> K
HK -> H
BF -> V
SV -> B
CV -> P
CO -> P
FC -> O
CP -> H
CC -> N
CN -> P
SK -> V
SS -> V
VH -> B
OS -> N
FB -> H
NB -> N
SC -> K
NV -> H
HO -> S
SO -> P
PH -> C
VO -> O
OB -> O
FK -> S
PN -> P
VK -> O
NH -> N
OC -> B
BP -> O
PF -> F
KB -> K
KV -> B
PO -> N
NN -> K
CH -> O
KC -> P
OP -> V
VP -> F
OK -> P
FS -> K
CB -> S
HB -> N
KS -> O
BK -> C
BV -> O
SH -> H
PS -> N
HS -> K
KO -> N)";
}