#include "../include/Solver.hpp"

int main(int ac, char **av)
{
    pathfinder::InfoParser parser;
    auto result = parser.parse("wiki.txt");
    pathfinder::Graph graph(result);
    pathfinder::Solver solver(graph);
    solver.setEntries(0, 9);
    double solution = solver.solve();
    std::cout << "Minimal way is " << solution << std::endl;
    return 0;
}
