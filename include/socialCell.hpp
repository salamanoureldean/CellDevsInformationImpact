#ifndef SOCIAL_CELL_HPP_
#define SOCIAL_CELL_HPP_

#include <cadmium/modeling/celldevs/grid/cell.hpp>
#include "socialState.hpp"

using namespace cadmium::celldevs;

class socialCell : public GridCell<socialState, double> {
public:
    socialCell(const std::vector<int>& id, 
               const std::shared_ptr<const GridCellConfig<socialState, double>>& config
              ): GridCell<socialState, double>(id, config) {}

    [[nodiscard]] socialState localComputation(
    socialState state,
    const std::unordered_map<std::vector<int>, NeighborData<socialState, double>>& neighborhood
) const override {

    int neighborsWithMessage = 0;

    for (const auto& [neighborId, neighborData] : neighborhood) {
        if (neighborData.state == nullptr) continue;

        int nVal = neighborData.state->value;

        // Skip center cell if it appears in the neighborhood map
        if (neighborId == std::vector<int>{0, 0}) continue;

        if (nVal == 1 || nVal == 2) {
            neighborsWithMessage++;
        }
    }

    if (state.value == 0 && neighborsWithMessage == 1) {
        return socialState(1);
    }

    if (state.value == 1 && neighborsWithMessage >= 2 && neighborsWithMessage <= 4) {
        return socialState(2);
    }

    return state;
}

    // Return the 100ms delay
    [[nodiscard]] double outputDelay(const socialState& state) const override {
        return 100.0;
    }
};

#endif