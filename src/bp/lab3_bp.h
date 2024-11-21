#ifndef __LAB3_BP_H__
#define __LAB3_BP_H__

#include "bp.h"  

#define GHR_BITS 32  // not sure about these 3 values
#define NUM_PERCEPTRONS 256  // Number of perceptrons 
#define THRESHOLD 32  // Threshold for perceptron prediction

// Perceptron structure
typedef struct {
    int weights[GHR_BITS];  
    int bias;               
} Perceptron;

// Function declarations
void perceptron_init(void);  
int perceptron_predict(Bp_Data* bp_data, Op* op);  
void update_weights(Bp_Data* bp_data, Op* op, int outcome);  

#endif  // __LAB3_BP_H__