#ifndef BroButtonNormalStateH
#define BroButtonNormalStateH

#include <State/BroButtonStateBase.h>

class BroButtonNormalState : public BroButtonStateBase
{
public:
    void Tick(const bool &isButtonPressed, const unsigned long &milliseconds) override;
};

#endif //BroButtonNormalStateH