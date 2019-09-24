/*
** EPITECH PROJECT, 2019
** Modules.hpp
** File description:
** kevin
*/

#ifndef _MODULES_HPP__
#define _MODULES_HPP__

#include <cstdlib>
#include <sys/utsname.h>
#include <iostream>
#include <ctime>
#include <chrono>
#include "IMonitorModule.hpp"

class Modules : public IMonitorModule{
    public:
        virtual ~Modules();
        const char *getHostName() const;
        const char *getUserName() const;
        const char *getSysName() const;
        const char *getKernelV() const;
        const char * getTimeDate() const;
};

#endif
