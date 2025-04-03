#include "../include/Graph.hpp"

namespace pathfinder {
    Graph::Graph(std::vector<Info> &nodes_data)
    {
        int id = 0;

        for (auto &node_data: nodes_data) {
            _nodes.push_back(Node(id));
            id++;
        }
        for (int i = 0; i < nodes_data.size(); i++) {
            for (auto &link: nodes_data[i].links) {
                _nodes[i].setLink(std::make_pair(link.first, &_nodes[link.second]));
            }
        }
    }

    void Graph::setEntries(int startIndex, int endIndex)
    {
        _entry = &_nodes[startIndex];
        _target = &_nodes[endIndex];
    }

    const Node* Graph::getMinimalNode() const
    {
        int index = -1;

        for (int i = 0; i < _nodes.size(); i++) {
            if (isInSubList(_nodes[i]))
                continue;
            if (index == -1) {
                index = i;
                continue;
            }
            if (_nodes[i].weight() < _nodes[index].weight()) {
                index = i;
            }
        }
        return index == -1 ? nullptr : &_nodes[index];
    }

    void Graph::addToSubNode(const Node *target)
    {
        if (isInSubList(*target))
            return;
        _subNodes.push_back(*target);
    }

    bool Graph::isInSubList(const Node &target) const
    {
        for (auto &nodes: _subNodes) {
            if (nodes == target)
                return true;
        }
        return false;
    }

    // void Graph::update(const Node *target)
    // {
        
    // }
}
