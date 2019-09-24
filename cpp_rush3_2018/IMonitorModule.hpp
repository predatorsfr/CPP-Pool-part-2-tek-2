/*
** EPITECH PROJECT, 2019
** IMonitorModule.hpp
** File description:
** kevin
*/

#ifndef _IMONITORMODULE_HPP__
#define _IMONITORMODULE_HPP__

class IMonitorModule {
    public:
//        virtual ~IMonitorModule();
        virtual const char *getHostName() const = 0;
        virtual const char *getUserName() const = 0;
        virtual const char *getSysName() const = 0;
        virtual const char *getKernelV() const = 0;
        virtual const char *getTimeDate() const = 0;
};

#endif
