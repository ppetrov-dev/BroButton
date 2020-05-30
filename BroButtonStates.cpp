#include "BroButtonStates.h"

void BroButtonUnreleasedState::Tick(const bool &isButtonPressed, const unsigned long &milliseconds)
{
    if (!isButtonPressed)
    {
        SetStopTime(milliseconds);
        SetStartTime(milliseconds);
        TransitionTo(new BroButtonNormalState());
    }
}
void BroButtonNormalState::Tick(const bool &isButtonPressed, const unsigned long &milliseconds)
{
    if (isButtonPressed)
    {
        SetStopTime(milliseconds);
        SetStartTime(milliseconds);
        TransitionTo(new BroButtonSingleClickCandidateState());
    }
}
void BroButtonSingleClickCandidateState::Tick(const bool &isButtonPressed, const unsigned long &milliseconds)
{
    if (!isButtonPressed)
    {
        if (IsDebounceExpiredWithStartTime(milliseconds))
        {
            SetStopTime(milliseconds);
            TransitionTo(new BroButtonSingleClickState());
        }
        else
            TransitionTo(new BroButtonNormalState());
    }
    else if (IsPressTicksExpired(milliseconds))
        TransitionTo(new BroButtonLongPressCandidateState());
}
void BroButtonSingleClickState::Tick(const bool &isButtonPressed, const unsigned long &milliseconds)
{
    if (!ContainsDoubleClickHandler() || IsClickTicksExpired(milliseconds))
        TransitionTo(new BroButtonSingleClickedState());
    else if (isButtonPressed && IsDebounceExpiredWithStopTime(milliseconds))
    {
        SetStartTime(milliseconds);
        TransitionTo(new BroButtonDoubleClickCandidateState());
    }
}
void BroButtonSingleClickedState::RaiseEventIfNeeded()
{
    RaiseClickIfNotNull();
    TransitionTo(new BroButtonNormalState());
}
void BroButtonDoubleClickCandidateState::Tick(const bool &isButtonPressed, const unsigned long &milliseconds)
{
    if (IsDebounceExpiredWithStartTime(milliseconds))
    {
        SetStartTime(milliseconds);
        SetStopTime(milliseconds);
        TransitionTo(new BroButtonDoubleClickingState());
    }
}
void BroButtonDoubleClickingState::RaiseEventIfNeeded()
{
    RaiseDoubleClickIfNotNull();
    TransitionTo(new BroButtonDoubleClickedState());
}
void BroButtonDoubleClickedState::Tick(const bool &isButtonPressed, const unsigned long &milliseconds)
{
    if (isButtonPressed)
        TransitionTo(new BroButtonUnreleasedState());
    else if (!isButtonPressed)
        TransitionTo(new BroButtonNormalState());
}
void BroButtonLongPressCandidateState::RaiseEventIfNeeded()
{
    RaiseLongPressStartIfNotNull();
    TransitionTo(new BroButtonLongPressStartedState());
}
void BroButtonLongPressStartedState::Tick(const bool &isButtonPressed, const unsigned long &milliseconds)
{
    if (!isButtonPressed)
    {
        SetStopTime(milliseconds);
        TransitionTo(new BroButtonLongPressStoppedState());
    }
}
void BroButtonLongPressStoppedState::RaiseEventIfNeeded()
{
    RaiseLongPressStopIfNotNull();
    TransitionTo(new BroButtonNormalState());
}