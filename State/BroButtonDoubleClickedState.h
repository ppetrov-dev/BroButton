#ifndef BroButtonDoubleClickedStateH
#define BroButtonDoubleClickedStateH

#include <State/BroButtonStateBase.h>

class BroButtonDoubleClickedState : public BroButtonStateBase
{
public:
    void Tick(const bool &isButtonPressed, const unsigned long &milliseconds) override;
};

#endif //BroButtonDoubleClickedStateH