#!/bin/bash
mkdir -p log
./build_sim.sh
./bin/social_network_impact config/social_config_single_seed.json 1000
mv social_log.csv log/social_log_single_seed_log.csv
echo "Single-seed scenario done."