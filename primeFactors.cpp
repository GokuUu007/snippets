
// TC - O(sqrt(n))

vector<array<int, 2>> factorize(int N) {
    vector<array<int, 2>> factors;
    for (int i = 2; i * i <= N; ++i) {
        int c = 0;
        while (N % i == 0) {
            N /= i, c += 1;
        }
        factors.push_back({i, c});
    }
    if (N) {
        factors.push_back({N, 1});
    }
    return factors;
}
