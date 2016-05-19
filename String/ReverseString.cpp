#include <iostream>
#include <cstring>
using namespace std;
string reverseString(string iniString) 
{
	string str = "";
	for(int i = iniString.size()-1; i >= 0 ; i--)
	{
		str += iniString[i];
	}
	return str;
}
int main()
{
	string s = "qckzfutq|ws}ejpl~oapz{}eldeedlj{fc}qx~zyjwb|}qkbdxouhb~yobmox~cz~dv}xbrrorgekiveqtkiohldybkpada}l|tvs|huzhvhbdzceoggustjojer{l|acbraylejy}kz|crawmjvyvq{emokxwh}cpyhhpuuz{iqhzpss{ysc~efuljgtc{ynqolagayo}xm}gos{dhs~cnnfpy{buhwaqfprhyyrlcjnxafilkifqb|jhiimjljg}hlhoxicxpzx}|zrbrcnirgjffsmv{et}hshlkhpeydaulawdeincawwfoqiknotjrlqm{lbikxoevqoxceuzokqjzxlreqqumkxdvantiwv~tuuimizkzjztyubawrxk{npsynddpkod|riyeykopvtog|||yodstyihkfkj~|vcsxupbrevrvwtnjpv}nlhtpxphiq|pevhyrnqpuwzwemzfnnwcse}b~oovstk~tqxupp~zjtsl}|j{nqzxnq|tcqxpwfgitzfjcpcglg|djepb}qabiomgqs~ltwclsgj}mjmq~fvgabufpnospuench~garubac|s|otlhquljsenx}rlmyazv{sqytm}ev~es{lsu{rtunuksgvrteunoyznzxohrp~odgmfak|~rnopn~wnkjwbleugeuzcg}nzntbvazibwnwblrzlcoseif|znmvnvs|z|prbejg}ajdcuinuhimxtmuifnb|fwdgegxrequoespxmwqkc}ow~nd|nqyfhiyzbappg}jqs~srpd|rmyrva{wbrazxwjvzz}}atcaluwbtbcicg{frooaivnjqgwba|cxgftayc{xbd~bekdbskcynhzpeugkedybvzmcibhlfvcyswak|djiagkh}qsfpd{wdgqahrawtv}|gsmihz|iik{}itku}~}huwfulcafcvizvc{hc{mer~xaj}i~uouw~jfs~jbn~tmibn~c}{xqjzwbcoyvviy|vksrtzox|ebso";
	string str = reverseString(s);
	cout<<str<<endl;
	return 0;
}