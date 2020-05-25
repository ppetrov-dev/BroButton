#ifndef BroButtonUnreleasedStateH
#define BroButtonUnreleasedStateH

#include <State/BroButtonStateBase.h>

class BroButtonUnreleasedState : public BroButtonStateBase
{
public:
    void Tick(const bool &isButtonPressed, const unsigned long &milliseconds) override;
};

#endif //BroButtonUnreleasedStateH