#include <bits/stdc++.h>
typedef unsigned long long int ll;

using namespace std;

int64_t d(int64_t i,int64_t j){
    return abs(i-j);
}

// autosave : onFocusChange


int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    //main

    int64_t t;
    int64_t i = 1;
    
    cin >> t;
    
    while(t--) {

        string h;
        int64_t n;

        cin>> n >> h;

        std::vector<int64_t> PHouse;

        // 1 : Trouver l'emplacement des poubelles 
        for (int64_t i=0; i<h.length(); i++){
            if (h[i]=='1'){
                PHouse.push_back(i);
            }
        }
        

        // On a la position de toutes les poubelles
        int64_t pinf = PHouse[0];
        int64_t psup;
        
        if (PHouse.size()==1){
            psup = pinf;
        }
        else{
            psup = PHouse[1];
        }
        
 
        

        int64_t S = 0;
        int64_t u=2;

        for (int64_t i=0; i<h.length(); i++){
            if (h[i]=='0'){

                while (psup<i){
                    if (u<PHouse.size()){
                        pinf = psup;
                        psup = PHouse[u];
                        u++;
                    }
                    else{
                        pinf = psup;
                        psup = pow(10,9);
                    }
                }

                if (abs(i-psup)<abs(i-pinf)){
                    S+=d(i,psup);
                }
                else{
                    S+=d(i,pinf);
                }

            }
            /*
            cout << "i : " << i << " and pinf : " << pinf <<
             " and psup : " << psup << " and S : " << S <<endl;
             */
            
        }

        //cout << "S : " << S <<endl;
        cout << "Case #" << i << ": " << S <<endl;
        i++;
        
        
    }
}
