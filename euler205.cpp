#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    long long int total = 0;
    int SixSidedNumbers[36];
    int FourSidedNumbers[36];

    for (unsigned int i = 0; i < 36; i++)
    {
        SixSidedNumbers[i] = 0;
        FourSidedNumbers[i] = 0;
    }

    for (int i = 1; i < 5; i++)
        for (int j = 1; j < 5; j++)
            for (int k = 1; k < 5; k++)
                for (int l = 1; l < 5; l++)
                    for (int m = 1; m < 5; m++)
                        for (int n = 1; n < 5; n++)
                            for (int o = 1; o < 5; o++)
                                for (int p = 1; p < 5; p++)
                                    for (int q = 1; q < 5; q++)
                                        FourSidedNumbers[i + j + k + l + m + n + o + p + q - 1]++;

    for (int i = 1; i < 7; i++)
        for (int j = 1; j < 7; j++)
            for (int k = 1; k < 7; k++)
                for (int l = 1; l < 7; l++)
                    for (int m = 1; m < 7; m++)
                        for (int n = 1; n < 7; n++)
                            SixSidedNumbers[i + j + k + l + m + n - 1]++;

    for (unsigned int i = 0; i < 36; i++)
        for (unsigned int j = 0; j < i; j++)
            total += SixSidedNumbers[j] * FourSidedNumbers[i];

    // 12230590464 comes from 262144 * 46656, which is the total possible combinations for all the dice rolls.
    // 262144 = 4^9
    // 46656 = 6^6

    float val = (float) total / 12230590464;

    cout << "The probability that Pyramidal Pete beats Cubic Colin is : " << std::setprecision(7) << val << endl;
    system("pause");
    return 0;
}