

// TC - N*log(log(N))

// define explicitly
const int mxN = 1e7;

vector<int> prime(mxN, 1);

void sieve(){
    prime[0] = 0;
    prime[1] = 0;

    for (int i = 2; i * i < mxN; ++i){
        if (prime[i]){
            for(int j = i; j * i < mxN; ++j){
                prime[j * i] = 0;
            }
        }
    }
}
