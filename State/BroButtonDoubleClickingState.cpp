#include "State/BroButtonDoubleClickingState.h"
#include "State/BroButtonDoubleClickedState.h"

void BroButtonDoubleClickingState::RaiseEventIfNeeded()
{
    RaiseDoubleClickIfNotNull();
    TransitionTo(new BroButtonDoubleClickedState());
}
