#!/bin/bash
mkdir -p log
./build_sim.sh
./bin/social_network_impact config/social_config_base_scenario.json 2000
mv social_log.csv log/social_log_base_scenario_log.csv
echo "Base scenario done."