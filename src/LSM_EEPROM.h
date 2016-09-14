/***
 *	Name: LSM_EEPROM.h
 *	Author: Albert Lloveras Carbonell (alloveras@salleurl.edu)
 *	Last Revision: 11/09/2016
 *	Description: This class defines a standard API for accessing
 *  the LSMaker EEPROM memories.
 *
***/

#ifndef _LSM_EEPROM_H_
#define _LSM_EEPROM_H_

#include <Arduino.h>
#include <avr/eeprom.h>
#include <stdint.h>

#include "External/LSMakerModule.h"

namespace LSM{

    class EEPROM : public LSMakerModule{

        public:
            static const uint8_t INTERNAL = 0x00;
            static const uint8_t LSMAKER = 0x01;

        //Singleton instance holder.
        private:
            static EEPROM *instance;

        private:
            uint8_t status = 0;

        private:
            //Private class constructor.
            EEPROM();
            void writeInternal(uint16_t addr, uint16_t size, void *data);
            void writeExternal(uint16_t addr, uint16_t size, void * data);
            void readInternal(uint16_t addr, uint16_t size, void *data);
            void readExternal(uint16_t addr, uint16_t size, void *data);

        public:

            //Singleton instance getter.
            static EEPROM * getInstance();

            //LSMakerModule interface implementation.
            void init();
            void execute();
            void destroy();
            String getModuleName();

            //EEPROM synchronous methods
            void write(uint8_t device, uint16_t addr, uint16_t size, void *data);
            void read(uint8_t device, uint16_t addr,uint16_t size, void *data);

            //Asynchronous operations finalization checker methods.
            bool isWriteFinished(int16_t operationId);
            bool isReadFinished(int16_t operationId);

    };
}


#endif