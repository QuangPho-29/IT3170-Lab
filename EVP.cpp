#include <bits/stdc++.h>

using namespace std;

/*1	0-50 kWh	1.728	0-100 kWh	1.728
2	51-100 kWh	1.786	101-200 kWh	2.074
3	101-200 kWh	2.074	201-400 kWh	2.612
4	201-300 kWh	2.612	401-700 kWh	3.111
5	301-400 kWh	2.919	701 kWh trở lên	3.457
6  	401 kWh trở lên	3.015*/

int oldLevel[] = {400, 300, 200, 100, 50};
int newLevel[] = {700, 400, 200, 100};

float oldVal[] = {936.2, 644.3, 383.1, 175.7, 86.4, 0};
float newVal[] = {1835.9, 902.6, 380.2, 172.8, 0};

float oldCost[] = {3.015, 2.919, 2.612, 2.074, 1.786, 1.728};
float newCost[] = {3.457, 3.111, 2.612, 2.074, 1.728};

int main() {
    int n;
    cin >> n;
    int i = 0;
    float oldC = 0, newC = 0;
    while (oldC == 0){
        if (min(n, oldLevel[i]) == oldLevel[i]) {
            oldC = oldCost[i] * (n - oldLevel[i]) + oldVal[i];
        }
        i++;
    }
    i = 0;
    while (newC == 0){
        if (min(n, newLevel[i]) == newLevel[i]) {
            newC = newCost[i] * (n - newLevel[i]) + newVal[i];
        }
        i++;
    }
    cout << (oldC - newC) * 1.1;

    return 0;
}
