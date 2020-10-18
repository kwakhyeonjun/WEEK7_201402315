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
 * ( 공통사항 )
 * try문에서 실행하는 funcA()에서 예외가 발생하는 경우 
 * try의 진행상황에서 벗어나 catch로 이동
 */
/* (실습 1-1) 분석결과 : 
 * 1. line27 - main함수의 funcA()로 함수 호출
 * 2. line20 - test r('A');로 클래스 생성
 * 3. line21 - funcB()로 함수 호출
 * 4. line14 - test r('B')로 클래스 생성
 * 5. line16 - Execute in B 출력
 * 6. line17 - 함수 호출 종료 후 영역을 벗어나며 객체가 제거되므로 B의 소멸자 호출 / Destructor execution : B 출력
 * 7. line22 - Execute in A 출력
 * 8. line23 - 함수 호출 종료 후 영역을 벗어나며 객체가 제거되므로 A의 소멸자 호출 / Destructor execution : A 출력
 * 
 * 결과적으로 
 * Executed in B
 * Destructor execution: B
 * Executed in A
 * Destructor execution: A
 * 으로 출력됨.
 */
/* (실습 1-2) 분석결과 :  * 1. line27 - main 함수의 funcA()로 함수 호출 * 2. line20 - test r('A')로 클래스 생성 * 3. line21 - funcB()로 함수 호출 * 4. line14 - test r('B')로 클래스 생성 * 5. line15 - 오류 발생으로 예외문(catch)로 이동 및 객체 제거      - 나중에 만들어진(stack에 늦게 생성된) 순으로 클래스 소멸자 호출 / Destructor execution : B, Destructor execution : A 출력 * 6. 마지막으로 Exception : Exception from funcB! 출력 */