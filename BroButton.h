#ifndef broRotaryEncoderH
#define broRotaryEncoderH

#include "Arduino.h"
#include "State/BroButtonStateBase.h"

class BroButton
{
	friend class BroButtonStateBase;

private:
	unsigned long _clickTicks = 500;   // number of ticks that have to pass by
									   // before a click is detected.
	unsigned long _pressTicks = 1000;  // number of ticks that have to pass by
									   // before a long button press is detected
	unsigned long _debounceTicks = 50; // number of ticks for debounce times.

	byte _pin;
	int _buttonPressedValue;
	bool _isPullupActive = true;

	unsigned long _startTime;
	unsigned long _stopTime;

	BroButtonStateBase *_state;
	void (*_onRightHoldTurnCallbackFunc)() = nullptr;
	void (*_onLeftHoldTurnCallbackFunc)() = nullptr;
	void (*_onClickCallbackFunc)() = nullptr;
	void (*_onDoubleClickCallbackFunc)() = nullptr;
	void (*_onLongPressStartCallbackFunc)() = nullptr;
	void (*_onLongPressStopCallbackFunc)() = nullptr;
	void TransitionTo(BroButtonStateBase *state);
	void DisposeStateIfNotNull();

public:
	BroButton(byte pin, bool isActiveLow, bool isPullupActive);
	BroButton(byte pin);
	~BroButton();
	void Tick(void);
	void Init();
	void Reset();
	
	void AttachOnClick(void (*newFunction)());
	void AttachOnDoubleClick(void (*newFunction)());
	void AttachOnLongPressStart(void (*newFunction)());
	void AttachOnLongPressStop(void (*newFunction)());
	void AttachOnRightHoldTurn(void (*newFunction)());
	void AttachOnLeftHoldTurn(void (*newFunction)());

	void SetDebounceTicks(unsigned long milliseconds);
	void SetClickTicks(unsigned long milliseconds);
	void SetPressTicks(unsigned long milliseconds);

	int GetLastPressedTicks();
};
#endif //broRotaryEncoderH