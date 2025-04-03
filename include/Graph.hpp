#include "Node.hpp"
#include "Info.hpp"
#pragma once

namespace pathfinder {
    class Graph {
        public:
            Graph(std::vector<Info> &nodes_data);
            void setEntries(int startIndex, int endIndex);
            const Node* getMinimalNode() const;
            void addToSubNode(const Node *target);
            bool isInSubList(const Node &target) const;
            // void update(const Node *target);
            Node *_entry;
            Node *_target;

        private:
            std::vector<Node> _nodes;
            std::vector<Node> _subNodes;

            // private methods
    };
}
