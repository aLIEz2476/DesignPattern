#include <iostream>
using namespace std;

class State;
class Context;
class StateOne;
class StateTwo;
class StateThree;

class State {
public:
	virtual void GoNext(Context* context) = 0;

};



class Context {
	State* m_pState;
public:
	void SetState(State* pState)
	{
		m_pState = pState;
	}

	void GoNext()
	{
		m_pState->GoNext(this);
	}
};

void StateOne::GoNext(Context *context)
{
	context->SetState(new StateTwo());
}

void StateTwo::GoNext(Context *context)
{
	context->SetState(new StateThree());
}

void StateThree::GoNext(Context *context)
{
	context->SetState(new StateOne());
}


class StateOne :public State {
public:
	void GoNext(Context* context);
};

class StateTwo :public State {
public:
	void GoNext(Context* context);
};

class StateThree :public State {
public:
	void GoNext(Context* context);
};


int main()
{
	Context cContext();
}