#ifndef BroButtonLongPressStoppedStateH
#define BroButtonLongPressStoppedStateH

#include <State/BroButtonStateBase.h>

class BroButtonLongPressStoppedState : public BroButtonStateBase
{
public:
    void RaiseEventIfNeeded() override;
};

#endif //BroButtonLongPressStoppedStateH