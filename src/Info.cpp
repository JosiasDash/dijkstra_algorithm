#include "../include/Info.hpp"

namespace pathfinder {
    std::vector<Info> InfoParser::parse(const std::string filepath) {
        std::ifstream stream(filepath);
        std::string line;
        bool node_start = false;
        Info node_info;
        std::vector<Info> nodes;
        // std::stringstream str_stream;
        double offset = 0;
        std::size_t index = 0;

        if (!stream.is_open()) {
            std::cerr << "Failed to open parser file " << filepath << std::endl;
            std::exit(84);
        }
        while (std::getline(stream, line)) {
            if (line[0] == '#')
                continue;
            if (line == "}" && node_start) {
                node_start = false;
                nodes.push_back(node_info);
                node_info.links.clear();
                // std::cout << "<---\n\n";
                continue;
            }
            if (line == "{") {
                node_start = true;
                // std::cout << "--->\n";
                continue;
            }
            if (node_start) {
                std::stringstream str_stream(line);
                str_stream >> offset >> index;
                // std::cout << offset << ", " << index << std::endl;
                node_info.links.push_back(std::make_pair(offset, index));
            }
        }
        if (nodes.empty())
            std::cout << "Warning: Nodes list is empty" << std::endl;
        stream.close();
        return nodes;
    }
}

// int main(int ac, char **av)
// {
//     pathfinder::InfoParser parser;
//     auto result = parser.parse("test.txt");

//     std::cout << "Result size: " << result.size() << std::endl;
//     return 0;
// }
