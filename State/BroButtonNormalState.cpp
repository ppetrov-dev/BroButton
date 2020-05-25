#include "State/BroButtonNormalState.h"
#include "State/BroButtonSingleClickCandidateState.h"

void BroButtonNormalState::Tick(const bool &isButtonPressed, const unsigned long &milliseconds)
{
    if ( isButtonPressed)
    {
        SetStopTime(milliseconds);
        SetStartTime(milliseconds);
        TransitionTo(new BroButtonSingleClickCandidateState());
    }
}
