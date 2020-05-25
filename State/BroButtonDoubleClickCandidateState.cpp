#include "State/BroButtonDoubleClickCandidateState.h"
#include "State/BroButtonDoubleClickingState.h"

void BroButtonDoubleClickCandidateState::Tick(const bool &isButtonPressed, const unsigned long &milliseconds)
{
    if (IsDebounceExpiredWithStartTime(milliseconds))
    {
        SetStartTime(milliseconds);
        SetStopTime(milliseconds);
        TransitionTo(new BroButtonDoubleClickingState());
    }
}
