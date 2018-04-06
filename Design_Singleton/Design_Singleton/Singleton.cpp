#include <iostream>
using namespace std;

// static 키워드를 사용하여 정체가 있는 정적 형태로 바꿔줌
class SingleObject {
	// 정적 멤버 : 클래스가 생성되기 전에 접근 가능한 영역이다. 모든 객체들이 공유할 수 있는 영역
	static SingleObject* m_pInstance;
	SingleObject() {}
public:
	// 정적멤버함수에서 변수를 하용하기 위해선 실체가 없는 일반 멤버변수는 사용할 수 없다.
	// 고로 클래스가 생성되기 전부터 존재하는 정적멤버변수를 가져와서 사용해야한다.
	static SingleObject* getInstance() {
		if (m_pInstance != NULL)
		{
			m_pInstance = new SingleObject();
			return m_pInstance;
		}
	}

	void ShowMessage()
	{
		cout << "SingleObject" << endl;
	}

	void Release()
	{
		delete m_pInstance;
	}
};

// 클래스에서 선언은 했지만 실체가 없으므로, C++에서는 이 메모리를 사용하기 위해
// 전역변수처럼 선언을 해야한다.
SingleObject* SingleObject::m_pInstance=NULL;

int main()
{
	SingleObject* pA=SingleObject::getInstance();
	pA->ShowMessage();
	pA->Release();
}