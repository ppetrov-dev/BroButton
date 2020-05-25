#include "State/BroButtonUnreleasedState.h"
#include "State/BroButtonNormalState.h"

void BroButtonUnreleasedState::Tick(const bool &isButtonPressed, const unsigned long &milliseconds)
{
    if (! isButtonPressed)
    {
        SetStopTime(milliseconds);
        SetStartTime(milliseconds);
        TransitionTo(new BroButtonNormalState());
    }
}
