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

    std::ifstream input_stream(path.c_str());
    std::stringstream sstr;

    while(input_stream >> sstr.rdbuf());

    return sstr.str();
}

string_vector fileutils::read_file_lines(const std::string &path)
{
    if(!fileutils::exists(path))
        return string_vector();

    std::ifstream input_stream(path.c_str());
    std::string current_line;

    string_vector return_vector;

    while (std::getline(input_stream, current_line))
        return_vector.push_back(current_line);

    return return_vector;
}

std::string fileutils::combine_path(const std::string &base_path, const std::string &append)
{
    boost::filesystem::path path_base(base_path);
    boost::filesystem::path path_rel(append);

    boost::filesystem::path combined_path = path_base / path_rel;

    return combined_path.string();
}

string_vector fileutils::get_dir_dirs(const std::string &dir_path)
{
    if(!fileutils::exists(dir_path))
        return string_vector();

    if(!fileutils::is_directory(dir_path))
        return string_vector();

    string_vector return_vector;

    boost::filesystem::directory_iterator end_it;
    boost::filesystem::directory_iterator dir_it(dir_path);

    for(; dir_it != end_it; ++dir_it)
    {
        if(!fileutils::is_directory(dir_it->path().string()))
            continue;

        return_vector.push_back(
            dir_it->path().string()
        );
    }

    return return_vector;
}

bool fileutils::is_directory(const std::string &path)
{
    return boost::filesystem::is_directory(path);
}

bool fileutils::is_file(const std::string &path)
{
    return boost::filesystem::is_regular_file(path);
}

} // namespace pw
