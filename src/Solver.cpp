#include "../include/Solver.hpp"

namespace pathfinder {
    Solver::Solver(Graph &graph)
    {
        _graph = &graph;
        _isEntriesSet = false;
    }

    double Solver::solve()
    {
        if (!_isEntriesSet) {
            std::cerr << "Please set source and destination nodes first" << std::endl;
            std::exit(84);
        }
        std::map<int, char> dict;
        for (int i = 0; i < 10; i++) {
            dict[i] = i + 65;
        }

        _graph->_entry->weight(0);
        while (!_graph->isInSubList(*_graph->_target)) {
            auto *min_node = _graph->getMinimalNode();
            if (!min_node)
                continue;
            _graph->addToSubNode(min_node);
            Node *tmp = const_cast<Node*>(min_node);
            tmp->updateNeighbors();
        }
        return _graph->_target->weight();
    }

    void Solver::setEntries(int source, int destination)
    {
        _graph->setEntries(source, destination);
        _isEntriesSet = true;
    }
}
