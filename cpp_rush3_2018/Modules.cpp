/*
** EPITECH PROJECT, 2019
** Modules.cpp
** File description:
** kevin
*/

#include "Modules.hpp"

Modules::~Modules()
{

}

const char *Modules::getHostName() const
{
    return std::getenv("HOSTNAME");
}

const char *Modules::getUserName() const
{
    return std::getenv("USER");
}

const char *Modules::getSysName() const
{
    struct utsname sysa;
    uname(&sysa);
    const char *lol =  sysa.sysname;
    return lol;
}

const char *Modules::getKernelV() const
{
    struct utsname sysa;
    uname(&sysa);
    const char *lol = sysa.release;
    return lol;
}

const char *Modules::getTimeDate() const
{
    auto end = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    return std::ctime(&end_time);
}
