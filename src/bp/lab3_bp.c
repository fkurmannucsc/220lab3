#include "lab3_bp.h"
#include <stdlib.h>
#include <stdio.h>

static Lab3Perceptron __attribute__((unused)) perceptron_table[PERCEPTRON_BP_NUM_PERCEPTRONS];
static int __attribute__((unused)) global_history[PERCEPTRON_BP_GHR_BITS] = {0};

// Init
void perceptron_init(void) {
    for (int i = 0; i < PERCEPTRON_BP_NUM_PERCEPTRONS; ++i) {
        perceptron_table[i].weights = (int*)malloc(
        sizeof(int) * (PERCEPTRON_BP_GHR_BITS));
        for (int j = 0; j < PERCEPTRON_BP_GHR_BITS; ++j) {
            perceptron_table[i].weights[j] = 0;  
        }
        perceptron_table[i].bias = 0; 
    }
}

// Predict branch
int perceptron_predict(Bp_Data* bp_data, Op* op) {
    // Map the branch address to an index in the perceptron table
    int index = op->inst_info->addr % PERCEPTRON_BP_NUM_PERCEPTRONS;

    Lab3Perceptron* perceptron = &perceptron_table[index];
    int dot_product = perceptron->bias;

    for (int i = 0; i < PERCEPTRON_BP_GHR_BITS; ++i) {
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
    int index = op->inst_info->addr % PERCEPTRON_BP_NUM_PERCEPTRONS;
    Lab3Perceptron* perceptron = &perceptron_table[index];
    int dot_product = perceptron->bias;

    for (int i = 0; i < PERCEPTRON_BP_GHR_BITS; ++i) {
        if (global_history[i]) {
            dot_product += perceptron->weights[i] * 1;
        } else {
            dot_product += perceptron->weights[i] * -1;
        }
    }

    // Update if prediction was incorrect or barely correct
    int predicted_outcome = dot_product >= 0 ? 1 : 0;
    if ((predicted_outcome != outcome) || abs(dot_product) <= PERCEPTRON_BP_THRESHOLD) {
        for (int i = 0; i < PERCEPTRON_BP_GHR_BITS; ++i) {
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
    for (int i = PERCEPTRON_BP_GHR_BITS - 1; i > 0; --i) {
        global_history[i] = global_history[i - 1];
    }
    global_history[0] = outcome;
}
