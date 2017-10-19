/* Cinder OS
# ========================================
# [] File Name : system.h
#
# [] Creation Date : December 2016
#
# [] Created By : Ali Gholami (aligholami7596@gmail.com)
# ========================================
*/

#ifndef SYSTEM_H
#define SYSTEM_H
#include "types.h"

uint8 inportb(uint16 _port);
void outportb(uint16 _port, uint8 _data);

#endif
