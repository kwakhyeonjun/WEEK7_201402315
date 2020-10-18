/*
 * ������ �ڵ忡�� 10���� ���� ��� false�� return�Ͽ� ���ǹ����� �ڵ带 �����Ű��
 * funcA()�� �����ϸ� �߻��ϴ� Exception�� ���Ͽ� ���ܸ� �߻���ų �� �ֵ��� �����Ͽ���.
 * out_of_range�� ������ ����Ͽ�����, "Invalid input!!\n"�� ���� ���ڷ� ���� �� �ְ� �������.
 */
#include <iostream>
void funcA() { //bool type���� return�� ������ �����Ƿ� void�� ��ü
	int c;
	std::cout << "input(number) : ";
	std::cin >> c; // �Է¹��� ���� ����
	if (c < 10) //Let's assume this is exception
		throw std::out_of_range("Invalid Input!!\n"); // 10���� ���� ��� ���� �߻�
}
int main() {
	try {
		funcA(); // funcA ���� �� ���� �߻��� catch�� �̵���
	}
	catch (std::exception& e) { // ���ܰ� �߻��� ��� ���� ���� e�� ������, catch�� ����
		std::cout << "Exception : "<< e.what(); // �������ڸ� �����
	}
	return 0;
}