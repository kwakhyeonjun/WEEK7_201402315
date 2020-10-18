/*
 * 기존의 코드에서 10보다 작은 경우 false를 return하여 조건문으로 코드를 진행시키나
 * funcA()를 싱행하며 발생하는 Exception에 대하여 예외를 발생시킬 수 있도록 진행하였다.
 * out_of_range로 오류를 명시하였으며, "Invalid input!!\n"을 예외 인자로 받을 수 있게 만들었다.
 */
#include <iostream>
void funcA() { //bool type으로 return할 이유가 없으므로 void로 대체
	int c;
	std::cout << "input(number) : ";
	std::cin >> c; // 입력받은 수를 저장
	if (c < 10) //Let's assume this is exception
		throw std::out_of_range("Invalid Input!!\n"); // 10보다 작은 경우 예외 발생
}
int main() {
	try {
		funcA(); // funcA 실행 중 예외 발생시 catch로 이동함
	}
	catch (std::exception& e) { // 예외가 발생한 경우 예외 인자 e를 받으며, catch를 실행
		std::cout << "Exception : "<< e.what(); // 예외인자를 출력함
	}
	return 0;
}