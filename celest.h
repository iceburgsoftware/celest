#pragma once
#include <iostream>
#include <syslog.h>
#include <signal.h>
#include <sys/wait.h>
#include <fstream>

#include <list>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVICE "echo"
#define BUF_SIZE 4096

using namespace std;

#ifndef HEY_H
#define HEY_H

string hey();

#endif

#ifndef ERROR_H
#define ERROR_H

void error(const char *msg);

#endif

#ifndef DOSTUFF_H
#define DOSTUFF_H

void dostuff(int, ostream&);

#endif