#include "lab3_bp.h"
#include <stdlib.h>  

static Perceptron perceptron_table[NUM_PERCEPTRONS];
static int global_history[GHR_BITS] = {0};  

void perceptron_init(void) {//init
    for (int i = 0; i < NUM_PERCEPTRONS; ++i) {
        for (int j = 0; j < GHR_BITS; ++j) {
            perceptron_table[i].weights[j] = 0;  
        }
        perceptron_table[i].bias = 0; 
    }
}

//predict branch
int perceptron_predict(Bp_Data* bp_data, Op* op) {
    // Map the branch address to an index in the perceptron table
    int index = op->inst_info->addr % NUM_PERCEPTRONS;

    Perceptron* perceptron = &perceptron_table[index];
    int dot_product = perceptron->bias;

    for (int i = 0; i < GHR_BITS; ++i) {
        if (global_history[i]) {
            dot_product += perceptron->weights[i] * 1;
        } else {
            dot_product += perceptron->weights[i] * -1;
        }
    }

    if (dot_product >= 0) {
        return 1;  // Predict TAKEN
    } else {
        return 0;  // Predict NOT TAKEN
    }
}

// Update perceptron weights
void update_weights(Bp_Data* bp_data, Op* op, int outcome) {
    int index = op->inst_info->addr % NUM_PERCEPTRONS;
    Perceptron* perceptron = &perceptron_table[index];
    int dot_product = perceptron->bias;

    for (int i = 0; i < GHR_BITS; ++i) {
        if (global_history[i]) {
            dot_product += perceptron->weights[i] * 1;
        } else {
            dot_product += perceptron->weights[i] * -1;
        }
    }

    // Update if prediction was incorrect or barely correct
    int predicted_outcome = dot_product >= 0 ? 1 : 0;
    if ((predicted_outcome != outcome) || abs(dot_product) <= THRESHOLD) {
        for (int i = 0; i < GHR_BITS; ++i) {
            if (outcome) {
                if (global_history[i]) {
                    perceptron->weights[i] += 1;
                } else {
                    perceptron->weights[i] -= 1;
                }
            } else {
                if (global_history[i]) {
                    perceptron->weights[i] -= 1;
                } else {
                    perceptron->weights[i] += 1;
                }
            }
        }

        if (outcome) {
            perceptron->bias += 1;
        } else {
            perceptron->bias -= 1;
        }
    }

    // Update GHR
    for (int i = GHR_BITS - 1; i > 0; --i) {
        global_history[i] = global_history[i - 1];
    }
    global_history[0] = outcome;
}
