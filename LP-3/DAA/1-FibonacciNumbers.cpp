#include<bits/stdc++.h>
using namespace std;

int iterativeFibo(int n) {
    vector<int> fibo(n);
    fibo[0] = 0;
    fibo[1] = 1;

    for(int i=2; i<n; i++) 
        fibo[i] = fibo[i-1] + fibo[i-2];

    return fibo[n-1];
}

int recursiveFibo(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    
    return recursiveFibo(n - 1) + recursiveFibo(n - 2);
}

int main() {
    int choice;

    int n;
    cout<<"Enter the n (term):";
    cin>>n;

    bool repeat = true;
    while(repeat) {
        cout<<"Menu"<<endl;
        cout<<"1. Iterative Finonacci"<<endl;
        cout<<"2. Recursive Finonacci"<<endl;
        cout<<"3. Exit"<<endl;

        cout<<"Enter your choice:"<<flush;
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<iterativeFibo(n)<<endl;
                break;
            case 2:
                cout<<recursiveFibo(n)<<endl;
                break;
            case 3:
                cout<<"Exitting the code..."<<endl;
                repeat = false;
                break;
            default:
                break;
        }
    }
}