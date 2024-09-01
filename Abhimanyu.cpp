#include <bits/stdc++.h>
using namespace std;

class Mahabharat
{
public:
    int InitialEnergy;

    Mahabharat(int p)
    {
        // Store Energy Of Abhimanyu For Refilling Purpose
        InitialEnergy = p;
    }

    bool Chakravyuha(vector<int> &circle, int i, int p, int a, int b, bool isSkip = false)
    {
        // Base Case
        if (i == 11)
        {
            return true;
        }

        // Calculate The Total Enemy Power As 3rd And 7th Circle Can Regenerate The Power
        int EnemyEnergy = circle[i];
        if (isSkip == false && (i + 1) % 4 == 0)
        {
            // Add The Power Of 3rd & 7th Circle If Not Skipped
            EnemyEnergy += circle[i - 1];
        }

        // Check If Abhimanyu Can Defeat The Enemy
        if (p >= EnemyEnergy)
        {
            // Abhimanyu Can Fight The Enemy or Skip The Circle
            bool isFraq = false, opt1 = false, opt2 = false;

            // If Abhimanyu Fight The Enemy Of 3rd & 7th Circle
            if (i == 2 || i == 6)
            {
                if (circle[i] % 2 != 0)
                {
                    isFraq = true;
                }
                circle[i] /= 2;
            }

            // Abhimanyu Fight The Enemy
            opt1 = Chakravyuha(circle, i + 1, p - EnemyEnergy, a, b);

            // If Abhimanyu Skip The Circle Then Restore The Power Of 3rd & 7th Circle
            if (i == 2 || i == 6)
            {
                circle[i] *= 2;
                if (isFraq)
                {
                    circle[i]++;
                }
            }

            // If Abhimanyu Can Skip The Circle
            if (a > 0)
            {
                opt2 = Chakravyuha(circle, i + 1, p, a - 1, b, true);
            }

            return opt1 || opt2;
        }

        // If Abhimanyu Can't Defeat The Enemy
        else
        {
            // Check If Enemy Power Is Greater Than Initial Power Of Abhimanyu That Means Abhimanyu Can Never Defeat The Enemy
            if (EnemyEnergy > this->InitialEnergy)
            {
                // Check If Abhimanyu Can Skip The Circle
                if (a > 0)
                {
                    return Chakravyuha(circle, i + 1, p, a - 1, b);
                }

                // Otherwise Abhimanyu Can't Defeat The Enemy
                else
                {
                    return false;
                }
            }

            // Abhimanyu Power Is Less Than Enemy Power
            else
            {
                if (a <= 0 && b <= 0)
                {
                    // Abhimanyu Can't Skip The Circle Or Refill The Energy
                    return false;
                }
                else
                {
                    bool opt1 = false, opt2 = false, isFraq = false;

                    // If Abhimanyu Refill The Energy
                    if (b > 0)
                    {
                        // Check After Refilling Fight With Enemy Of 3rd & 7th Circle
                        if (i == 2 || i == 6)
                        {
                            if (circle[i] % 2 != 0)
                            {
                                isFraq = true;
                            }
                            circle[i] /= 2;
                        }

                        // Abhimanyu Fight The Enemy
                        opt1 = Chakravyuha(circle, i + 1, this->InitialEnergy - EnemyEnergy, a, b - 1);

                        // Restore The Power Of 3rd & 7th Circle If Skipped
                        if (i == 2 || i == 6)
                        {
                            circle[i] *= 2;
                            if (isFraq)
                            {
                                circle[i]++;
                            }
                        }
                    }

                    // If Abhimanyu Skip The Circle
                    if (a > 0)
                    {
                        // Check After Skipping Fight With Enemy Of 3rd & 7th Circle
                        if (i == 2 || i == 6)
                        {
                            opt2 = Chakravyuha(circle, i + 1, p, a - 1, b, true);
                        }

                        // Otherwise Skip The Circle
                        else
                        {
                            opt2 = Chakravyuha(circle, i + 1, p, a - 1, b);
                        }
                    }

                    return opt1 || opt2;
                }
            }
        }

        return true;
    }
};

int main()
{
    int p, a, b;
    vector<int> circle(11);

    cout << "Enter The Energy Of Abhimanyu: ";
    cin >> p;

    cout << "Enter Number Of Time Circle Can Be Skipped: ";
    cin >> a;

    cout << "Enter Number Of Time Energy Can Refill: ";
    cin >> b;

    cout << "Enter The Energy Of Each Circle: ";
    for (int i = 0; i < 11; i++)
    {
        cin >> circle[i];
    }

    // Create Object Of Mahabharat Class
    Mahabharat War = Mahabharat(p);

    // Check If Abhimanyu Can Come Out Of Chakravyuh
    bool Result = War.Chakravyuha(circle, 0, p, a, b);

    if (Result)
    {
        cout << "YES! Abhimanyu Came Out Of Chakravyuh" << endl;
    }
    else
    {
        cout << "NO! Abhimanyu Died In Chakravyuh" << endl;
    }

    return 0;
}