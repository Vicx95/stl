#include "AppendNewRecipe.hpp"
#include <algorithm>
#include <fstream>
#include <map>

static const std::map<char, std::string> quantities{{'g', "gram"},
                                                    {'s', "szklanka(i)"},
                                                    {'m', "mililitrow"}};

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<std::size_t, char>>& amount) {
    std::string fileName = "recipes.txt";
    std::fstream recipesStream(fileName, recipesStream.out | recipesStream.app);
    if (!recipesStream.is_open()) {
        return false;
    }
    recipesStream << FormatRecipit(steps, ingredients, amount).str();
    recipesStream.close();
    return true;
}
