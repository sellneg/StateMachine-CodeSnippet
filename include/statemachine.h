#ifndef STATE_MACHINE_H_INCLUDED
#define STATE_MACHINE_H_INCLUDED

typedef enum {
    ST_IDLE,
    ST_RUNNING,
    ST_MOLD_CLOSED,
    ST_INCOMPLETE,
    ST_MOLD_OPEN,
    ST_COMPLETE,
    ST_INPUT_ERROR,
} state_t;

typedef struct {
    state_t currState;
} stateMachine_t;

typedef enum {
    EV_ANY,
    EV_NONE,
    EV_FALLING_EDGE,
    EV_RISING_EDGE,
    EV_TIME_OUT,
    EV_DEFAULT,
} event_t;

void StateMachine_Init(stateMachine_t * stateMachine);
void StateMachine_RunIteration(stateMachine_t *stateMachine, event_t event);
const char * StateMachine_GetStateName(state_t state);

extern void cycle_idle();
extern void cycle_running();
extern void cycle_mold_closed();
extern void cycle_incomplete();
extern void cycle_mold_open();
extern void cycle_complete();
extern void cycle_input_error();

#endif // #ifndef STATE_MACHINE_H_INCLUDED