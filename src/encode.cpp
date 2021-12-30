//
// Created by 97252 on 12/29/2021.
//

#include <string>
#include <vector>
#include <zconf.h>
#include <rpcndr.h>
#include <iostream>
#include "../include/encode.h"
#include "../include/connectionHandler.h"

void shortToBytes(short opcode, Byte i);

void encoder () {
     while (true) {
         std::string s;
         std::cin >> s;
         std::vector<std::string> argsVec = s.split();
         short Opcode = encode::getOpcode(argsVec.at(0));
         char (*b) = new char[2];
         shortToBytes(Opcode, *b);
         ConnectionHandler::sendBytes(b, 2);

     }
 }

void encode::shortToBytes(short num, char* bytesArr){
    bytesArr[0] = ((num >> 8) & 0xFF);
    bytesArr[1] = (num & 0xFF);
}
 short encode:: getOpcode(std::string str){
    if(str=="REGISTER")
        return 1;
     if(str=="LOGIN")
         return 2;
     if(str=="LOGOUT")
         return 3;
     if(str=="FOLLOW")
         return 4;
     if(str=="POST")
         return 5;
     if(str=="PM")
         return 6;
     if(str=="LOGSTAT")
         return 7;
     if(str=="STAT")
         return 8;
     if(str=="NOTIFICATION")
         return 9;
     if(str=="BLOCK")
         return 12;
     else
         return -1;
};

