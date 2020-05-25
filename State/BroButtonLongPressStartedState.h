#ifndef BroButtonLongPressStartedStateH
#define BroButtonLongPressStartedStateH

#include <State/BroButtonStateBase.h>

class BroButtonLongPressStartedState : public BroButtonStateBase
{
public:
    void Tick(const bool &isButtonPressed, const unsigned long &milliseconds) override;
};

#endif //BroButtonLongPressStartedStateH