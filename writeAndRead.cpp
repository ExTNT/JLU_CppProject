#include "writeAndread.h"
#include <iostream>
#include <fstream>
#include "json.hpp"
#include <string>

using json = nlohmann::json;

void writeUsersToFile(const std::string& filePath, const std::unordered_map<std::string, user_dyh>& userls) {
    json j;
    for (const auto& i : userls) {
        j.push_back(i.second.toJson());
    }
    std::ofstream outFile(filePath);
    if (!outFile) {
        std::cerr << "Error: Unable to open file for writing " << filePath << std::endl;
        return;
    }
    outFile << j.dump(4);
    outFile.close();
    std::cout << "Data sucessfully written to " << filePath << std::endl;
    return;
}

void writeVsersToFile(const std::string& filePath, const std::unordered_map<std::string, vxUser_dyh>& vserls) {
    json j;
    for (const auto& i : vserls) {
        j.push_back(i.second.toJson());
    }
    std::ofstream outFile(filePath);
    if (!outFile) {
        std::cerr << "Error: Unable to open file for writing " << filePath << std::endl;
        return;
    }
    outFile << j.dump(4);
    outFile.close();
    std::cout << "Data sucessfully written to " << filePath << std::endl;
    return;
}

void writeGroupsToFile(const std::string& filePath, const std::unordered_map<std::string, QQGroup_dyh>& groupls) {
    json j;
    for (const auto& i : groupls) {
        j.push_back(i.second.toJson());
    }
    std::ofstream outFile(filePath);
    if (!outFile) {
        std::cerr << "Error: Unable to open file for writing " << filePath << std::endl;
        return;
    }
    outFile << j.dump(4);
    outFile.close();
    std::cout << "Data sucessfully written to " << filePath << std::endl;
    return;
}

std::unordered_map < std::string, QQGroup_dyh> readGroupsFromFile(const std::string& filePath) {
    std::unordered_map < std::string, QQGroup_dyh> groupls;
    std::ifstream inFile(filePath);
    if (!inFile) {
        std::cerr << "Error: Unable to open file for reading " << filePath << std::endl;
        return groupls;
    }
    json j;
    inFile >> j;
    inFile.close();
    std::cout << "Data sucessfully read from " << filePath << std::endl;
    for (const auto& i : j) {
        QQGroup_dyh temp;
        temp.fromJson(i);
        groupls.insert({temp.getId(), temp});
    }
    return groupls;
}

std::unordered_map<std::string, user_dyh> readUsersFromFile(const std::string& filePath) {
    std::unordered_map<std::string, user_dyh> userls;
    std::ifstream inFile(filePath);
    if (!inFile) {
        std::cerr << "Error: Unable to open file for reading " << filePath << std::endl;
        return userls;
    }
    json j;
    inFile >> j;
    inFile.close();
    std::cout << "Data sucessfully read from " << filePath << std::endl;
    for (const auto& i : j) {
        user_dyh temp;
        temp.fromJson(i);
        userls.insert({temp.getId(), temp});
    }
    return userls;
}

std::unordered_map<std::string, vxUser_dyh> readVsersFromFile(const std::string& filePath) {
    std::unordered_map<std::string, vxUser_dyh> vserls;
    std::ifstream inFile(filePath);
    if (!inFile) {
        std::cerr << "Error: Unable to open file for reading " << filePath << std::endl;
        return vserls;
    }
    json j;
    inFile >> j;
    inFile.close();
    std::cout << "Data sucessfully read from " << filePath << std::endl;
    for (const auto& i : j) {
        vxUser_dyh temp;
        temp.fromJson(i);
        vserls.insert({temp.getId(), temp});
    }
    return vserls;
}

std::priority_queue<int, std::vector<int> > readIdsFromFile(const std::string& filePath) {
    std::priority_queue<int, std::vector<int> > ids;
    std::ifstream inFile(filePath);
    if (!inFile) {
        std::cerr << "Error: Unable to open file for reading " << filePath << std::endl;
        return ids;
    }
    json j;
    inFile >> j;
    inFile.close();
    std::cout << "Data sucessfully read from " << filePath << std::endl;
    for (const auto& i : j) {
        int temp;
        std::string str;
        i.at("id").get_to(str);
        temp = std::stoi(str);
        ids.push(temp);
    }
    return ids;
}

std::priority_queue<int, std::vector<int> > readVIdsFromFile(const std::string& filePath) {
    std::priority_queue<int, std::vector<int> > ids;
    std::ifstream inFile(filePath);
    if (!inFile) {
        std::cerr << "Error: Unable to open file for reading " << filePath << std::endl;
        return ids;
    }
    json j;
    inFile >> j;
    inFile.close();
    std::cout << "Data sucessfully read from " << filePath << std::endl;
    for (const auto& i : j) {
        int temp;
        std::string str;
        i.at("id").get_to(str);
        temp = std::stoi(str);
        ids.push(temp);
    }
    return ids;
}

std::priority_queue<int, std::vector<int> >readGroupsIdsFromFile(const std::string& filePath) {
    std::priority_queue<int, std::vector<int> > ids;
    std::ifstream inFile(filePath);
    if (!inFile) {
        std::cerr << "Error: Unable to open file for reading " << filePath << std::endl;
        return ids;
    }
    json j;
    inFile >> j;
    inFile.close();
    std::cout << "Data sucessfully read from " << filePath << std::endl;
    for (const auto& i : j) {
        int temp;
        std::string str;
        i.at("id").get_to(str);
        temp = std::stoi(str);
        ids.push(temp);
    }
    return ids;
}
