//https://www.hackerrank.com/challenges/winning-lottery-ticket/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the winningLotteryTicket function below.
long winningLotteryTicket(vector<string> tickets) {
    int n = tickets.size();
    long ans = 0;
    vector<int> flags(n);

    for(int i = 0, k = 1; i < n; i++, k = 1){
       for(char c = '0'; c <= '9'; c++, k *= 2){
           if(tickets[i].find(c) != -1)
            flags[i] += k;
       }
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if( (flags[i] | flags[j]) == 1023)
                ans++;
        }
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> tickets(n);

    for (int i = 0; i < n; i++) {
        string tickets_item;
        getline(cin, tickets_item);

        tickets[i] = tickets_item;
    }

    long result = winningLotteryTicket(tickets);

    fout << result << "\n";

    fout.close();

    return 0;
}
