//https://www.hackerrank.com/challenges/and-product/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the andProduct function below.
long andProduct(long a, long b) {
    int ax = log(a)/log(2), bx = log(b)/log(2);

    //return when calculating is invaluable.
    if(ax - bx != 0)
    return 0;

    //initialize
    long ans = a & b;
    //erase all bits from 1 to difference of two numbers.
    for(int i = abs(a-b), x = 1; x <= i; x <<= 1){
        ans |= x;
        ans ^= x;
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int n_itr = 0; n_itr < n; n_itr++) {
        string ab_temp;
        getline(cin, ab_temp);

        vector<string> ab = split_string(ab_temp);

        long a = stol(ab[0]);

        long b = stol(ab[1]);

        long result = andProduct(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
