#include <cmath>
#include "ProgressBar.h"

int main() {
    const int nEvents = 1e7;
    
    ProgressBar bar(nEvents);

    // symulacja zadania i aktualizacja postępu
    for (int i = 0; i < nEvents; ++i) {
        bar.refresh(i);

        double *z = new double;
        *z = pow(i, sin(cos(tan(pow(tan(sin(i / 10.0)), i)))));
        delete z;
    }
    
    std::cout << std::endl;
    return 0;
}