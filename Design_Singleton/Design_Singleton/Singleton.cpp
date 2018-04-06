#include <iostream>
using namespace std;

// static Ű���带 ����Ͽ� ��ü�� �ִ� ���� ���·� �ٲ���
class SingleObject {
	// ���� ��� : Ŭ������ �����Ǳ� ���� ���� ������ �����̴�. ��� ��ü���� ������ �� �ִ� ����
	static SingleObject* m_pInstance;
	SingleObject() {}
public:
	// ��������Լ����� ������ �Ͽ��ϱ� ���ؼ� ��ü�� ���� �Ϲ� ��������� ����� �� ����.
	// ��� Ŭ������ �����Ǳ� ������ �����ϴ� ������������� �����ͼ� ����ؾ��Ѵ�.
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

// Ŭ�������� ������ ������ ��ü�� �����Ƿ�, C++������ �� �޸𸮸� ����ϱ� ����
// ��������ó�� ������ �ؾ��Ѵ�.
SingleObject* SingleObject::m_pInstance=NULL;

int main()
{
	SingleObject* pA=SingleObject::getInstance();
	pA->ShowMessage();
	pA->Release();
}