/**
 * CAPTION: Week_1 State Machine  <ö.varol> gith: <omrvrl>
 * DESC:
 * 
 * 
 * STATE:
 *      - Material_Control
 *      - Start_Production
 *      - Processing
 *      - Product_Ouput
 * EVENT:
 *      - Defect is detected
 *      - No defect is detected
 * TRANSITIONS:
 *      - Material_Control -> Start_Production
 *      - Start_Production -> Processing
 *      - Start_Production -> Material_Control
 *      - Processing -> Product_Ouput
 *      - Processing -> Material_Control
 * 
 *  
 */

#include <stdio.h>
#include <stdbool.h>


typedef enum{
    Material_Control,
    Start_Production,
    Processing,
    Product_Ouput
}ProductionState;


typedef enum {
    NonCompliant,
    Compliant
}MaterialState;


bool ControlMaterial(MaterialState *material){
    return *material;
}


void UpdateProductionState(ProductionState *phase){
    switch (*phase)
    {
        case Material_Control:
            printf("Material is controlling...\n");  
        break;
        case Start_Production:
            printf("Starting Production\n"); 
        break;
        case Processing:
            printf("Processing...\n");
        break;
        case Product_Ouput:
            printf("Product output\n");
            *phase = Material_Control;
        break;
        default:
            printf("Fault is detected\n");
        break;
    }
}

int main(void){

    ProductionState currentstate = Material_Control;
    
    while (1)
    {
        MaterialState Material = Compliant;

    
        if(ControlMaterial(&Material)){
            UpdateProductionState(&currentstate);
            currentstate++;
            printf("success\n");
        };
        
    };

    return 0;
}




