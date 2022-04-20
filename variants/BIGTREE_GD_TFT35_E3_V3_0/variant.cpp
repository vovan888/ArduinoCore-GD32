/*
    Copyright (c) 2020, GigaDevice Semiconductor Inc.

    Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors
       may be used to endorse or promote products derived from this software without
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
OF SUCH DAMAGE.
*/

#include "pins_arduino.h"

#ifdef __cplusplus
extern "C" {
#endif

/* digital pins for pinmap list */
const PinName digital_pins[] = {
        PORTC_7,        //D0
        PORTC_6,        //D1
        PORTB_13,    //D2
        PORTB_14,    //D3
        PORTB_15,    //D4
        PORTB_12,    //D5
        PORTD_13,    //D6
        PORTC_8,        //D7
        PORTC_4,        //D8/A6
        PORTC_9,        //D9
        PORTA_7,        //D10/A5
        PORTA_8,        //D11
        PORTA_4,        //D12/A2
        PORTA_6,        //D13/A4
        PORTA_5,        //D14/A3
        PORTA_9,        //D15
        PORTD_3,        //D16
        PORTD_2,        //D17
        PORTA_10,    //D18
        PORTA_2,        //D19/A0
        PORTA_3,        //D20/A1
        PORTC_12,    //D21
        PORTC_11,    //D22
        PORTC_10,    //D23
        PORTA_15,    //D24
        PORTB_11,    //D25
        PORTB_10,    //D26
        PORTD_12,    //D27
        PORTD_7,        //D28
        PORTE_2,        //D29
        PORTD_4,        //D30
        PORTD_5,        //D31
        PORTB_1,        //D32
        PORTC_13,    //D33
        PORTE_3,        //D34
        PORTE_4,        //D35
        PORTE_5,        //D36
        PORTE_6,        //D37
        PORTB_3,        //D38
        PORTB_4,        //D39
        PORTB_5,        //D40
        PORTB_6        //D41
};

/* analog pins for pinmap list */
const uint32_t analog_pins[] = {
        19,    //A0
        20,    //A1
};
#ifdef __cplusplus
}
#endif
