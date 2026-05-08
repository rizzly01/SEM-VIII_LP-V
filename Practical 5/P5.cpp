#include <iostream>
#include <omp.h>
using namespace std;
#define N 6

int main() {

    // Training data (AI/ML dataset)
    float X[N] = {1, 2, 3, 4, 5, 6};
    float Y[N] = {2, 9, 6, 3, 10, 12};
    float W = 0.2;   // model weight
    float learning_rate = 0.01;
    float gradient = 0;

    // 🔷 HPC Step 1: Parallel prediction + error calculation
    #pragma omp parallel for reduction(+:gradient)
    for (int i = 0; i < N; i++) {
        float prediction = W * X[i];
        float error = prediction - Y[i];
        gradient += error * X[i];
    }
    // 🔷 Update model weight (ML training step)
    W = W - learning_rate * (gradient / N);
    cout << "Updated Weight (After HPC Training Step): " << W << endl;
    return 0;
}