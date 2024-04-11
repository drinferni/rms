#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



 
void SOE(int n, std::vector <int> & prime){
	prime.push_back(2);

	int g = n;

	if (g%2==0) --g;
		std::vector <int> vec(g/2,0);
		for (int x=0;x<g/2;++x) {
			//num = 2 * (ind +1) +1
			if (vec[x]==0) {
				int r=x;
				int num= 2*(r+1) +1;
				int op=num;
				prime.push_back(num);
				while (r<g/2) {
					vec[r]=1;
					num+=op+op;
					r=((num-1)/2)-1;
				}
			}
		}
}

long long int gcd ( long long int a , long long int b) {
	if ( b> a) return gcd(b,a);
	if (a%b==0) return b;
	return gcd(b,a%b);
}

int gcd ( int a, int b) {
	if (b>a) return gcd(b,a);
	if (a%b==0) return b;
	return gcd(b,a%b);
}


//code for connected cpmponents
//code for post and pre dfs


vector <int> SuffixArray( string & str) {
	
	str+='$';
	int len = str.length();

	vector <int> vec (len,0);
	vector <int> equi_class(len,0);
	
	int k=1;

	//k=1;

	{
		vector <std::pair<int,int>> a ;
		for (int r=0;r<len;++r) a.push_back(make_pair(str[r],r));
		
		sort(a.begin(),a.end());

		for (int r=0;r<len;++r) vec[r] = a[r].second;
		
		int clas = 1;

		equi_class[a[0].second]=1;
		for (int r=1;r<len;++r) {
			if (a[r].first == a[r-1].first) {
				equi_class[a[r].second]=clas;
			}
			else {
				++clas;
				equi_class[a[r].second]=clas;
			}
		}
		k*=2;		
	}
	
	while (k < 2*len) {
		vector <pair <pair<int,int> , int> > a;

		for (int r=0;r<len;++r) {
			a.push_back(make_pair ( make_pair(equi_class[r] , equi_class[(r+k/2)%len]) , r));
		}


		sort(a.begin(),a.end());

		for (int r=0;r<len;++r) vec[r] = a[r].second;
		
		int clas = 1;

		equi_class[a[0].second]=1;
		for (int r=1;r<len;++r) {
			if (a[r].first == a[r-1].first) {
				equi_class[a[r].second]=clas;
			}
			else {
				++clas;
				equi_class[a[r].second]=clas;
			}
		}
		k*=2;		

	}

	return vec;

}


void solve () {
	
	ll n,m;
	cin>>n>>m;

	vector <vector <char>> table(n,vector <char> (m,0));
	
	char c;

	for (int r=0;r<n;++r) {
		for (int e=0;e<m;++e) {
			cin>>c;
			table[r][e] = c;
		}
	}

//	for (auto p  : table) {
//		for (auto q : p) cout << q << ' ';
//		cout << endl;
//	}
	
	ll ans =0;
	
	set <pair<ll,ll>> conflict;

	for (int r=0;r<n-1;++r) conflict.insert(make_pair(r,r+1));
	
	int state=0;	

	for (int e=0;e<m;++e) {
		char prev = table[0][e];
		int flag=0;
		set <pair <ll,ll> > dummy;
		if (state ==0) {
//			for (auto p : conflict) {
//				cout << p.first << ' ' << p.second << endl;
//			}

			for (auto p : conflict) {
				if (table[p.first][e]  < table[p.second][e]) ;
				else if (table[p.first][e] == table[p.second][e]) {
					flag=1;
					state =1;
					dummy.insert(make_pair(p.first,p.second));
				}
				else {
					flag=1; 
					++ans;
					dummy.clear();
					for (int r=0;r<n-1;++r) dummy.insert(make_pair(r,r+1));
					break;
				}
			}
			conflict = dummy;
		}
		else {
//			for (auto p : conflict) {
//				cout << p.first << ' ' << p.second << endl;
//			}
			for (auto p : conflict) {
				if (table[p.first][e]  < table[p.second][e]) ;
				else if (table[p.first][e] == table[p.second][e]) {
					flag=1;
					state =1;
					dummy.insert(make_pair(p.first,p.second));
				}
				else {
					flag=1; 
					++ans;
					dummy = conflict;
					break;
				}
			}
			conflict = dummy;

		}
		if (flag==0) break;
	}

	cout << ans << endl;
}


int main () {

	ios_base::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0); 
	
	solve();
}    
 
