#include <bits/stdc++.h>
typedef unsigned long long int ll;

using namespace std;

// autosave : onFocusChange

int64_t V(int64_t N, int64_t P){
	int64_t S = 0;
    while (N%P == 0) { 
        S++;
        N = N/P;
    } 
	return S;
} 


int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    

    int T;
    cin >> T;
    //cout << "T : " << T <<endl;

    for(int t=0; t < T; t++){
        cout << "Case #" << t+1 << ": ";

        int a[3];
        // N: number of elements in the array
        // Q: number of queries
        // P: prime number

        
        cin >> a[0] >> a[1] >> a[2];
        //cout <<  "a[i] : " << a[0] << " and " << a[1] << " and " << a[2] <<endl;
        

        int A[a[0]];
        for (int i=0; i<a[0]; i++){
            cin >> A[i];
        }

        //cout <<  "A[i] : " << A[0] << " and " << A[1] << " and " << A[4] <<endl;

        for(int i=0; i<a[1]; i++){
            int p; cin >> p;
            
            if (p==1){
                int m[2];
                cin >> m[0] >> m[1];
                //cout << "p : " << p << " m[i] : " << m[0] << " and " << m[1] <<endl;
                //cout<<A[m[0]-1] << endl;
                A[m[0]-1]=m[1];
                //cout<<A[m[0]-1] << endl;
            }
            else{ // p ==2
                int S, L, R;
                cin >> S >> L >> R; // S, L, R
                //cout << "p : " << p << " S : " << S << " and " << L << " and " << R <<endl;

                int Sigma = 0;
                for (int j=L; j<=R; j++){
                    int64_t buffer = pow(A[j-1],S) - pow(A[j-1] % a[2],S);
                    //cout << pow(A[j-1],S)<< " " << pow(A[j-1] % a[2],S) << " " <<buffer <<endl;

                    if (buffer != 0){
                        Sigma += V(buffer,a[2]);
                    }
                    
                }
                cout << Sigma <<  " ";

            }
        }
        cout << endl;
    }
}
