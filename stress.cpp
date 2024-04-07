/* 

    ॐ हौं जूं सः ॐ भूर्भुवः स्वः 
    ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय मामृतात् 
    ॐ स्वः भुवः भूः ॐ सः जूं हौं ॐ

   @Author  : Akshat Madhavan
   @Country : INDIA 
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all x.begin(), x.end()
#ifndef ONLINE_JUDGE
#define deb(x) cerr << #x << " -> "; _print(x); cerr << endl;
#else 
#define deb(x)
#endif

void _print(double a) {cerr << a;}
void _print(float a) {cerr << a;}
void _print(int a) {cerr << a;}
void _print(char a) {cerr << a;}
void _print(bool a) {cerr << a;}
void _print(string a) {cerr << a;}
template<class T> void _print(vector<T>a);
template<class T> void _print(set<T>a);
template<class T> void _print(multiset<T>a);
template <class T, class V> void _print(pair <T, V> p);
template<class T, class V> void _print(map<T,V>a);
template<class T, class V> void _print(multimap<T,V>a);
template<class T> void _print(vector<T>a) {cerr << '[';for(T i:a) {_print(i);cerr << ' ';}cerr << ']';}
template<class T> void _print(set<T>a) {cerr << '[';for(T i:a) {_print(i);cerr << ' ';}cerr << ']';}
template<class T> void _print(multiset<T>a) {cerr << '[';for(T i:a) {_print(i);cerr << ' ';}cerr << ']';}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}" << endl;}
template<class T, class V> void _print(map<T,V>a) {cerr << endl << '[';for(auto i:a) {_print(i);cerr << ' ';}cerr << ']';}


int optimal () {

}   

int brute () {

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE   
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);  
    #endif  

    srand(time(0));
    int t = rand() % 100 + 1;   
    while(t--) {
        int n = rand() % 7 + 1;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {

        }
        auto ans = optimal(), correct = brute();
        if (ans != correct) {
            // deb(n, a);
            // cerr << "Wrong Answer - ";
            // deb(ans);
            // cerr << "correct lAnswer - ";
            // deb(correct);
        } 
    } 
    return 0;
}
