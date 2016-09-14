#include "LSM_EEPROM.h"

using namespace LSM;

EEPROM *EEPROM::instance = NULL;

//Private constructor (avoid class to be instantiated)
EEPROM::EEPROM(){}

//Singleton instance getter.
EEPROM * EEPROM::getInstance(){
    if(instance == NULL){
        instance = new EEPROM();
    }
    return instance;
}

//LSMakerModule interface implementation
void EEPROM::init(void){
}

void EEPROM::execute(void){

}

void EEPROM::destroy(void){
}

String EEPROM::getModuleName(void){
    return "LSM_EEPROM";
}
//END of LSMakerModule interface Implementation

//Public synchronous write method.
void EEPROM::write(uint8_t device, uint16_t addr, uint16_t size, void *data){

    if(device == INTERNAL){
        this->writeInternal(addr,size,data);
    }else if(device == EXTERNAL){
        this->writeExternal(addr,size,data);
    }

}

//Public synchronous read method.
void EEPROM::read(uint8_t device, uint16_t addr,uint16_t size, void *data){
    
    if(device == INTERNAL){
        this->readInternal(addr,size,data);
    }else if(device == EXTERNAL){
        this->readExternal(addr,size,data);
    }

}

//Private synchronous internal EEPROM write method.
void EEPROM::writeInternal(uint16_t addr, uint16_t size, void *data){

    //Re-declare void * as pointer to byte array.    
    uint8_t *pData = (uint8_t *) data;

    //Wait until the EEPROM is ready.
    eeprom_busy_wait();

    for(uint16_t i = 0 ; i < size ; i++){
        //Write the current byte to EEPROM
        eeprom_write_byte((uint8_t*) addr,*(pData + i));
        addr++;
    }

}

//Private synchronous external EEPROM write method.
void EEPROM::writeExternal(uint16_t addr, uint16_t size, void * data){

}

//Private synchronous internal EEPROM read method.
void EEPROM::readInternal(uint16_t addr, uint16_t size, void *data){

    //Re-declare void * as pointer to byte array.
    uint8_t *pData = (uint8_t *) data;

    //Wait until the EEPROM is ready
    eeprom_busy_wait();

    for(uint16_t i = 0 ; i < size ; i++){
        pData[i] = eeprom_read_byte((uint8_t *)addr);
        addr++;
    }

}

//Private synchronous external EEPROM read method.
void EEPROM::readExternal(uint16_t addr, uint16_t size, void *data){

}
