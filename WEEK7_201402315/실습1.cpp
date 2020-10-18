#include <iostream>
#include <stdexcept>
class Test {
public:
	Test(char id) : id_(id) {}
	~Test() {
		std::cout << "Destructor execution: "
			<< id_ << std::endl;
	}
private:
	char id_;
};
int funcB() {
	Test r('B');
	throw std::runtime_error("Exception from funcB!\n");
	std::cout << "Executed in B" << std::endl;
	return 0;
}
int funcA() {
	Test r('A');
	funcB();
	std::cout << "Executed in A" << std::endl;
	return 0;
}
int main() {
	try {
		funcA();
	}
	catch (std::exception& e) {
		std::cout << "Exception : " << e.what();
	}
}
/*
 * ( ������� )
 * try������ �����ϴ� funcA()���� ���ܰ� �߻��ϴ� ��� 
 * try�� �����Ȳ���� ��� catch�� �̵�
 */
/* (�ǽ� 1-1) �м���� : 
 * 1. line27 - main�Լ��� funcA()�� �Լ� ȣ��
 * 2. line20 - test r('A');�� Ŭ���� ����
 * 3. line21 - funcB()�� �Լ� ȣ��
 * 4. line14 - test r('B')�� Ŭ���� ����
 * 5. line16 - Execute in B ���
 * 6. line17 - �Լ� ȣ�� ���� �� ������ ����� ��ü�� ���ŵǹǷ� B�� �Ҹ��� ȣ�� / Destructor execution : B ���
 * 7. line22 - Execute in A ���
 * 8. line23 - �Լ� ȣ�� ���� �� ������ ����� ��ü�� ���ŵǹǷ� A�� �Ҹ��� ȣ�� / Destructor execution : A ���
 * 
 * ��������� 
 * Executed in B
 * Destructor execution: B
 * Executed in A
 * Destructor execution: A
 * ���� ��µ�.
 */
/* (�ǽ� 1-2) �м���� :  * 1. line27 - main �Լ��� funcA()�� �Լ� ȣ�� * 2. line20 - test r('A')�� Ŭ���� ���� * 3. line21 - funcB()�� �Լ� ȣ�� * 4. line14 - test r('B')�� Ŭ���� ���� * 5. line15 - ���� �߻����� ���ܹ�(catch)�� �̵� �� ��ü ����      - ���߿� �������(stack�� �ʰ� ������) ������ Ŭ���� �Ҹ��� ȣ�� / Destructor execution : B, Destructor execution : A ��� * 6. ���������� Exception : Exception from funcB! ��� */