#include <algorithm>
#include <iostream>
#include <ranges>
#include <sstream>
#include <unordered_map>
using namespace std;

string input();

int main() {
    string str;
    stringstream file(input());
    unordered_map<char, long long> clr;
    unordered_map<string, long long> pairs;
    unordered_map<string, string> rules;
    getline(file, str);
    ++clr[str.front()];
    ++clr[str.back()];
    for (int i = 1; i < size(str); ++i)
        ++pairs[str.substr(i - 1, 2)];
    for (getline(file, str); getline(file, str);)
        rules[str.substr(0, 2)] = str.substr(6, 1);
    for (int i = 1; i <= 40; ++i) {
        for (auto [p, c] : exchange(pairs, {})) {
            auto ins = rules[p];
            pairs[p[0] + ins] += c;
            pairs[ins + p[1]] += c;
        }
        auto cnt = clr;
        for (auto [p, c] : pairs)
            for (char t : p)
                cnt[t] += c;
        auto [m, M] = ranges::minmax(cnt | views::values);
        cout << i << ": " << (M - m) / 2 << endl;
    }
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