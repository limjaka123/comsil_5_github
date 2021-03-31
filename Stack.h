#include "LinkedList.h"
#include <string>

//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template <typename T>
class Stack : public LinkedList<T>{
	public:
		bool Delete (T &element){
			//first가 0이면 false반환
			if(this->first==0)
			{
				return false;
			}
			else
			{
			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
				Node<T>* current=this->first;//template T로 Node 클래스인 current를 형성하고 first와 같게 한다.
				element=current->data;//삭제하기 전 element에 data를 저장한다.
				this->first=this->first->link;//첫번째 노드가 삭제되면 새로운 첫번째 노드가 될 두번째 노드로 first를 변경한다. 
				delete current;//first를 삭제한다.
				this->current_size--;//size를 감소시킨다.
			}


			return true;
			}
};
