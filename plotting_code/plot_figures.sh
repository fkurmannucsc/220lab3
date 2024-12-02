#!/bin/bash
set -x #echo on
cd "$(dirname "$0")"

# Change this for new lab!
OUTPUT_DIR=/home/$USER/plot/$EXPERIMENT
SIM_PATH=/home/$USER/exp/simulations
DESCRIPTOR_PATH=/home/$USER/$EXPERIMENT.json

mkdir -p $OUTPUT_DIR

# Lab 1 plots.
# python3 plot_ipc.py -o $OUTPUT_DIR -d $DESCRIPTOR_PATH -s $SIM_PATH
# python3 plot_misprediction.py -o $OUTPUT_DIR -d $DESCRIPTOR_PATH -s $SIM_PATH
# python3 plot_icache_miss.py -o $OUTPUT_DIR -d $DESCRIPTOR_PATH -s $SIM_PATH
# python3 plot_dcache_miss.py -o $OUTPUT_DIR -d $DESCRIPTOR_PATH -s $SIM_PATH

# Lab 2 plots.
# python3 plot_lab2_ipc.py -o $OUTPUT_DIR -d $DESCRIPTOR_PATH -s $SIM_PATH
# python3 plot_lab2_dcache_miss.py -o $OUTPUT_DIR -d $DESCRIPTOR_PATH -s $SIM_PATH

# Lab 2 plots, part B.
# python3 plot_lab2_dcache_miss.py -o $OUTPUT_DIR -d $DESCRIPTOR_PATH -s $SIM_PATH
# python3 plot_lab2_ccc.py -o $OUTPUT_DIR -d $DESCRIPTOR_PATH -s $SIM_PATH
# python3 plot_lab2_ccc_rate.py -o $OUTPUT_DIR -d $DESCRIPTOR_PATH -s $SIM_PATH

# Lab 3 plots
python3 plot_lab3_ipc.py -o $OUTPUT_DIR -d $DESCRIPTOR_PATH -s $SIM_PATH
python3 plot_lab3_bp_on_path.py -o $OUTPUT_DIR -d $DESCRIPTOR_PATH -s $SIM_PATH
python3 plot_lab3_bp_off_path.py -o $OUTPUT_DIR -d $DESCRIPTOR_PATH -s $SIM_PATH
python3 plot_lab3_cycles.py -o $OUTPUT_DIR -d $DESCRIPTOR_PATH -s $SIM_PATH
python3 plot_lab3_fetch_off_path.py -o $OUTPUT_DIR -d $DESCRIPTOR_PATH -s $SIM_PATH
python3 plot_lab3_fetch_on_path.py -o $OUTPUT_DIR -d $DESCRIPTOR_PATH -s $SIM_PATH
python3 plot_lab3_st_nop.py -o $OUTPUT_DIR -d $DESCRIPTOR_PATH -s $SIM_PATH
