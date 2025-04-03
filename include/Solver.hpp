#include "Lib.hpp"
#include "Graph.hpp"
#pragma once

namespace pathfinder {
    class Solver {
        public:
            Solver(Graph &graph);
            void setEntries(int source, int destination);
            double solve();
        private:
            Graph *_graph;
            bool _isEntriesSet;
    };
}
