#include "State/BroButtonDoubleClickedState.h"
#include "State/BroButtonNormalState.h"
#include "State/BroButtonUnreleasedState.h"

void BroButtonDoubleClickedState::Tick(const bool &isButtonPressed, const unsigned long &milliseconds)
{
    if (isButtonPressed)
        TransitionTo(new BroButtonUnreleasedState());
    else if (!isButtonPressed)
        TransitionTo(new BroButtonNormalState());
}
