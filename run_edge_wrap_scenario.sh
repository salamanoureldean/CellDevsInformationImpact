#!/bin/bash
mkdir -p log
./build_sim.sh
./bin/social_network_impact config/social_config_edge_wrap.json 1000
mv social_log.csv log/social_log_edge_wrap_log.csv
echo "Edge-wrap scenario done."