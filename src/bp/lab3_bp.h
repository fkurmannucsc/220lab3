#ifndef __LAB3_BP_H__
#define __LAB3_BP_H__

#include "bp.h"

#define PERCEPTRON_BP 1
#define PERCEPTRON_BP_GHR_BITS 32
#define PERCEPTRON_BP_NUM_PERCEPTRONS 256
#define PERCEPTRON_BP_THRESHOLD 32

// Number of global history bits, default: 32
// Number of perceptrons, default: 256
// Threshold for perceptron prediction, default: 32

// Example malloc initialization
// typedef struct Lab3_Percep_Bpc_Data {
//   Perceptron* conf_pt;
//   uns64 conf_perceptron_global_hist;       // global history only for confidence
//                                            // perceptron to support long history
//   uns64 conf_perceptron_global_misp_hist;  // global history only for confidence
//                                            // perceptron to support long history
// } Lab3_Percep_Bpc_Data;

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