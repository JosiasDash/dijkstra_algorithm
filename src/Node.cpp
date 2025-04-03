#include "../include/Node.hpp"

namespace pathfinder {
    Node::Node(int id)
    {
        _weight = infinite;
        _uniqueID = id;
    }

    void Node::setLink(std::pair<double, Node*> link)
    {
        for (auto &_link: _links) {
            if (_link.second.get() == link.second) {
                std::cout << "Error cover" << std::endl;
                return;
            }
        }
        _links.push_back(std::make_pair(link.first, std::shared_ptr<Node>(link.second, [](void *){})));
    }

    void Node::weight(double new_weight)
    {
        if (new_weight < _weight)
            _weight = new_weight;
    }

    double Node::weight() const
    {
        return _weight;
    }

    int Node::ID() const
    {
        return _uniqueID;
    }

    bool Node::operator==(const Node &target) const
    {
        return _uniqueID == target.ID();
    }

    void Node::updateNeighbors()
    {
        for (auto &link: _links) {
            link.second->weight(_weight + link.first);
        }
    }
}
