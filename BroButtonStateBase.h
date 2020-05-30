#ifndef BroButtonStateBaseH
#define BroButtonStateBaseH

class BroButton;
class BroButtonStateBase
{
    private:
        BroButton *_context;
    protected:
        void SetStartTime(const unsigned long &milliseconds);
        void SetStopTime(const unsigned long &milliseconds);
        bool IsDebounceExpiredWithStartTime(const unsigned long &milliseconds);
        bool IsDebounceExpiredWithStopTime(const unsigned long &milliseconds);
        bool IsClickTicksExpired(const unsigned long &milliseconds);
        bool IsPressTicksExpired(const unsigned long &milliseconds);
        bool ContainsDoubleClickHandler();
        void RaiseLongPressStartIfNotNull();
        void RaiseLongPressStopIfNotNull();
        void RaiseClickIfNotNull();
        void RaiseDoubleClickIfNotNull();
        void TransitionTo(BroButtonStateBase *state);

    public:
        virtual void Tick(const bool &isButtonPressed, const unsigned long &milliseconds);
        void SetContext(BroButton *context);
};
#endif //BroButtonStateBaseH