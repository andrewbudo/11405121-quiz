#include <iostream>
#include <string>
#include<vector>

using namespace std;

int main()
{
    size_t k;
    string s;
    cin >> k >> s;

    bool lucky = true;
    int diff(0);
    k /= 2;
    for (size_t i = 0; i < k; ++i)
    {
        if ((s[i] != '4' && s[i] != '7') || (s[k+i] != '4' && s[k+i] !='7'))
        {
            lucky = false;
            break;
        }
        diff += (s[i] - s[k+i]);
    }
    lucky = lucky && (diff == 0);
    cout << (lucky ? "Y" : "N") << endl;
    return 0;
}
