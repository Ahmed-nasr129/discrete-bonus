#include <bits/stdc++.h>
using namespace std;

signed main() {
    int primes[100000];
    for(int i=0;i<100000;i++) {
        primes[i] = 1;
    }
    vector <int> primesOnly;
    primes[0]=0;
    primes[1]=0;
    for(int i=2;i*i<100000;i++) {
        if(primes[i]==1) {
            for(int j=i*i;j<100000;j+=i) {
                primes[j]=0;
            }
        }
    }
    for(int i=2;i<100000;i++) {
        if(primes[i]==1)
            primesOnly.push_back(i);
    }

    int acc=1,s=primesOnly.size();
    cout<<"primes of Set S={";
    for(int i=0;i<s;i++) {
        acc*=primesOnly[i];
        cout<<primesOnly[i];
        int finall=primesOnly[primesOnly.size()-1];
        if(acc<=finall) {
            if(!binary_search(primesOnly.begin(),primesOnly.end(),acc+1)) {
                cout<<"}\nN = ";
                cout<<acc+1<<endl;
                for(int j=0;j<s;j++){
                    if((acc+1)%primesOnly[j]==0) {
                        cout<<"P1 = "<<primesOnly[j]<<", P2 = "<<(acc+1)/primesOnly[j]<<endl;
                        break;
                    }
                }

                return 0;
            }
            cout<<",";
        }else {
            cout<<"No solution"<<endl;
        }
    }
}
