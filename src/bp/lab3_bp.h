#ifndef __LAB3_BP_H__
#define __LAB3_BP_H__

#include "bp.h"

#define PERCEPTRON_BP TRUE
#define PERCEPTRON_BP_GHR_BITS 32
#define PERCEPTRON_BP_NUM_PERCEPTRONS 512
#define PERCEPTRON_BP_THRESHOLD 32

// Perceptron structure
typedef struct {
    int weights[PERCEPTRON_BP_GHR_BITS];
    int bias;
} Lab3Perceptron;

// Function declarations
void perceptron_init(void);  
int perceptron_predict(Bp_Data* bp_data, Op* op);
void update_weights(Bp_Data* bp_data, Op* op, int outcome);

#endif  // __LAB3_BP_H__