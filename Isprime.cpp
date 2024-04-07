
bool isprime (int N) {
    for(int i = 2; i * i <= N; ++i) {
        if(!(N % i)) {
            return 0;
        }
    }
    return 1;
}
