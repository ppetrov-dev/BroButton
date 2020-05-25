#ifndef BroButtonSingleClickStateH
#define BroButtonSingleClickStateH

#include <State/BroButtonStateBase.h>

class BroButtonSingleClickState : public BroButtonStateBase
{
public:
    void Tick(const bool &isButtonPressed, const unsigned long &milliseconds) override;
};

#endif //BroButtonSingleClickStateH