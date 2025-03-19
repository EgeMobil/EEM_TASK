#ifndef __CLIMATE_PUBLIC_H
#define __CLIMATE_PUBLIC_H

#include "Climate_Definitions.h"

Climate_Obj* Climate_GetObj(void);                  // Returns Climate Object Pointer
void Climate_PublicInit(void);                      // Initialize Climate Object
void Climate_Update(void);                          // Self Update of Climate Object 
void Climate_UserSetTargetTemp(float* targetTemp);  // Set Target Temperature

#endif