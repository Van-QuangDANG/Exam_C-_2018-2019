#include <iostream>
#include <cmath>
#include "LoanPayment.h"
#include "loop.h"

using namespace std;

int main() {
        int case_number;
        float r, PMT, PV, n;
        string y;

        cout << "(PMT/PV)=r. (1+ 1/((1+r)^n-1)" << "\n";
        cout << "Please choose the case of missing parameter " << "\n";
        cout << "Case 1: calculates PMT given n, PV, r" << "\n";
        cout << "Case 2: calculates PV given PMT, n, r" << "\n";
        cout << "Case 3: calculates n given PMT, PV, r" << "\n";
        cout << "Case 4: calculates r given PMT, n, PV" << "\n";


        do {
            cout << "Choose a case (enter a number between 1 and 4): " << "\n";
            cin >> case_number;

            switch (case_number) {
                case 1: {
                    cout << "You have chosen case " << case_number << "\n"
                         << "Please input n, r, PV (separated by spacing): " << "\n" << "For example: 5 0.02 5000"
                         << "\n";
                    cin >> n >> r >> PV;
                    cout << "\n" << "Results: PMT = " << r * PV * (1 + 1 / (pow((1 + r), n) - 1)) << "\n";
                }
                    break;
                case 2: {
                    cout << "You have chosen case " << case_number << "\n"
                         << "Please input n, r, PMT (separated by spacing): " << "\n" << "For example: 5 0.02 1060.79"
                         << "\n";
                    cin >> n >> r >> PMT;
                    cout << "\n" << "Results: PV = " << round(PMT / (r * (1 + 1 / (pow((1 + r), n) - 1)))) << "\n";
                }
                    break;
                case 3: {
                    cout << "You have chosen case " << case_number << "\n"
                         << "Please input PV, r, PMT (separated by spacing): " << "\n"
                         << "For example: 5000 0.02 1060.79" << "\n";
                    cin >> PV >> r >> PMT;
                    cout << "\n" << "Results: n = " << round(log(1 / (PMT / (r * PV) - 1) + 1) / log(1 + r)) << "\n";
                }
                    break;
                case 4: {
                    cout << "You have chosen case " << case_number << "\n"
                         << "Please input n, PV, PMT (separated by spacing): " << "\n" << "For example: 5 5000 1060.79"
                         << "\n";
                    cin >> n >> PV >> PMT;

                    //applying Secant algorithm
                    float NPV1, NPV2, r1 = 0.005, r2 = 0.06;
                    NPV1 = PMT / r1 * (1 - 1 / pow(1 + r1, n)) - PV;
                    NPV2 = PMT / r2 * (1 - 1 / pow(1 + r2, n)) - PV;
                    r = (r1 + (r2 - r1) * NPV1 / (NPV1 + abs(NPV2))) * 100;
                    cout << "\n" << "Results: yr = " << r << "%\n";
                }
                    break;
                default: {
                    cout << "Please try again and re-enter only a number (1-4)" << "\n";
                }
            }
            cout << "Do you want to start another calculation? (Y/N)" << "\n";
            cin >> y;
        }
        while (y=="Y"||y=="y");
        cout <<"Have a wonderful day! :)" <<"\n";

system("pause");
return 0;
}