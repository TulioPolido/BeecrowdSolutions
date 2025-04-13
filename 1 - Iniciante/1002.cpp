#include <iostream>
#include <iomanip> // <- Necessário para setprecision e fixed

using namespace std;

int main() {
    double a;
    cin >> a;

    double area = 3.14159 * a * a;

    cout << fixed << setprecision(4);
    cout << "A=" << area << endl;

    return 0;
}
