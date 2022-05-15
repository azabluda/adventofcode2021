#include <iostream>
#include <functional>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string input();

int main() {
    string line;
    unordered_map<string, unordered_set<string>> adj;
    for (stringstream file(input()); getline(file, line);) {
        string u = line.substr(0, line.find('-'));
        string v = line.substr(size(u) + 1);
        adj[u].insert(v);
        adj[v].insert(u);
    }
    unordered_set<string> seen;
    function<int(string, bool)> dfs = [&](string u, bool part2) {
        if (u == "end") return 1;
        int res = 0, unsee = true;
        if (islower(u[0]) && !seen.insert(u).second) {
            if (u == "start" || !part2) return 0;
            unsee = part2 = false;
        }
        for (string v : adj[u])
            res += dfs(v, part2);
        if (unsee) seen.erase(u);
        return res;
    };
    cout << "Part 1: " << dfs("start", false) << endl;
    seen.clear();
    cout << "Part 2: " << dfs("start", true) << endl;
}

string input1() {
    return R"(fs-end
he-DX
fs-he
start-DX
pj-DX
end-zg
zg-sl
zg-pj
pj-he
RW-he
fs-DX
pj-RW
zg-RW
start-pj
he-WI
zg-he
pj-fs
start-RW)";
}

string input() {
    return R"(EO-jc
end-tm
jy-FI
ek-EO
mg-ek
jc-jy
FI-start
jy-mg
mg-FI
jc-tm
end-EO
ds-EO
jy-start
tm-EO
mg-jc
ek-jc
tm-ek
FI-jc
jy-EO
ek-jy
ek-LT
start-mg)";
}