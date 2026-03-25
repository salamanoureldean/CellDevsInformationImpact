#include <cadmium/modeling/celldevs/grid/coupled.hpp>
#include <cadmium/simulation/logger/csv.hpp>
#include <cadmium/simulation/root_coordinator.hpp>
#include "../include/socialCell.hpp"

using namespace cadmium::celldevs;
using namespace cadmium;

std::shared_ptr<GridCell<socialState, double>> addGridCell(const coordinates & cellId, 
    const std::shared_ptr<const GridCellConfig<socialState, double>>& cellConfig) {
    if (cellConfig->cellModel == "social") {
        return std::make_shared<socialCell>(cellId, cellConfig);
    }
    throw std::bad_typeid();
}

int main(int argc, char ** argv) {
    std::string configFilePath = (argc > 1) ? argv[1] : "config/social_config.json";
    double simTime = (argc > 2) ? std::stod(argv[2]) : 500;

    auto model = std::make_shared<GridCellDEVSCoupled<socialState, double>>("socialNetwork", addGridCell, configFilePath);
    model->buildModel();

    auto rootCoordinator = RootCoordinator(model);
    rootCoordinator.setLogger<CSVLogger>("social_log.csv", ";");
    rootCoordinator.start();
    rootCoordinator.simulate(simTime);
    rootCoordinator.stop();
    return 0;
}