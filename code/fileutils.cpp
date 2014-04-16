#include "fileutils.h"

#include <boost/filesystem.hpp>
#include <iostream>
#include <sstream>
#include <fstream>

namespace pw
{

bool fileutils::exists(const std::string &path)
{
    if(path.empty())
        return false;

    return boost::filesystem::exists(path);
}

std::string fileutils::read_file_all(const std::string &path)
{
    if(!fileutils::exists(path))
        return "";

    std::ifstream input_stream(path);
    std::stringstream sstr;

    while(input_stream >> sstr);

    return sstr.str();
}

string_vector fileutils::read_file_lines(const std::string &path)
{
    if(!fileutils::exists(path))
        return string_vector();

    std::ifstream input_stream(path);
    std::string current_line;

    string_vector return_vector;

    while (getline(input_stream, line))
        return_vector.push_back(line);

    return return_vector;
}

std::string fileutils::combine_path(const std::string &base_path, const std::string &append)
{
    boost::filesystem::path path_base(base_path);
    boost::filesystem::path path_rel(append);

    boost::filesystem::path combined_path = path_base / path_rel;

    return combined_path.string();
}

} // namespace pw
