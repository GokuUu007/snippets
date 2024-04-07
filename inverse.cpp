
template<typename T>
T inv(T a, T b){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}
