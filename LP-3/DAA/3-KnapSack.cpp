#include<bits/stdc++.h>
using namespace std;

// pair<int, int> = {value, weight}
bool compare(pair<int,double> a, pair<int,double> b) {
    double v1 = (double) a.first / a.second;
    double v2 = (double) b.first / b.second;

    return v1 > v2;
}

double fractionalKnapSack(vector<pair<int, double>> weights, int& W) {
    sort(weights.begin(), weights.end(), compare);
    double ans = 0;

    for(int i=0; i<weights.size(); i++) {
        if(weights[i].second <= W) {
            ans += weights[i].first;
            W -= weights[i].second;
        } else {
            double valueW = (double) weights[i].first / weights[i].second;
            ans += valueW * W;
            W = 0;
            break;
        }
    }

    return ans;
}

int zeroOneKnapSack(vector<int> price, vector<int> weights, int W) {
    int n = price.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (weights[i - 1] <= j) 
                dp[i][j] = max(dp[i - 1][j], price[i - 1] + dp[i - 1][j - weights[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][W];
}

int main() {
    int n;
    cout<<"Enter number of elemets:";
    cin>>n;

    vector<pair<int, double>> weights(n);
    int W1;

    vector<int> price(n+1);
    vector<int> weight(n+1);
    int W2;
    price[0] = 0;
    weight[0] = 0;

    int choice;
    bool repeat = true;
    while(repeat) {
        cout<<"Menu"<<endl;
        cout<<"1. Fractional Knapsack"<<endl;
        cout<<"2. 0-1 Knapsack"<<endl;
        cout<<"3. Exit"<<endl;

        cout<<"Enter your choice:"<<flush;
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"Value, Weight"<<endl;
                for(int i=0; i<n; i++) 
                    cin>>weights[i].first>>weights[i].second;
                cout<<"Knapsack Capacity:";
                cin>>W1;
                cout<<fractionalKnapSack(weights, W1)<<endl;
                break;
            case 2:
                cout<<"Price:"<<endl;
                for(int i=1; i<=n; i++) 
                    cin>>price[i];
                cout<<"Weight:"<<endl;
                for(int i=1; i<=n; i++)
                    cin>>weight[i];
                cout<<"Knapsack Capacity:";
                cin>>W2;
                cout<<zeroOneKnapSack(price, weight, W2)<<endl;
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