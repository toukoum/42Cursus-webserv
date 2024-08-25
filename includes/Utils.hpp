
#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <cstdarg>
#include <stdint.h>
#include <sstream>
#include <fstream>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <filesystem>



#include "Logger.hpp"
#include "ConfigParser.hpp"
#include "ErrorPage.hpp"

/* UTILS */
void printMsg(std::ostream &os, const char *msg, ...);
bool directoryExist(const char *path);
bool fileExist(const std::string &name);
std::string trimLine(std::string &line);
std::vector<std::string> split(std::string s, std::string delimiter);
std::string unsignedIntToString(unsigned int value);
std::string intToString(int value);

int protectedCall(int ret, std::string msg, bool isFatal = true);

std::string extractIp(std::string ipPort);
unsigned int extractPort(std::string ipPort);
bool isEmptyFile();
std::string getErrorMessage(int code);
std::string intToHexa(ssize_t num);
std::string getMimeType(const std::string &path);

// epoll utils
void addSocketEpoll(int epollFD, int sockFD, uint32_t flags);
void modifySocketEpoll(int epollFD, int sockFD, uint32_t flags);
void deleteSocketEpoll(int epollFD, int sockFD);

// list directory
std::string buildPage(std::vector<std::string> files, std::string path, std::string root);
void cleanPath(std::string& path);
bool is_path_within_root(const std::string& root, std::string& path) ;
std::string listDirectory(std::string path, std::string root);



#endif // UTILS_HPP