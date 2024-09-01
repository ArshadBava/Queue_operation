#include<iostream>
#define MAXSIZE 200
using namespace std;

class Queue{
	private:
		int queue[MAXSIZE];
	    int front;
		int rear;
		
	public:
		Queue(){
			front=0;
			rear=0;
		}
		
		void insert();
		void del();
		void display();
		void tople();
		int size();
		bool isEmpty();
		void clear();
		
		
};
//enqueue()
void Queue::insert(){  
    int value;
	if(rear==MAXSIZE){
		cout<<"Queue is full"<<endl;
		
	}else{
		cout << "Enter the value to insert: ";
        cin>>value;
		rear++;
		queue[rear]=value;
		cout<<value<<" is added"<<endl;
	}
}

void Queue::del(){     //dequeue
  	if(front==rear){
		cout<<"Queue is empty"<<endl;
		
	}else{
		front++;
		cout <<"Element deleted by deleted function is"<<queue[front]<<endl;
	}
}

void Queue::display(){
	if(rear==front){
		cout<<"Queue id empty"<<endl;
		
	}else{
		cout<<"The queue elemtnts are: ";
		for(int i=front+1;i<=rear;i++){
			cout<<queue[i]<<" ";
		}
		cout<<endl;
	}
}
void Queue::tople(){
	if(rear==front){
		cout<<"Queue id empty"<<endl;
		
	}
	else {
        cout << "TOP ELEMENT OF THE QUEUE: " << queue[rear] << endl;
    }
		
}
int Queue::size() {
    return rear-front;
}

bool Queue::isEmpty() {
    return front == rear;
}
void Queue::clear() {
    front = 0;
    rear = 0;
    cout << "QUEUE IS CLEARED" << endl;
}
int main(){
	Queue q;
	int ch,value;
	do {
        cout << "\nQUEUE OPERATIONS";
        cout << "\n1. INSERT ITEM";
        cout << "\n2. DELETE ITEM";
        cout << "\n3. DISPLAY ITEM";
        cout << "\n4. TOP ELEMENT OF QUEUE";
        cout << "\n5. SIZE OF QUEUE";
        cout << "\n6. CHECK QUEUE IS EMPTY OR NOT";
        cout << "\n7. CLEAR QUEUE";
        cout << "\n8. EXIT";
        cout << "\nENTER YOUR CHOICE: ";
        cin >> ch;
        switch (ch) {
            case 1:q.insert();
                break;
            case 2:q.del();
                break;
            case 3:q.display();
                break;
            case 4:q.tople();
                break;
            case 5:cout << "TThe queue size : " << q.size() << endl;
                break;
            case 6:if (q.isEmpty()) {
                    cout << "Queue is empty" << endl;
                } else {
                    cout << "Queue is not empty" << endl;
                }
                break;
            case 7: q.clear();
                break;
            case 8:cout << "EXITING..." << endl;
                break;
            default:
                cout << "Enter a value between 1 and 8" << endl;
        }
        
	}while(ch!=8);
	return 0;
}


