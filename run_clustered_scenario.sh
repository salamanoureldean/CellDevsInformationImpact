#!/bin/bash
mkdir -p log
./build_sim.sh
./bin/social_network_impact config/social_config_clustered.json 1000
mv social_log.csv log/social_log_clustered_log.csv
echo "Clustered scenario done."