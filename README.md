# LSM_EEPROM
This module defines a standard API to access the EEPROM memories on the LSMaker board.

## EEPROM memories available

| EEPROM Memory         |      Capacity      |
|-----------------------|:------------------:|
| Arduino Mega EEPROM   |      4 KBytes      |
| Microchip 25AA02E48   |      2 Kbits       |

# Download
[LSM_EEPROM.zip](https://github.com/lsmaker/LSM_EEPROM/releases/download/1.0/LSM_EEPROM.zip)

# Clone
**Using SSH**
```
git clone --recursive git@github.com:lsmaker/LSM_EEPROM.git LSM_EEPROM
```
**Using HTTPS**
```
git clone --recursive https://github.com/lsmaker/LSM_EEPROM.git LSM_EEPROM
```

# Example
```
#include <LSMaker.h>
#include <LSM_EEPROM.h>


LSM_EEPROM *eeprom = new LSM_EEPROM();

void setup(){
  LSMaker::init();
  LSMaker::addModule(eeprom);
}

void loop(){

}
```

## Author
[Albert Lloveras](https://github.com/alloveras)

## License
The MIT License (MIT)
Copyright &copy; 2016 La Salle, Universitat Ramón Llull

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
