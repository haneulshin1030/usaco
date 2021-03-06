/**
* Source: http://codeforces.com/blog/entry/3107
* similar to KMP
*/

vi z(string s) {
    int N = s.length(); s += '#';
    vi ans(N); ans[0] = N;
    while (s[1+ans[1]] == s[ans[1]]) ans[1] ++;
    
    int L = 1, R = ans[1];
    FOR(i,2,N) {
        if (i <= R) ans[i] = min(R-i+1,ans[i-L]);
        while (s[i+ans[i]] == s[ans[i]]) ans[i] ++;
        if (i+ans[i]-1 > R) L = i, R = i+ans[i]-1;
    }
    return ans;
}

vi get(string a, string b) { // find prefixes of a in b
    string s = a+"@"+b; 
    vi t = z(s);
    return vi(t.begin()+a.length()+1,t.end());
}

int main() {
	vi x = z("abcababcabcaba");
	for (int i: x) cout << i << " ";
	cout << "\n";
	
	x = get("abcab","uwetrabcerabcab");
	for (int i: x) cout << i << " ";
}