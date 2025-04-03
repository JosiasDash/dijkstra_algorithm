#include "Lib.hpp"
#pragma once

namespace pathfinder {
    const double infinite = std::numeric_limits<double>::infinity();

    class Node {
        public:
            Node(int id);
            // Node(double weight, std::vector<std::pair<double, Node *>> links);
            void setLink(std::pair<double, Node*> link);
            void weight(double new_weight);
            double weight() const;
            int ID() const;
            bool operator==(const Node &target) const;
            void updateNeighbors();
        private:
            double _weight;
            int _uniqueID;
            std::list<std::pair<double, std::shared_ptr<Node>>> _links;
    };
}
