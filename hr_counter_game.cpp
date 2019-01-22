//https://www.hackerrank.com/challenges/counter-game/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the counterGame function below.
string counterGame(long n) {
    long player = 0, temp, len;

    while(n > 1){
        len = log(n)/log(2);
        temp = pow(2, len);
        if(n > temp) n -= temp;
        else n /= 2;
        player ^= 1;
    }

    if(player)
        return "Louise";
    else return "Richard";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = counterGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
