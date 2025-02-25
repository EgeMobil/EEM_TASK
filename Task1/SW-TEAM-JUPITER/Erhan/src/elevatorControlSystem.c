#include  "elevatorControlSystem.h"


static en_state_machine_step state_machine_step;

static int floor_selection = 0;
static int Before_floor_selection = -1;

void elevatorControlSystem_init(void)
{
    state_machine_step = SM_ELEVATOR_WAIT;
}

void elevatorControlSystem(void)
{
    switch (state_machine_step)
    {
        case SM_ELEVATOR_WAIT:
            printf("asansör beklemede kullanmak için lütfen enter tuşuna basiniz.\n");
            getchar();
            while (getchar() != '\n');
            state_machine_step = SM_ELEVATOR_ENTERING_DOOR_OPENING;
        break;

        case SM_ELEVATOR_ENTERING_DOOR_OPENING:
            printf("kapi aciliyor ve yolcular biniyor\n");
            state_machine_step = SM_ELEVATOR_FLOOR_SELECTION;
        break;

        case SM_ELEVATOR_FLOOR_SELECTION:
            printf("kat seçimi yapabilirsiniz\n");
            scanf("%d",&floor_selection);
            if(floor_selection == Before_floor_selection)
            {
                printf("zaten o kattasınız\n");
                state_machine_step = SM_ELEVATOR_FLOOR_SELECTION;
                break;
            }
            Before_floor_selection = floor_selection;
            state_machine_step = SM_ELEVATOR_MOVEMENT;
        break;

        case SM_ELEVATOR_MOVEMENT:
            printf("asansor hareket ediyor\n");
            state_machine_step = SM_ELEVATOR_EXITING_DOOR_OPENING;
        break;

        case SM_ELEVATOR_EXITING_DOOR_OPENING:
            printf("asansör %d'ye ulaştı kapi aciliyor ve yolcular iniyor\n", floor_selection);
            state_machine_step = SM_ELEVATOR_WAIT;
        break;
    
        default:
            printf("beklenmedik bir hata gerçekleşti\n");
        break;
    }
}

