#include "Lib.hpp"
#pragma once

namespace pathfinder {
    struct Info {
        std::vector<std::pair<double, std::size_t>> links;
    };

    class InfoParser {
        public:
            std::vector<Info> parse(const std::string filepath);

    };

}

/*
{
12.3 1
}
*/
