#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
using namespace std;

string input();

static size_t common_chars(string const& s) {
    return s.size() - unordered_set(begin(s), end(s)).size();
}

int main() {
    size_t res1 = 0, res2 = 0;
    unordered_map<size_t, size_t> ez{ {2, 1}, {4, 4}, {3, 7}, {7, 8} };
    string str, str1, str4;
    for (stringstream file(input()); getline(file, str);) {
        size_t out = 0, idx = 0;
        for (stringstream line(str); getline(line, str, ' ');) {
            size_t cnt = str.size(), val = ez[cnt];
            if (idx++ <= 10) {
                if (val == 1) str1 = str;
                if (val == 4) str4 = str;
                continue;
            }
            res1 += !!val;
            size_t cnt1 = common_chars(str + str1),
                   cnt4 = common_chars(str + str4);
            val = cnt == 6 && cnt1 == 1 ? 6
                : cnt == 6 && cnt4 == 4 ? 9
                : cnt == 5 && cnt1 == 2 ? 3
                : cnt == 5 && cnt4 == 2 ? 2
                : cnt == 5 ? 5 : val;
            out = 10 * out + val;
        }
        res2 += out;
    }
    cout << "Part 1: " << res1 << endl;
    cout << "Part 2: " << res2 << endl;
}

string input1() { return R"(
be cfbegad cbdgef fgaecd cgeb fdcge agebfd fecdb fabcd edb | fdgacbe cefdb cefbgd gcbe
edbfga begcd cbg gc gcadebf fbgde acbgfd abcde gfcbed gfec | fcgedb cgb dgebacf gc
fgaebd cg bdaec gdafb agbcfd gdcbef bgcad gfac gcb cdgabef | cg cg fdcagb cbg
fbegcd cbd adcefb dageb afcb bc aefdc ecdab fgdeca fcdbega | efabcd cedba gadfec cb
aecbfdg fbg gf bafeg dbefa fcge gcbea fcaegb dgceab fcbdga | gecf egdcabf bgf bfgea
fgeab ca afcebg bdacfeg cfaedg gcfdb baec bfadeg bafgc acf | gebdcfa ecba ca fadegcb
dbcfg fgd bdegcaf fgec aegbdf ecdfab fbedc dacgb gdcebf gf | cefg dcbef fcge gbcadfe
bdfegc cbegaf gecbf dfcage bdacg ed bedf ced adcbefg gebcd | ed bcgafe cdgba cbgef
egadfb cdbfeg cegd fecab cgb gbdefca cg fgcdab egfdb bfceg | gbdfcae bgc cg cgb
gcafb gcf dcaebfg ecagb gf abcdeg gaef cafbge fdbac fegbdc | fgae cfgab fg bagce
)"; }

string input() {
    string a = R"(
badf gadfec bgcad ad dbcfg gcaeb fecdgab gad bgcadf efcdgb | gcadb ad agd deacfg
adgfeb dagecf ceadg edabc ceg dfacebg fgead gfcd becagf gc | acdeg efbcag agfcde fagceb
fedgcb gcadb edgcf af fbcedga gdafce faebcg acf deaf gdafc | edafcg fa ecagfd acdbg
gafced gac bdfeagc dface aedbg agedc cg cgef dafcgb cbeafd | dgcae ceadf cga abdfce
bgda cdg dacbe cfega begcafd febacd degcba adecg edcfbg gd | dfecbg dg defgcb gfcea
bc gadebc bdc gebfd cefb bfgdcae cgdfb dcebgf bgaedf cfadg | cdbega begfda gfcad gbedf
gdcb cgfeab ecadfgb gcbfe dc dcgef becdfa faged ebdgcf cfd | caegfb cfd efgabc cgfbe
cefdag bf fcebag gafbc fedcgba aefcg gcefbd feba dgacb gbf | bfg bf bf edcgaf
cbe fbdcae cgfbe dfagbc gdeb cgefa bfegacd bdfcge eb gdcfb | fgcbe gbcdef cbgdf dbeg
bcfdga bacgf bdg adgc bdefa fcedgb dagfb ebcadgf dg bcfeag | ebfad aefbd abecgf gcefadb
fa fadbgc ebcfd efgbdac gdcafe fda egbdac abgdc dcafb bgaf | bgacd cbgda gfebcda adf
cabegf dbceg gacefd cb ebdgca bce adbc bfgde aegcd cefadbg | eabcdg gcebd gecfad cadgeb
cbgae gedacf eagbcfd cebfda dbfg cgfbda bcdaf bfagc gf gfc | bfgd abfcdeg dfgb gbdfcea
bgfcae bg fgacdb cdegfba gebf ebacg cdaeg cgb cbafe dcebfa | cebga bcedafg dgeca cdgfeba
bge fcdgbe bgead bacg fdbae debacg aegcd fdbacge fdcgea bg | dgaeb gcbdea dgcefa adgce
gfedca afg acbfe cbdgfa gdba gafbc ga fdcgbe dbfgc afedcbg | befgcda ag gbdfc gbdfca
gafeb cabeg aecgbd gf fceagb gacf aebfd fedgcb gecadfb egf | gfecba fgac cbgfeda gacebfd
debag gfacedb gfdeca ca dca cdbef dabgec dgebfa bgac badce | gcdbfea cfdeb eabdfg cda
eacbfg ebgcd dgfbc fdecba gbedca eg adecb gce abgcdfe egad | bdfgc gdecb fagecb bgdce
gd cfadeb edcagf bgcea ebadgf dbgf dbeag cefdbga gde fabed | adbfe dfbg dg agdbe
cdfage bedga defgab gdafcbe abcge fdgcab db febd dgb fdeag | agfbde bd gebad bdcafg
gfdbeac daegfc gefac efdgbc acfd ecdfg eafbgd aebgc fa afe | fa af defgc dbfecg
fcbgd dgbaf gfa gbae gdafbce ebfda ag fadegc adefbg afdceb | dabef gfa dagfbe baefdg
bcdegaf dfa dbeacf geafbc cagbf df afcdgb dafcg caedg gdfb | gcdae fda ecgad fdacg
febgda gcbe facdgb fcead eag becadgf ge abfgce cgeaf afbcg | eag eg fegac cafeg
fcbgd cga dcbga ca abdeg acbe dacegb gaebfd gfcaed bdcegfa | adgcb bagedc eacb fdecagb
gabfec gebac ebfcdga cdfge agcfe fa dgacbe fabc dgafbe fag | fgedc afbgcde afebgc fabc
fabe deb egdafbc dgabe gbafcd dceag gbafd fdbega cgfdeb eb | bdage efdacgb degac fbdag
gad afgdbe gfcaed gadce egbafdc fcda acgbe gdcef ecfbdg ad | fgced agbce aecbg gcdef
dgbefc def cadeb badfe fe dfeacb bacdeg efca feagbdc bfagd | cfeabd debaf cbdfeg edcba
cbfadge dfacg ebcdga bafcgd adgfce bad bfga fcabd decbf ab | ecbdag cafdbg fabcdg ab
aedbcf cfba adf afced edcfb adcge fecbgd bfadeg af dabegfc | acfde adegc gdeca dgefba
efcad fabegcd dgbfe age fgebca dbegfc ga egdfa bgda baegfd | dgefb egbfd ebfagd agdfe
agcfbd ecfabd aebgfdc acebd cgaeb cgb gface gb ebgd cagbde | gb aegbcd cbgae bfdaec
caedgfb gd bgde dfabc beacfg gcbad gadbce ecbag dgefac cgd | gdc bfdac bedg ecgdfa
cedagb begdaf cdagb bc cagfbed dcfga dbce fbacge bac egdab | cba edbc cb fdgbea
cadbe fc defgba dafce cfd acgfdb fgeda ecgf eadcfbg fcgaed | cdaefg dgfebac cbade ceabd
bagedc dbgca degacf bc gfdba ceba cdfebg fgcaebd bgc cgade | dacgeb gbefcd adecg fcaged
fgc cg efcdga abfedc gdec aefcd cdgfa gcaefb dfgab afecdbg | fcaegb cgde dafcbe caedf
dc dgcef fbeadgc gefca gdcfeb bgdfe faedgb bcdf acbged gcd | beacdg dc cd fdegbc
cdf bcfg fc cegfda adfbcg dbfag cbdea dbacgfe gbafde adcbf | cf bafcdg cf afgdb
aeb cdaefb fbgca fgcead gcadbe be acefb gbcfead fbde ceafd | edafc cbadfe efadc gecafbd
cabef gcfbd fbcda deafbg abd aedc bfgcae bfegdca edfabc ad | dfeacb gbadfe deca ebafc
fecbdag ed efgac cgadfe gfceba abcdf eadfc dgbefa fde cdeg | fagec gfbdea efadc dfgabe
bdce cgafd db bdg bgefc cfedgb facgeb gdecbaf cdfbg gafebd | bedc cbefg dbec fegcdb
edgcbf gd febgda dgcf ecbdg ged aebdcf dbagcfe bcefd gbcea | cafbde afbdge cfdgeb gcbefd
bcfeadg fbgae dbcaef bdeaf cbfedg facd efd decba decbga fd | abecgd bfaeg egcbda dcegabf
cagdbe ecg eafgb cafegb cg gcfb aegfbd fadec aecfg gcbafde | cgabde cgafe cadebg gfaec
ec fgbcea cagfed dcbgaf adbge aec egadc gcfad bedagcf decf | dgefca fbagce fcadg aec
aef dgcaefb cbea gebdcf adecfg gbfec bgfeac adgfb gabef ea | befcgda dbgfa efa ae
gdeaf ecba cdabg gce dcgabfe debcag egdac ec gecfbd cbadfg | edcfbg adgcfeb bdaegc gec
fcgaed cadbf dcfegb gdfbc gcb fcageb acfbdeg gb dbge gdfce | fcdba bg fcbeag ecfgda
debac fgadec cdb fcegabd cb bcge cfdabg edgca efbad gcdbea | cadgfeb ecdgaf dbc gcaed
cdagef fgdac ed fegd aedgc dea bfcgda cebag bcfeda cfagbed | aecgfd cfadg geacd gcadfb
adcfb cgaef gacdfe gacfd dgbecfa cfbgea egda dcg gd gebdfc | bfaecg gdc cdg fgecdb
dae edcafgb cfedg eagfb dgafe da faedcb faegdb ebcagf dagb | facdeb eadgf ead baegfd
dgcabf facgbe egcabdf ec fce bfdge caed gdafc cgaefd gcedf | deca dfgca cgbedaf gfdce
fgdeac aebg ga ebdcgaf ecgfdb gcabd cfabd debcg gac dacbge | efdcbg ga bcdeag gbdcea
fde fadge df acdfbeg cbdgfe dfegab cdage dbfa gbaef fgacbe | agdfbe eafgd bfgdec beagf
decbfga ebfgcd fdcae bdc eafdcg dfbca bace fecdba cb abfdg | eafdc gcbfde bcea cabdf
eadfbc bcgd cfdeg gadef acfegb cg eabgcdf bcdegf befcd cge | bfced cdbef fceagb bcdg
adbgfec gb gafb efdagb ebadcg aegcfd dgb gdfbe dbecf adefg | fdaeg dfbce ebdcf efagd
cgea gbcde agdcfeb gba gabcd dagfbe cdgebf egdabc ga cdbfa | ga adfcb gbdeca ag
fd abcef becdg abdfeg cbagfe dcfa fbdaegc fed ecbfd bdfcae | bafecd fcadbe facd begdc
cagfdbe baegf eafcb cafbge dfebg gaec ga agbcdf gab cbfade | fbedg bgfae bacfed geafb
eacdgf fac fa cebda bdfgce dcfea adcgfb feag decfg bdfcgea | adbce bfceadg cfdgea edabc
eb gafcb agdcbf fdcea cbdeafg fbegac fceab ebgf bec ebacgd | fdcgab egafbc ecgbfa dgacefb
cegfa afdbgc adgecf cebfa degca bacged gf fdeg fga ebadcfg | eagfdc edgf dgbace acgef
bfae adcfgb gecfb fa gabfce acdeg egcbfad acegf agf befgcd | bcgef gefcb fgabcd cgfbad
bgefa eca cgefa ce gdfeba dfcga gaebdcf cbfe dbeacg cgbafe | ce aebgf gdcaf cae
egdacf edfba fabdc cgeafbd cagfbd gadfc bfdecg bc fbc agbc | bcf baefd cdfgab gcfdab
dbfgc befgcda ebd fbcead adbcfg dfbgce gbef eb acged ecgbd | cbefdg edfcgb gbcfd fcbgd
fgabde gdbf egadb cabdgfe bd ebadfc bde gdaec gfecab afegb | fegab db bfgae gcade
gdcabe egbadf aedfcg gbdf efd agefbdc becaf badge fdaeb df | aedfb gbdae eafdb cdebag
facgbe ga feadcb begda agcd daebc ecadbg gcdfabe abg gebdf | eadcbfg gecabd fgdbe abfceg
feb dbgfce fb debfg fdegc beagd dgfabec fcebad fadecg bfgc | gfbdce gbcf afgbcde egadb
gebfda fdbeacg afecb acbdf bd dgcfa eagbcf bdceaf bda ecdb | cfabd cbdfa gfdbcea dbec
edfgb degcb fbegadc df fabegc gbfade fdb afdg fageb bdfaec | cdgeb bagfe gedbaf fdebg
cadge dgfa facedb dfaec eagdbfc abegfc gecdb ga edgfca gac | dcbeg bacedf gacefb cgfdae
cbad edgbf afcdge ecafbg ecdfb deacfb gedbcfa dec cd cbeaf | bceaf abcd cd cde
decaf dgbaef gbfac bcadfe dgce agdfc dg adg cbgedaf gcfade | dbacef cafdeb efdabg gfeadb
dgefcb cgbdfae bcdge bga gcea ga dfgaeb dgbac cbadge abdcf | ag agb cfegbd egac
dace fecgd gdbafc egdfbc gad dfaeg dbfgace afbge da cfaged | dag gafde eacd egfdc
adbcge ea fbagcd gedfca cdbfgea bdcfe cdeab eac ebga dgcba | eagb ea efdbgac begfcda
egc dbecfg gc cgba aedcfb becgadf cfeag dgefa ceagbf bafec | cg fdbgec agefc fgade
debcf cabfgde fegbac egaf gf baceg efbcg bgf acbegd gbafdc | fbg bdcfe cbega fg
cfadgeb adbef fgabd efgcab dae dceb ecbfa de dfecag befacd | de acgefb efdba bafecg
cbaegdf gaf gf cedafg dfaebc ebfda gbef abfedg bafgd gadcb | ecbafd deabf cdgba dafgec
cge dcfga efdgb ec ecfagdb egfcd ceda dcagef bcegaf dbacgf | facbge gfcead ec gfdca
fbaced egfabd dbgcef dbgfa dfa adbcg af efag fdbeg abgefcd | edfbg egfdcb begfd bedgf
ce egbadc gec cfgabed bgacef caed dcegb gfbed acfbgd gcbad | dcfgab ecbgd bdceg ce
fcaebd ceafbdg dfbgec aecbd fecba deb ed bcefag badcg dafe | gdcab gacbd fecba bdace
af bacefdg cfgdb bcdfea cgdeab badce fda afce dgabfe dfacb | bgfdea bdacf cfdba adcfeb
cgbe gfecbda fgdbae agbcfe fdgbac caegf cfg cadfe afgbe gc | bgce geacf fcdae efgbad
cfedab fdacb ceafb gdcfeba bd afcgd ebgdfa dba cebd fagcbe | db dgcaf abefc edbgfa
gdfbce ecgda gc bagc bdfeac aecdb deabgc edfag cge dgebfca | gbaecd dceab afbdgce eabcgd
gbeca acdegf afdeg bgfcaed cd ecdf gdbcfa dcg decga bgdfea | fdce egabc dc egdfa
cd fbcd acd aecbdg becfad cefga dcfae ebgfdca febadg febda | cadegb dcbf cfdeab agecbd
dc abefgdc beafc egbad daegcb dcb gdafeb acbed gcbfad egcd | degc bdc deagbc dcbega
aefdbg fcdbaeg gdbec dacf dfecb fbc bfeda cegabf fc dbeafc | fbc bfecga fbceag dgbec
dgabef faebc efadb ecagbfd agecbd ce aec bcafg fdce cabefd | cebagd befdac defc ce
fdbcge gbfdeac edg fbdea gacd gebac gdebca aefbgc dg egdab | dafeb dfabe caebg cadg
bedfc cgafe dfabce bcfadge bfcea ba cfgedb fba cadb gbdfea | bfadgec edfbc efbcd afb
fgebad bdacef ceabf afc agceb bgfcda fc dabef edfc fdabegc | dfegab ecbfa efdbag acbgfed
afb agcebfd dbca edcafb ba cfbge egafbd febac agefdc efcad | eafcbd eadfbg dcgafe efacd
bc eagcbd ebafcdg gbfae cfgdea dgcbfa cebd gecab deacg abc | edgcba cbaeg ebacg abdfgc
fea aecgfd abedcg fa dfcea gdfa ecfagb gecad efcagbd cfebd | aef cefdb fgda cfbed
gbdeaf cdfbg edgacbf ab abg gceda dcgba bcfa gecbdf afgdbc | ab agcde dfcgb agcbd
gcedaf fbadceg egdfba cedb dcfbg fbd dfcge bd fcgebd bgafc | fbagc efgdcb dfgabe edcb
cfeg egdfabc dbefga bfcedg fbdec dfbca cbgead bec bgedf ec | efbgd bdecf debcga gfdbae
fdegbac begf agecd afebdc aebcf abcdfg aefbgc bg bga ecabg | bg bg bga bag
ef gef efbd cgefd debcga bedcfga bgdcfe egcdb gacdf bfceag | bcfged gafbce gdcbea gcedba
fdbc ebcad dgabcef decfag dcbefa db edfca gcbea adgefb dba | gebac fdbc dabce agbfced
gacd fgbea adf agdfcbe afedcb fcdbg dfbag cfbdga dbfegc da | gadbecf cfbdg eabfg gcad
edfabg cfa gcfe dfcabe cgadf agfde cgbad gdefca dcbfaeg cf | fca ecfbad agedf fdaeg
befda fc gbdceaf bfcdga gbadce bfc abgdc dbafc dgfbec gafc | cf adfcgbe dgcfab cabdf
ca bgeca edfcagb eac geafb ebgfda cdgeb afegdc cbfa ebgacf | ac bcagfe fdagbe beagf
aebdfc cfgbe fcgdb acfdgb dg gafd fdbca gbeadc gdb dbecfga | abcdf egfbc cabdf befadc
bceaf dfabeg ce bec cbdefg dfcgbae cgfab bacedf aebfd cead | gbcaf ecad baefc bdfae
fbdegac cgeaf daebcg be efdb bgfced ebfcg dgcfb cdbgfa cbe | be fbegc cgfedb be
dfcag fgedbc dbceafg adcfe gbafcd acbedg dbacg gfc gf bgfa | cdgabe agbf fg cfg
cagfeb ebcdf eadcfb fc ecabd acdgeb eacbfgd febdg fcad cfb | dcbage cf bdcea egfbac
dcfga bdacfg bdag cafeb aedfgc gfcab gb gbfedc gafedcb cbg | fecdbg edfgca dcgaf edfagc
fe cabged afcgbe gefdbc caefg ecf efab ebcdagf gabce gcdfa | gbcea acefbg adfcg ebgcdf
adce aefdbc bacfe ecgadfb ca dcagfb eagdbf gcfbe bdeaf afc | ecbfa dabef eafdcbg fdbeac
dgbef da befca bdfeag bda dcfgeab gfdbce edbcga bfade gfda | dgbef da da gdfa
cda dabg fgdbc acfedg fbdca efgbcd cdgfabe faecb fadbgc da | gbfcd abgdcf eafbc gcbfd
ceabd gefbda bgfaec fgcea fba dcfeag fb bcfagde bcafe cfbg | efagc febcga fb dgafec
agcfeb fae ea cadfgb dacfb cbefda ecdfbag aefdb cead gdfeb | afe gdfbe efa begfd
edgbca gedbc bda gbfac dgefba da bfdgce edca gdcab acegbfd | adce dbceg cfbga dfebgc
gbfdaec gcfed cae eadcbf gdfabe ac agbef eafcg bfagce cgba | afcgeb dcgafbe fcgabe gdcef
fdcbeg df cbfeg aecbfgd dcfeb efbgac abgfde gdfc edf cbdae | fgcd becfdg fd ebfcgd
cea fbce cebgfa gadcf defbga ce fgaec abgcefd aecdgb abegf | gfeca gfeab ec egfca
egbdafc decfbg dfg abcfeg fd gfceb deacg fcedg befd gabfdc | efcgb begfc afgcbd edcfg
gb bcagf adgcf fbg acfeb bgec cgedbfa fdebca afcbeg egfabd | eacfb egcb gbce fgcbae
bfcdea acbgf geabf dgfceb gaed fgadbe aef gfacbed ea gefbd | gfcba ebfgcd bafcg debfac
gbdfac eb fgabce fedca abefcdg ebcdga bagcf begf abcef ceb | dfcea efgb gdbeac cgfdeab
afbdec cg cgab gdeca cbaedg gec fbcadeg afdeg beacd fbgedc | bgcefd agecd cg acged
cgfdb be deagbf aebd ebdgf cefgba gabecdf acdfeg feagd beg | baed gefda febgac bade
bfedg dcgeb bf ecdgfb fadge dcbega fbce dcbgaef cdfgab dbf | bcdge gdebc gdceb fdb
facg cgdef ebdacf gaecbfd cfgade gc cgd gdcabe fdegb deacf | gfbed dagfecb gcfa dceaf
afbge cag afcb fbgeca dfecg dgacbfe ca aegdcb dagbef cfgea | fbeag cabf ca faecg
efdacb baedgf agefbc aeg aefgd eg dgeb dcgaf dbeaf cgfeabd | abdef fedgab egbd eg
afebd cdebf cfea ae bcgfed dgabce gbfad bgefcda aeb ebdcfa | aebdcg efdab ea ecbgda
acdfebg gceda ab daebc cagbef bac gadebc ebfcd eacdfg dbga | gafcde gdaecf ab cdaebg
)", b = R"(
adf deac bfacgd gacefd dcfeg dbfacge gfbae bgfdec ad eadgf | dabgcf fad gafed ad
dcafbeg eadgc fcbga bfgade cafedg fcaeg cfde gef egadbc fe | eacgbd eadgbf dcebag efg
bc cgdfeb fgbad fdgbac fbc cefga bfcag cagdbfe dgfabe badc | gabfc bafdgc gcabf fgabd
fb cdfag adbgf fbg dgceaf abfc gbadfc aebgd gbfadce bgfedc | agdbf fcdgab cfdgeb dgcefb
dcefa adgbec gecfbd gcdea dge gbea abdgfce eg gdcbaf bcadg | gaedc eagb eabfdgc cgbfaed
gfedb gafdeb bcafdg beg dgabf efab be adgbec dfagecb fdceg | gdebca gdecf defcgba gdbaec
edgbca dcegf cbfe dgbaef bdcgfe dec fgbde eagcfdb ce dafcg | edfcg eafgbd ec agcfd
gdebfa bgadf eacbg dcbgaf gabdc dbc ebgcdaf gcbfed cd cdaf | adcgb dbc gbecfd dacf
abefdg gbecf cdafebg abdfe gadf aegfb edcbfa deacgb ga eag | gae abefg cegbad abecfd
fgcde gaefcbd adbcf ea gbeadf cfead deacfg bdcgef aed aceg | cgbefda cegafd ead fgcde
befgda cfebg cead beadcfg edbfca ca fcdagb baefd acb bfeca | ebdafg efdabc dfaeb fgadbe
dafc egadcf badgce ecgfa cf dfecgb ebgaf gfcdbea fgc gadec | gcf abgdfec ebcfgd gfaec
bdaf df afgce aefcd decfab abecd bfgdce dbcage fdabceg def | aegcf fgbdce bdfa df
cbgfed cdaeb fega agfcbd dafbge abf gdebf fedba degfbca af | acdbgf fa defbg egbfd
dabcfe eagb cgebaf cbgfe eb cbdfg afecgbd feagcd geafc bef | cefga bcfge cebgfa gdcfb
fd dcf afdb fgcab dcgfa fegdcab gabdcf acbfeg cgdae cfedbg | abcgdfe cdfag ebdgfc dfcga
ged egbdfa bgead bgfcea dcfbeg afgd edacb gd afdbecg ebfga | gaefdcb egd edgab efbdgc
dfgace cbgfa bfgad cb acb cfbe cebfga afgec dcaegb eagdcfb | fabgc agbdce daefcg dfceag
cfbe bfcaed cba cb ebcfgad ebcdga acgfde bagfd dcabf ceadf | abc fdaec fbdaec cfdba
egbdfa fabde bcadfe fcgab fbgea fgecdba gebd gae eg ecfgad | gae agbcfde fcaedg ebgd
cfabdge cefgad befgca bdgcfe cb cbgd gdefc ebc daebf bcfed | dcbg afedb cgbd cfbgaed
acdefg gadce bcg gbfdca dcbfe dcbgae bage dbcge gaedbfc gb | cbdef fcdbe agbe bg
bcd gfcaeb egcbdf cgbde gbecf cd fced bcdafg bdeag dbcefga | cbd fbgcad egcbd decgfb
bgea dafbg efbad eb cefdbg adefc aebfdg bfe aedcbfg agbcfd | bfgced afdce dcebgf bfgdea
cedgfb gdbefa agcb cg degab agbdce cadbfeg gceda cge fcade | ceg gc fdecgab begda
dfbgc gbfae ed fgbde edb cdfegb dgec bdceaf deabfcg fcabgd | fagbced afbge bcadgf aegcfbd
edabfc bafcedg cg gdfac cgf cedfa defcbg eagc edcfag bgfda | egdcbf gc gcae edfbac
dagefb ead geacb gfacde acdbfg dbfgace de gcafd dfce dgcea | cebga gbcafd gdfac ed
efac bafed gaedbf ecfbd dbafec egcadb cadgebf dec gfdcb ec | dfbgea adgefb feac dce
agcbed cgfab bd cegdf dgb fcebgd cfbdg dcgaef dbfe bfgdaec | cbedag fcagb gadfceb agfecd
debcgf gefcd dcgbfae degbf gbf bg gcdb feacdg adefb ecgabf | gbceadf cfegba cbdg cefdg
dgfaceb adc fbgad agbdc begcfd ca afgcde acedgb ebdgc ebac | gfabd ca cebgfda ebadcg
ecbgdf ef deagbc bfcga aefd dabeg gebaf aefgdb feb cbeagfd | acbfg cbgfed bfegad bfcgde
faebcd gebcfd dcbfg gf fdecb bgf afebgd fedgbca cefg cabgd | dacfeb aefdcb fcdbge edbcf
fceabd bfgca cda efcadg gced cd facbdge gdfca gfead adgefb | befdca dfaeg cafgd facgd
agfeb ebacd gcbead abcefd dcaf fc bdcfeg fcabe fbcagde fec | feagb afdc cfad cefdab
dfaceb gbceadf dbgc fgbead ecadg cdeba gd edcabg deg fgace | edacbf cbgd edagbcf edbac
agb gceb ebdagc edbag edfab bg cdega fcgaed cgabfd dgaefbc | gbdeca ebfad egcfda cbadge
ae gaef gfdce decag fadcegb gecfdb dcgfea edcfab bdcag eac | gdacb gdcfe fdcabe fdbgec
bagdf gebd afgdceb efbagd db gbaefc bad facdg facdbe fbgea | dba gfadb gadfb dba
egfab ecgadb afb gfbce gfda gdebfa edbfacg edbfac af abgde | edgab fdbace bcfeg fa
dbafc adc daef ad dfgbc gebcda facbe bcfaed aecfgb eadfgcb | dgcbea bcgfd cbedag agfebc
debcga dfcbg egfc cgd gc cedbgf fdceb acfdbe fgbda cbgafed | eagdcfb dcfbg cg dgbaf
da dcebgf egdbfca gecbd cabd gabdce badefg ade egcad cgafe | cgedb afgce cbda acbd
cfbeg dgafec bd bdefc ecgbda acfde decbfa afbd abcfdeg dcb | aedgbfc fcaedg badcge facegd
acb bdag fdgbcae aefdbc gbcaed ba gacfde cgdea befgc ecbga | cdafegb gcaed cdeafg bcage
fbeacd gfdba deafcbg debgf cgda ga geafbc acgdfb cfbad fag | cabdf dfbgca afgdb afgdb
fgdbace ebfacg dgbac adgbcf bcagf ad cad facbde dcgbe gfda | cgbed ad abfgc gadf
cfd df cgadfeb dbcgaf ecfdag febcg bdfa aebcdg gcbdf adgcb | fcbeg bcgade cdf fcd
cfde eadgbc fe edacg bfgac debafg gcafe efg gabedfc gfcade | dcef gafbc gbdeca feg
gdc cbefgda acfd gdecf ecbfag fedgb eacdgf cd dbaceg afegc | gabfec dc cabfeg gdcbae
cgdefb adgebc efdcb gdfae abdfe cdbaef fabc ba abd cgebdfa | acbedf dgafe fdceb ab
degfb cgba adbec gda deacfg cfedab aegdb ebdcga dfacgeb ga | ga afgedbc gefdca baedc
afe bcafe ecga fedbc ea cfaedgb fbcag fcgaeb dcabfg fdbaeg | fcgbda bdcef gfecbad eadbfg
adgceb dacebfg caedgf dc acgfe dfgbe cgfeab cfda defgc edc | egfcda gcaedbf faceg afbceg
)";
    return a + b;
}
